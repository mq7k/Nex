#include "blackbird/proto/crsf.h"
#include "blackbird/bbconf.h"
#include "cpu/cortex/common/memory.h"
#include "cpu/cortex/common/string.h"
#include "cpu/cortex/common/sys.h"
#include "libcom/bytebuf.h"
#include "libcom/data/ring_buffer.h"
#include "libcom/errcodes.h"
#include "libcom/util.h"

constexpr u8 crc8tab[256] = {
  0x00, 0xd5, 0x7f, 0xaa, 0xfe, 0x2b, 0x81, 0x54, 0x29, 0xfc, 0x56, 0x83, 0xd7, 0x02, 0xa8, 0x7d,
  0x52, 0x87, 0x2d, 0xf8, 0xac, 0x79, 0xd3, 0x06, 0x7b, 0xae, 0x04, 0xd1, 0x85, 0x50, 0xfa, 0x2f,
  0xa4, 0x71, 0xdb, 0x0e, 0x5a, 0x8f, 0x25, 0xf0, 0x8d, 0x58, 0xf2, 0x27, 0x73, 0xa6, 0x0c, 0xd9,
  0xf6, 0x23, 0x89, 0x5c, 0x08, 0xdd, 0x77, 0xa2, 0xdf, 0x0a, 0xa0, 0x75, 0x21, 0xf4, 0x5e, 0x8b,
  0x9d, 0x48, 0xe2, 0x37, 0x63, 0xb6, 0x1c, 0xc9, 0xb4, 0x61, 0xcb, 0x1e, 0x4a, 0x9f, 0x35, 0xe0,
  0xcf, 0x1a, 0xb0, 0x65, 0x31, 0xe4, 0x4e, 0x9b, 0xe6, 0x33, 0x99, 0x4c, 0x18, 0xcd, 0x67, 0xb2,
  0x39, 0xec, 0x46, 0x93, 0xc7, 0x12, 0xb8, 0x6d, 0x10, 0xc5, 0x6f, 0xba, 0xee, 0x3b, 0x91, 0x44,
  0x6b, 0xbe, 0x14, 0xc1, 0x95, 0x40, 0xea, 0x3f, 0x42, 0x97, 0x3d, 0xe8, 0xbc, 0x69, 0xc3, 0x16,
  0xef, 0x3a, 0x90, 0x45, 0x11, 0xc4, 0x6e, 0xbb, 0xc6, 0x13, 0xb9, 0x6c, 0x38, 0xed, 0x47, 0x92,
  0xbd, 0x68, 0xc2, 0x17, 0x43, 0x96, 0x3c, 0xe9, 0x94, 0x41, 0xeb, 0x3e, 0x6a, 0xbf, 0x15, 0xc0,
  0x4b, 0x9e, 0x34, 0xe1, 0xb5, 0x60, 0xca, 0x1f, 0x62, 0xb7, 0x1d, 0xc8, 0x9c, 0x49, 0xe3, 0x36,
  0x19, 0xcc, 0x66, 0xb3, 0xe7, 0x32, 0x98, 0x4d, 0x30, 0xe5, 0x4f, 0x9a, 0xce, 0x1b, 0xb1, 0x64,
  0x72, 0xa7, 0x0d, 0xd8, 0x8c, 0x59, 0xf3, 0x26, 0x5b, 0x8e, 0x24, 0xf1, 0xa5, 0x70, 0xda, 0x0f,
  0x20, 0xf5, 0x5f, 0x8a, 0xde, 0x0b, 0xa1, 0x74, 0x09, 0xdc, 0x76, 0xa3, 0xf7, 0x22, 0x88, 0x5d,
  0xd6, 0x03, 0xa9, 0x7c, 0x28, 0xfd, 0x57, 0x82, 0xff, 0x2a, 0x80, 0x55, 0x01, 0xd4, 0x7e, 0xab,
  0x84, 0x51, 0xfb, 0x2e, 0x7a, 0xaf, 0x05, 0xd0, 0xad, 0x78, 0xd2, 0x07, 0x53, 0x86, 0x2c, 0xf9
};

// Functions declarations.
static i32
_encode_frame_gps(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_gps(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_gps(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_gps_time(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_gps_ext(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_variometer_sensor(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_battery_sensor(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_barometric_alt_vspeed(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_airspeed(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_heartbeat(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_decode_frame_heartbeat(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_temp(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_voltage_grp(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_vtx_telemetry(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_barometer(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_magnometer(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_accel_gyro(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_attitude(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_flight_mode(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_encode_frame_rpm(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_decode_frame_link_stats(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_decode_frame_link_stats_rx(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_decode_frame_link_stats_tx(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_decode_frame_rc_channels(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static i32
_decode_frame_param_dev_info(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

static u8
_compute_crc(
  u8* buf,
  u32 len
)
{
  u8 crc = 0;
  for (u32 i = 0; i < len; i++)
  {
    crc = crc8tab[crc ^ *buf++];
  }

  return crc;
}

static inline struct bb_crsf_port*
_get_port(
  struct bb_crsf_node* node,
  i32 idx
)
{
  return &node->ports[idx];
}

static inline enum bb_crsf_port_rx_state
_get_port_rx_state(
  struct bb_crsf_port* port
)
{
  return port->rx_state;
}

static inline enum bb_crsf_port_tx_state
_get_port_tx_state(
  struct bb_crsf_port* port
)
{
  return port->tx_state;
}

static void
_set_port_rx_state(
  struct bb_crsf_port* port,
  enum bb_crsf_port_rx_state state
)
{
  port->rx_state = state;
}

static u32
_is_valid_len(
  u8 len
)
{
  return len > 2 && len <= 62;
}

static u32
_is_valid_type(
  u8 type
)
{
  switch (type)
  {
    case BB_CRSF_FRAME_TYPE_GPS:
    case BB_CRSF_FRAME_TYPE_GPS_TIME:
    case BB_CRSF_FRAME_TYPE_GPS_EXTENDED:
    case BB_CRSF_FRAME_TYPE_VARIOMETER_SENSOR:
    case BB_CRSF_FRAME_TYPE_BATTERY_SENSOR:
    case BB_CRSF_FRAME_TYPE_BAROMETRIC_ALT_VSPEED:
    case BB_CRSF_FRAME_TYPE_AIRSPEED:
    case BB_CRSF_FRAME_TYPE_HEARTBEAT:
    case BB_CRSF_FRAME_TYPE_RPM:
    case BB_CRSF_FRAME_TYPE_TEMP:
    case BB_CRSF_FRAME_TYPE_VOLTAGE_GRP:
    case BB_CRSF_FRAME_TYPE_VTX_TELEMETRY:
    case BB_CRSF_FRAME_TYPE_BAROMETER:
    case BB_CRSF_FRAME_TYPE_MAGNOMETER:
    case BB_CRSF_FRAME_TYPE_ACCEL_GYRO:
    case BB_CRSF_FRAME_TYPE_LINK_STATS:
    case BB_CRSF_FRAME_TYPE_LINK_STATS_REPEATER:
    case BB_CRSF_FRAME_TYPE_RC_CHANNELS:
    case BB_CRSF_FRAME_TYPE_SUBSET_RC_CHANNELS:
    case BB_CRSF_FRAME_TYPE_RC_CHANNELS_PACKED_11BITS:
    case BB_CRSF_FRAME_TYPE_LINK_STATS_RX:
    case BB_CRSF_FRAME_TYPE_LINK_STATS_TX:
    case BB_CRSF_FRAME_TYPE_ATTITUDE:
    case BB_CRSF_FRAME_TYPE_MAVLINK_FC:
    case BB_CRSF_FRAME_TYPE_FLIGHT_MODE:
    case BB_CRSF_FRAME_TYPE_ESP_NOW:
    case BB_CRSF_FRAME_TYPE_PARAM_PING_DEV:
    case BB_CRSF_FRAME_TYPE_PARAM_DEV_INFO:
    case BB_CRSF_FRAME_TYPE_PARAM_SETTINGS:
      return 1;

    default:
      return 0;
  }
}

static u32
_is_bc_frame(
  u8 type
)
{
  return type <= 0x27;
}

static u32
_get_header_size(void)
{
  // Sync byte is written directly to USART.
  // 1 byte = Frame length
  // 1 byte = Type
  // 1 byte = CRC
  return 3;
}

static u32
_get_frame_size(
  struct bb_crsf_frame* frame
)
{
  switch (frame->type)
  {
    case BB_CRSF_FRAME_TYPE_GPS:
      return 15;

    case BB_CRSF_FRAME_TYPE_GPS_TIME:
      return 9;

    case BB_CRSF_FRAME_TYPE_GPS_EXTENDED:
      return 20;

    case BB_CRSF_FRAME_TYPE_VARIOMETER_SENSOR:
      return 2;

    case BB_CRSF_FRAME_TYPE_BATTERY_SENSOR:
      return 8;

    case BB_CRSF_FRAME_TYPE_BAROMETRIC_ALT_VSPEED:
      return 3;

    case BB_CRSF_FRAME_TYPE_AIRSPEED:
      return 2;

    case BB_CRSF_FRAME_TYPE_HEARTBEAT:
      return 2;

    case BB_CRSF_FRAME_TYPE_RPM:
      return 1 + 3 * frame->bc.rpm.count;

    case BB_CRSF_FRAME_TYPE_TEMP:
      return 1 + 2 * frame->bc.temp.count;

    case BB_CRSF_FRAME_TYPE_VOLTAGE_GRP:
      return 1 + 2 * frame->bc.voltages.count;

    case BB_CRSF_FRAME_TYPE_VTX_TELEMETRY:
      return 7;

    case BB_CRSF_FRAME_TYPE_BAROMETER:
      return 8;

    case BB_CRSF_FRAME_TYPE_MAGNOMETER:
      return 6;

    case BB_CRSF_FRAME_TYPE_ACCEL_GYRO:
      return 18;

    case BB_CRSF_FRAME_TYPE_LINK_STATS:
      return 10;

    case BB_CRSF_FRAME_TYPE_LINK_STATS_REPEATER:
      return 10;

    case BB_CRSF_FRAME_TYPE_RC_CHANNELS:
      return 0;

    case BB_CRSF_FRAME_TYPE_SUBSET_RC_CHANNELS:
      return 0;

    case BB_CRSF_FRAME_TYPE_RC_CHANNELS_PACKED_11BITS:
      return 0;

    case BB_CRSF_FRAME_TYPE_LINK_STATS_RX:
      return 5;

    case BB_CRSF_FRAME_TYPE_LINK_STATS_TX:
      return 6;

    case BB_CRSF_FRAME_TYPE_ATTITUDE:
      return 6;

    case BB_CRSF_FRAME_TYPE_MAVLINK_FC:
      return 9;

    case BB_CRSF_FRAME_TYPE_FLIGHT_MODE:
      // We have to include the null byte at the end.
      return (u32) strlen(frame->bc.flight_mode.flight_mode) + 1;

    case BB_CRSF_FRAME_TYPE_ESP_NOW:
      return 0;

    case BB_CRSF_FRAME_TYPE_PARAM_PING_DEV:
    case BB_CRSF_FRAME_TYPE_PARAM_DEV_INFO:
    case BB_CRSF_FRAME_TYPE_PARAM_SETTINGS:
    default:
      return 0;
  }
}

static i32
_encode_frame(
  u8 sync_byte,
  struct bb_crsf_frame* frame,
  u8* buf,
  u32 len
)
{
  struct nex_bytebuf bytebuf;
  nex_bytebuf_init(&bytebuf, buf, len);

  nex_bytebuf_write_u8(&bytebuf, sync_byte);
  nex_bytebuf_write_u8(&bytebuf, 0x00); // Placeholder for the frame len.
  nex_bytebuf_write_u8(&bytebuf, frame->type);
  i32 code;

  switch (frame->type)
  {
    case BB_CRSF_FRAME_TYPE_GPS:
      code = _encode_frame_gps(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_GPS_TIME:
      code = _encode_frame_gps_time(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_GPS_EXTENDED:
      code = _encode_frame_gps_ext(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_VARIOMETER_SENSOR:
      code = _encode_frame_variometer_sensor(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_BATTERY_SENSOR:
      code = _encode_frame_battery_sensor(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_BAROMETRIC_ALT_VSPEED:
      code = _encode_frame_barometric_alt_vspeed(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_AIRSPEED:
      code = _encode_frame_airspeed(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_HEARTBEAT:
      code = _encode_frame_heartbeat(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_RPM:
      code = _encode_frame_rpm(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_TEMP:
      code = _encode_frame_temp(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_VOLTAGE_GRP:
      code = _encode_frame_voltage_grp(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_VTX_TELEMETRY:
      code = _encode_frame_vtx_telemetry(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_BAROMETER:
      code = _encode_frame_barometer(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_MAGNOMETER:
      code = _encode_frame_magnometer(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_ACCEL_GYRO:
      code = _encode_frame_accel_gyro(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_ATTITUDE:
      code = _encode_frame_attitude(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_FLIGHT_MODE:
      code = _encode_frame_flight_mode(frame, &bytebuf);
      break;

    case BB_CRSF_FRAME_TYPE_LINK_STATS:
    case BB_CRSF_FRAME_TYPE_LINK_STATS_REPEATER:
    case BB_CRSF_FRAME_TYPE_RC_CHANNELS:
    case BB_CRSF_FRAME_TYPE_SUBSET_RC_CHANNELS:
    case BB_CRSF_FRAME_TYPE_RC_CHANNELS_PACKED_11BITS:
    case BB_CRSF_FRAME_TYPE_LINK_STATS_RX:
    case BB_CRSF_FRAME_TYPE_LINK_STATS_TX:
    case BB_CRSF_FRAME_TYPE_MAVLINK_FC:
    case BB_CRSF_FRAME_TYPE_ESP_NOW:

    case BB_CRSF_FRAME_TYPE_PARAM_PING_DEV:
    case BB_CRSF_FRAME_TYPE_PARAM_DEV_INFO:
    case BB_CRSF_FRAME_TYPE_PARAM_SETTINGS:
      return -NERR_NOTIMPL;

    default:
      return -NERR_INV_ARG;
  }

  if (code < 0)
  {
    return code;
  }

  u32 cur = nex_bytebuf_get_cur(&bytebuf);
  frame->crc = _compute_crc(&buf[2], cur - 2); // Skip frame len and sync byte.
  nex_bytebuf_write_u8(&bytebuf, frame->crc);

  cur = nex_bytebuf_get_cur(&bytebuf);
  nex_bytebuf_set_cur(&bytebuf, 1);
  nex_bytebuf_write_u8(&bytebuf, (u8) (cur - 2));
  nex_bytebuf_set_cur(&bytebuf, cur);

  return (i32) cur;
}

static i32
_forward_packet_to(
  struct bb_crsf_port* dst,
  struct bb_crsf_port* src
)
{
  u32 required_bytes = src->inpacket_len + 2;
  u32 bytes_left = nex_ring_buffer_space_left(&dst->rbbuf_out);
  if (bytes_left < required_bytes)
  {
    return -NERR_FULL;
  }

  nex_ring_buffer_write(&dst->rbbuf_out, src->inpacket_len);
  nex_ring_buffer_write(&dst->rbbuf_out, src->inpacket_type);
  nex_ring_buffer_write_bytes(&dst->rbbuf_out, src->inbuf, src->inpacket_len - 2);
  nex_ring_buffer_write(&dst->rbbuf_out, src->inpacket_crc);
  nex_ring_buffer_write(&dst->rbbuf_out, 0);

  return NOK;
}

static u32
_forward_frame(
  struct bb_crsf_node* node,
  struct bb_crsf_port* origin_port
)
{
  u32 success = 0;

  for (u32 i = 0; i < node->ports_count; ++i)
  {
    struct bb_crsf_port* dst_port = _get_port(node, (i32) i);
    if (dst_port == origin_port)
    {
      continue;
    }

    if (_forward_packet_to(dst_port, origin_port) == NOK)
    {
      ++success;
    }
  }

  return success;
}

static i32
_handle_ext_frame_ping_dev(
  struct bb_crsf_node* node,
  struct bb_crsf_port* port
)
{
  struct bb_crsf_frame frame;
  frame.type = BB_CRSF_FRAME_TYPE_PARAM_DEV_INFO;

  u32 len = ARR_SIZE(BB_DEVICE_NAME);
  if (len < 60)
  {
    u8* dst = frame.ext.param_dev_info.device_name;
    memcpy(dst, BB_DEVICE_NAME, sizeof(BB_DEVICE_NAME));
    dst[len] = 0;
  }
  else
  {
    u8* dst = frame.ext.param_dev_info.device_name;
    const char* name = "Generic";
    len = strlen(name);
    memcpy(dst, name, len);
    dst[len] = 0;
  }

  frame.ext.param_dev_info.serial_number = BB_SERIAL_NUMBER;
  frame.ext.param_dev_info.hardware_id = BB_HARDWARE_ID;
  frame.ext.param_dev_info.firmware_id = BB_FIRMWARE_ID;
  
  // TODO: Implement parameters counter.
  frame.ext.param_dev_info.parameters_total = 0;
  frame.ext.param_dev_info.parameter_version_number = 0x02;

  bb_crsf_port_enqueue_packet(node, port->idx, &frame);
  return NOK;
}

static i32
_handle_ext_frame(
  struct bb_crsf_node* node,
  struct bb_crsf_port* port,
  struct bb_crsf_frame* frame
)
{
  switch (frame->type)
  {
    case BB_CRSF_FRAME_TYPE_PARAM_PING_DEV:
      return _handle_ext_frame_ping_dev(node, port);

    case BB_CRSF_FRAME_TYPE_PARAM_DEV_INFO:
    case BB_CRSF_FRAME_TYPE_PARAM_SETTINGS:
      return -NERR_NOTIMPL;

    default:
      return -NERR_INV_ARG;
  }
}

static void
_set_port_tx_state(
  struct bb_crsf_port* port,
  enum bb_crsf_port_tx_state state
)
{
  port->tx_state = state;
}

static void
_reset_port_rx(
  struct bb_crsf_port* port
)
{
  // port->inbuf_wcur = 0;
  port->pktcur = 0;
  port->inpacket_crc = 0;
  port->inpacket_len = 0;

  for (u32 i = 0; i < 64; ++i)
  {
    port->pktbuf[i] = 0;
  }

  _set_port_rx_state(port, BB_CRSF_PORT_RX_STATE_WAIT_SYNC);
}

static i32
_find_byte(
  u8* buf,
  u8 byte,
  u32 max
)
{
  u32 cur = 0;
  while (max-- != 0)
  {
    if (buf[cur] == byte)
    {
      return (i32) cur;
    }

    ++cur;
  }

  return -NERR_NOT_FOUND;
}

static void
_tick_port_rx(
  struct bb_crsf_node* node,
  struct bb_crsf_port* port
)
{
  enum bb_crsf_port_rx_state state = _get_port_rx_state(port);

  // DMA cursor.
  u32 items_left = node->ops->get_items_left();
  u32 total_recv_bytes = BB_CRSF_PORT_INBUF_LEN - items_left;
  u32 items_avb;

  if (total_recv_bytes >= port->inbuf_rcur)
  {
    // DMA cursor after write cursor, no wrap.
    items_avb = total_recv_bytes - port->inbuf_rcur;
  }
  else
  {
    // DMA cursor before write cursor, wrap necessary.
    items_avb = BB_CRSF_PORT_INBUF_LEN - port->inbuf_rcur;
  }

  u8* src = &port->inbuf[port->inbuf_rcur];
  u8* dst = &port->pktbuf[port->pktcur];

  switch (state)
  {
    case BB_CRSF_PORT_RX_STATE_WAIT_SYNC:
      if (items_avb == 0)
      {
        // Nothing new to process.
        return;
      }

      const u32 max_depth = MIN(128, items_avb);
      i32 off = _find_byte(src, port->sync_byte, max_depth);
      if (off < 0)
      {
        // Failed to find sync byte, update cursor and exit.
        port->inbuf_rcur = FAST_MOD(
          port->inbuf_rcur + max_depth,
          BB_CRSF_PORT_INBUF_LEN
        );

        _reset_port_rx(port);
        return;
      }
      
      // Skip the sync byte.
      ++off;
      port->inbuf_rcur = FAST_MOD(
        port->inbuf_rcur + (u32) off,
        BB_CRSF_PORT_INBUF_LEN
      );

      src = &port->inbuf[port->inbuf_rcur];
      u8 frame_len = *src;

      if (!_is_valid_len(frame_len))
      {
        _reset_port_rx(port);
        return;
      }

      port->inpacket_len = frame_len;
      port->inpacket_bytes_left = frame_len;
      port->pktbuf[0] = frame_len;
      port->pktcur = 1;

      port->inbuf_rcur = FAST_MOD(
        port->inbuf_rcur + 1,
        BB_CRSF_PORT_INBUF_LEN
      );

      _set_port_rx_state(port, BB_CRSF_PORT_RX_STATE_WAIT_PAYLOAD);
      break;

    case BB_CRSF_PORT_RX_STATE_WAIT_PAYLOAD:
      if (items_avb == 0)
      {
        // Nothing new to process.
        return;
      }

      // We copy as many bytes as we can.
      const u8 count = (MIN(items_avb, port->inpacket_bytes_left)) & 0xff;
      memcpy(dst, src, count);

      port->inbuf_rcur = FAST_MOD(
        port->inbuf_rcur + count,
        BB_CRSF_PORT_INBUF_LEN
      );

      port->inpacket_bytes_left -= count;
      port->pktcur += count;

      // TODO: Implement a timeout.
      if (port->inpacket_bytes_left == 0)
      {
        _set_port_rx_state(port, BB_CRSF_PORT_RX_STATE_PARSE);
        break;
      }

      break;

    case BB_CRSF_PORT_RX_STATE_PARSE:
      struct bb_crsf_frame frame;
      i32 code = bb_crsf_read_packet(&frame, port->pktbuf, port->pktcur);
      if (code != NOK)
      {
        node->ops->on_parse_fail();
        _reset_port_rx(port);
        return;
      }

      if (_is_bc_frame(frame.type))
      {
        _forward_frame(node, port);
        node->ops->on_packet_ready(port, &frame);
      }
      else
      {
        _handle_ext_frame(node, port, &frame);
      }

      _reset_port_rx(port);
      return;
      break;

    default:
      break;
  }
}

static void
_tick_port_tx(
  struct bb_crsf_node* node,
  struct bb_crsf_port* port
)
{
  enum bb_crsf_port_tx_state state = _get_port_tx_state(port);
  switch (state)
  {
    case BB_CRSF_PORT_TX_STATE_READY:
      if (!nex_ring_buffer_is_empty(&port->rbbuf_out))
      {
        i32 code = nex_ring_buffer_head_peek(&port->rbbuf_out, &port->outpacket_len);
        if (code < 0)
        {
          break;
        }

        nex_ring_buffer_consume(&port->rbbuf_out, 1);
        code = nex_ring_buffer_copy(&port->rbbuf_out, port->seq_out_queue, port->outpacket_len);
        if (code < 0)
        {
          break;
        }

        node->ops->send(port->seq_out_queue, port->outpacket_len);
        _set_port_tx_state(port, BB_CRSF_PORT_TX_STATE_IN_PROGRESS);
      }
      break;

    case BB_CRSF_PORT_TX_STATE_IN_PROGRESS:
      // TODO: Implement a timeout.
      break;

    default:
      break;
  }
}

static void
_tick_port(
  struct bb_crsf_node* node,
  struct bb_crsf_port* port
)
{
  u32 it = 0;
  while (it++ < 3)
  {
    enum bb_crsf_port_rx_state state = _get_port_rx_state(port);
    _tick_port_rx(node, port);
    if (_get_port_rx_state(port) == state)
    {
      // No progress made.
      break;
    }
  }

  _tick_port_tx(node, port);
}

static u32
_validate_frame_len(
  u32 len
)
{
  return len >= 2 && len <= 62;
}

i32
bb_crsf_read_packet(
  struct bb_crsf_frame* frame,
  u8* buf,
  u32 buflen
)
{
  // buflen is the len of the raw buffer.
  // frame_len is the encoded len of the CRSF frame.

  if (buflen < 3)
  {
    return -NERR_EMPTY;
  }

  struct nex_bytebuf bytebuf;
  nex_bytebuf_init(&bytebuf, buf, buflen);

  i32 code;
  if ((code = nex_bytebuf_read_u8(&bytebuf, &frame->len)) != NOK)
  {
    return code;
  }

  if (!_validate_frame_len(frame->len))
  {
    return -NERR_RANGE;
  }

  if ((code = nex_bytebuf_read_u8(&bytebuf, &frame->type)) != NOK)
  {
    return code;
  }

  if (!_is_valid_type(frame->type))
  {
    return -NERR_INV_ARG;
  }

  if (!_is_bc_frame(frame->type))
  {
    if ((code = nex_bytebuf_read_u8(&bytebuf, &frame->dst_addr)) != NOK)
    {
      return code;
    }

    if ((code = nex_bytebuf_read_u8(&bytebuf, &frame->origin_addr)) != NOK)
    {
      return code;
    }
  }

  code = bb_crsf_decode_packet(frame, &bytebuf);
  if (code != NOK)
  {
    return code;
  }

  if ((code = nex_bytebuf_read_u8(&bytebuf, &frame->crc)) != NOK)
  {
    return code;
  }

  u32 computed_crc = _compute_crc(&buf[1], buflen - 2);
  if (computed_crc != frame->crc)
  {
    return -NERR_INV_ARG;
  }

  return NOK;
}

i32
bb_crsf_decode_packet(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  switch (frame->type)
  {
    case BB_CRSF_FRAME_TYPE_HEARTBEAT:
      return _decode_frame_heartbeat(frame, buf);

    case BB_CRSF_FRAME_TYPE_LINK_STATS:
      return _decode_frame_link_stats(frame, buf);

    case BB_CRSF_FRAME_TYPE_LINK_STATS_RX:
      return _decode_frame_link_stats_rx(frame, buf);

    case BB_CRSF_FRAME_TYPE_LINK_STATS_TX:
      return _decode_frame_link_stats_tx(frame, buf);

    case BB_CRSF_FRAME_TYPE_LINK_STATS_REPEATER:
    case BB_CRSF_FRAME_TYPE_RC_CHANNELS:
      return _decode_frame_rc_channels(frame, buf);

    case BB_CRSF_FRAME_TYPE_RPM:
    case BB_CRSF_FRAME_TYPE_TEMP:
    case BB_CRSF_FRAME_TYPE_VOLTAGE_GRP:
    case BB_CRSF_FRAME_TYPE_VTX_TELEMETRY:
    case BB_CRSF_FRAME_TYPE_BAROMETER:
    case BB_CRSF_FRAME_TYPE_MAGNOMETER:
    case BB_CRSF_FRAME_TYPE_ACCEL_GYRO:

    case BB_CRSF_FRAME_TYPE_SUBSET_RC_CHANNELS:
    case BB_CRSF_FRAME_TYPE_RC_CHANNELS_PACKED_11BITS:

    case BB_CRSF_FRAME_TYPE_ATTITUDE:
    case BB_CRSF_FRAME_TYPE_MAVLINK_FC:
    case BB_CRSF_FRAME_TYPE_FLIGHT_MODE:
    case BB_CRSF_FRAME_TYPE_ESP_NOW:
    case BB_CRSF_FRAME_TYPE_GPS:
    case BB_CRSF_FRAME_TYPE_GPS_TIME:
    case BB_CRSF_FRAME_TYPE_GPS_EXTENDED:
    case BB_CRSF_FRAME_TYPE_VARIOMETER_SENSOR:
    case BB_CRSF_FRAME_TYPE_BATTERY_SENSOR:
    case BB_CRSF_FRAME_TYPE_BAROMETRIC_ALT_VSPEED:
    case BB_CRSF_FRAME_TYPE_AIRSPEED:
      return -NERR_NOTIMPL;

    case BB_CRSF_FRAME_TYPE_PARAM_PING_DEV:
      // This frame has no payload.
      return NOK;

    case BB_CRSF_FRAME_TYPE_PARAM_DEV_INFO:
      return _decode_frame_param_dev_info(frame, buf);

    case BB_CRSF_FRAME_TYPE_PARAM_SETTINGS:

    default:
      return -NERR_INV_ARG;
  }
}

static i32
_encode_frame_gps(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_gps* pkt = &frame->bc.gps;

  code = nex_bytebuf_write_u32_be(buf, (u32) pkt->latitude);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u32_be(buf, (u32) pkt->longitude);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, pkt->groundspeed);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, pkt->heading);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, pkt->altitude);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(buf, pkt->satellites);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_encode_frame_gps_time(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_gps_time* pkt = &frame->bc.gps_time;

  code = nex_bytebuf_write_u16_be(buf, pkt->year);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, pkt->month);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, pkt->day);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, pkt->hour);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, pkt->minute);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, pkt->second);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, pkt->millisecond);
  if (code != NOK)
  {
    return code;
  }

  return code;
}

static i32
_encode_frame_gps_ext(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_gps_ext* pkt = &frame->bc.gps_ext;

  code = nex_bytebuf_write_u8(buf, pkt->fix_type);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->n_speed);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->e_speed);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->v_speed);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->h_speed_acc);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(buf, pkt->fix_type);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(buf, pkt->fix_type);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(buf, pkt->fix_type);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(buf, pkt->fix_type);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(buf, pkt->fix_type);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(buf, pkt->fix_type);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_encode_frame_variometer_sensor(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_variometer* pkt = &frame->bc.variometer;
  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->v_speed);
  return code;
}

static i32
_encode_frame_battery_sensor(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_battery* pkt = &frame->bc.battery;

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->voltage);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->current);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u24_be(buf, pkt->capacity_used);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(buf, pkt->remaining);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_encode_frame_barometric_alt_vspeed(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_baro_alt_vspeed* pkt = &frame->bc.baro;

  code = nex_bytebuf_write_u16_be(buf, pkt->altitude_packed);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(buf, (u8) pkt->vertical_speed_packed);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_encode_frame_airspeed(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_airspeed* pkt = &frame->bc.airspeed;

  code = nex_bytebuf_write_u16_be(buf, pkt->speed);
  return code;
}

static i32
_encode_frame_heartbeat(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_heartbeat* pkt = &frame->bc.heartbeat;

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->origin_address);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_decode_frame_heartbeat(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_heartbeat* pkt = &frame->bc.heartbeat;

  code = nex_bytebuf_read_u16_be(buf, (u16*) &pkt->origin_address);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_encode_frame_rpm(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_rpm* pkt = &frame->bc.rpm;

  code = nex_bytebuf_write_u8(buf, pkt->rpm_source_id);
  if (code != NOK)
  {
    return code;
  }

  for (u32 i = 0; i < pkt->count; ++i)
  {
    code = nex_bytebuf_write_u24_be(buf, (u32) pkt->rpm_values[i]);
    if (code != NOK)
    {
      return code;
    }
  }

  return NOK;
}

static i32
_encode_frame_temp(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_temp* pkt = &frame->bc.temp;
  
  code = nex_bytebuf_write_u8(buf, pkt->temp_source_id);
  if (code != NOK)
  {
    return code;
  }

  for (u32 i = 0; i < pkt->count; ++i)
  {
    code = nex_bytebuf_write_u16_be(buf, (u16) pkt->temperature[i]);
    if (code != NOK)
    {
      return code;
    }
  }

  return NOK;
}

static i32
_encode_frame_voltage_grp(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_voltages* pkt = &frame->bc.voltages;

  code = nex_bytebuf_write_u8(buf, pkt->voltage_source_id);
  if (code != NOK)
  {
    return code;
  }

  for (u32 i = 0; i < pkt->count; ++i)
  {
    code = nex_bytebuf_write_u16_be(buf, pkt->voltages[i]);
    if (code != NOK)
    {
      return code;
    }
  }

  return NOK;
}

static i32
_encode_frame_vtx_telemetry(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_vtx_telemetry* pkt = &frame->bc.vtx_telemetry;

  code = nex_bytebuf_write_u8(buf, pkt->origin_address);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(buf, pkt->power_dBm);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, pkt->frequency_MHz);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u8(buf, pkt->flags);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_encode_frame_barometer(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_barometer* pkt = &frame->bc.barometer;

  code = nex_bytebuf_write_u32_be(buf, (u32) pkt->pressure_pa);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u32_be(buf, (u32) pkt->baro_temp);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_encode_frame_magnometer(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_magnometer* pkt = &frame->bc.magnometer;

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->field_x);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->field_y);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->field_z);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_encode_frame_accel_gyro(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_accel_gyro* pkt = &frame->bc.accel_gyro;

  code = nex_bytebuf_write_u32_be(buf, pkt->sample_time);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->gyro_x);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u32_be(buf, (u16) pkt->gyro_y);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u32_be(buf, (u16) pkt->gyro_z);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u32_be(buf, (u16) pkt->acc_x);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u32_be(buf, (u16) pkt->acc_y);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u32_be(buf, (u16) pkt->acc_z);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u32_be(buf, (u16) pkt->gyro_temp);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_encode_frame_attitude(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_attitude* pkt = &frame->bc.attitude;

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->pitch);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->roll);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_write_u16_be(buf, (u16) pkt->yaw);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_encode_frame_flight_mode(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_flight_mode* pkt = &frame->bc.flight_mode;
  const char* str = pkt->flight_mode;

  while (*str)
  {
    code = nex_bytebuf_write_u8(buf, (u8) *str);
    if (code != NOK)
    {
      return code;
    }

    ++str;
  }

  code = nex_bytebuf_write_u8(buf, 0);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_decode_frame_link_stats(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_link_stats* pkt = &frame->bc.link_stats;

  code = nex_bytebuf_read_u8(buf, &pkt->up_rssi_ant1);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->up_rssi_ant2);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->up_link_quality);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, (u8*) &pkt->up_snr);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->active_antenna);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->rf_profile);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->up_rf_power);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->down_rssi);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->down_link_quality);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, (u8*) &pkt->down_snr);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_decode_frame_rc_channels(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_rc_channels* pkt = &frame->bc.rc_channels;
  u8 arr[22];

  code = nex_bytebuf_read_u8_arr(buf, arr, ARR_SIZE(arr));
  if (code != NOK)
  {
    return code;
  }

  pkt->channels[0] = (u16) (arr[0] | ((arr[1] & 0x7) << 8));
  pkt->channels[1] = (u16) (((arr[1] & 0xf8) >> 3) | ((arr[2] & 0x3f) << 5));
  pkt->channels[2] = (u16) (((arr[2] & 0xc0) >> 6) | (arr[3] << 2) | ((arr[4] & 0x1) << 10));
  pkt->channels[3] = (u16) (((arr[4] & 0xfe) >> 1) | ((arr[5] & 0xf) << 7)); 
  pkt->channels[4] = (u16) (((arr[5] & 0xf0) >> 4) | ((arr[6] & 0x7f) << 4));
  pkt->channels[5] = (u16) (((arr[6] & 0x80) >> 7) | (arr[7] << 1) | ((arr[8] & 0x3) << 9));
  pkt->channels[6] = (u16) (((arr[8] & 0xfc) >> 2) | ((arr[9] & 0x1f) << 6));
  pkt->channels[7] = (u16) (((arr[9] & 0xe0) >> 5) | (arr[10] << 3));

  pkt->channels[8] = (u16) (arr[11] | ((arr[12] & 0x7) << 8));
  pkt->channels[9] = (u16) (((arr[12] & 0xf8) >> 3) | ((arr[13] & 0x3f) << 5));
  pkt->channels[10] = (u16) (((arr[13] & 0xc0) >> 6) | (arr[14] << 2) | ((arr[15] & 0x1) << 10));
  pkt->channels[11] = (u16) (((arr[15] & 0xfe) >> 1) | ((arr[16] & 0xf) << 7)); 
  pkt->channels[12] = (u16) (((arr[16] & 0xf0) >> 4) | ((arr[17] & 0x7f) << 4));
  pkt->channels[13] = (u16) (((arr[17] & 0x80) >> 7) | (arr[18] << 1) | ((arr[19] & 0x3) << 9));
  pkt->channels[14] = (u16) (((arr[19] & 0xfc) >> 2) | ((arr[20] & 0x1f) << 6));
  pkt->channels[15] = (u16) (((arr[20] & 0xe0) >> 5) | (arr[21] << 3));

  return NOK;
}

static i32
_decode_frame_param_dev_info(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  u8 byte;
  u32 idx = 0;

  do
  {
    if ((code = nex_bytebuf_read_u8(buf, &byte)) != NOK)
    {
      return code;
    }

    frame->ext.param_dev_info.device_name[idx++] = byte;
  } while (byte != 0x00);

  code = nex_bytebuf_read_u32_be(buf, &frame->ext.param_dev_info.serial_number);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u32_be(buf, &frame->ext.param_dev_info.hardware_id);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u32_be(buf, &frame->ext.param_dev_info.firmware_id);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &frame->ext.param_dev_info.parameters_total);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &frame->ext.param_dev_info.parameter_version_number);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_decode_frame_link_stats_rx(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_link_stats_rx* pkt = &frame->bc.link_stats_rx;

  code = nex_bytebuf_read_u8(buf, &pkt->rssi_db);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->rssi_percent);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->link_quality);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, (u8*) &pkt->snr);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->rf_power_db);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->rssi_ant2_db);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->active_antenna);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

static i32
_decode_frame_link_stats_tx(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
)
{
  i32 code;
  struct bb_crsf_frame_link_stats_tx* pkt = &frame->bc.link_stats_tx;

  code = nex_bytebuf_read_u8(buf, &pkt->rssi_db);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->rssi_percent);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->link_quality);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, (u8*) &pkt->snr);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->rf_power_db);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->fps);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->rssi_ant2_db);
  if (code != NOK)
  {
    return code;
  }

  code = nex_bytebuf_read_u8(buf, &pkt->active_antenna);
  if (code != NOK)
  {
    return code;
  }

  return NOK;
}

void
bb_crsf_init(
  struct bb_crsf_node* node
)
{
  node->ports_count = 0;
}

i32
bb_crsf_node_add_port(
  struct bb_crsf_node* node,
  volatile void* usart
)
{
  (void) usart;

  if (node->ports_count + 1 >= 8)
  {
    return -NERR_FULL;
  }

  i32 idx = (i32) node->ports_count++;
  struct bb_crsf_port* port = &node->ports[idx];
  // port->usart = usart;

  nex_ring_buffer_init(
    &port->rbbuf_out,
    port->_rawoutrb,
    ARR_SIZE(port->_rawoutrb)
  );

  port->outbuf_wcur = 0;
  port->outbuf_rcur = 0;

  port->inbuf_rcur = 0;
  port->idx = idx;

  _set_port_tx_state(port, BB_CRSF_PORT_TX_STATE_READY);
  _set_port_rx_state(port, BB_CRSF_PORT_RX_STATE_WAIT_SYNC);

  return idx;
}

void
bb_crsf_port_set_sync_byte(
  struct bb_crsf_node* node,
  i32 port_idx,
  u8 sync_byte
)
{
  struct bb_crsf_port* port = &node->ports[port_idx];
  port->sync_byte = sync_byte;
}

// void
// bb_crsf_node_rx_complete(
//   struct bb_crsf_node* node,
//   i32 port_idx
// )
// {
//   struct bb_crsf_port* port = _get_port(node, port_idx);
//   _set_port_rx_state(port, BB_CRSF_PORT_RX_STATE_PARSE);
// }

// void
// bb_crsf_node_rx_ready(
//   struct bb_crsf_node* node,
//   i32 port_idx,
//   u8 byte
// )
// {
//   struct bb_crsf_port* port = _get_port(node, port_idx);
//   _push_port_in_byte(node, port, byte);
// }

void
bb_crsf_node_tx_complete(
  struct bb_crsf_node* node,
  i32 port_idx
)
{
  struct bb_crsf_port* port = _get_port(node, port_idx);
  if (_get_port_tx_state(port) == BB_CRSF_PORT_TX_STATE_IN_PROGRESS)
  {
    _set_port_tx_state(port, BB_CRSF_PORT_TX_STATE_READY);
  }
}

void
bb_crsf_node_tick(
  struct bb_crsf_node* node
)
{
  for (u32 i = 0; i < node->ports_count; ++i)
  {
    struct bb_crsf_port* port = _get_port(node, (i32) i);
    _tick_port(node, port);
  }
}

i32
bb_crsf_port_enqueue_packet(
  struct bb_crsf_node* node,
  i32 port_idx,
  struct bb_crsf_frame* frame
)
{
  struct bb_crsf_port* port = _get_port(node, port_idx);
  u32 bytes_left = nex_ring_buffer_space_left(&port->rbbuf_out);
  const u32 header_sz = _get_header_size();
  u32 bytes_required = _get_frame_size(frame) + header_sz + 1 + 1;
  if (bytes_left < bytes_required)
  {
    return -NERR_FULL;
  }

  u8 buf[64] = {0};
  i32 count = _encode_frame(port->sync_byte, frame, buf, 64);
  nex_ring_buffer_write(&port->rbbuf_out, (u8) count);
  nex_ring_buffer_write_bytes(&port->rbbuf_out, buf, (u32) count);
  
  return NOK;
}

