#ifndef BLACKBIRD_PROTO_CRSF_H
#define BLACKBIRD_PROTO_CRSF_H

#include "libcom/bytebuf.h"
#include "libcom/data/ring_buffer.h"
#include "libcom/types.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

enum bb_crsf_addr
{
  BB_CRSF_ADDR_BROADCAST = 0x00,
  BB_CRSF_ADDR_CLOUD = 0x0e,
  BB_CRSF_ADDR_USB = 0x10,
  BB_CRSF_ADDR_BLUETOOTH_WIFI = 0x12,
  BB_CRSF_ADDR_WIFI_RECV = 0x13,
  BB_CRSF_ADDR_VIDEO_RECV = 0x14,
  BB_CRSF_ADDR_OSD_TBS_CORE_PNP_PRO = 0x80,
  BB_CRSF_ADDR_ESC1 = 0x90,
  BB_CRSF_ADDR_ESC2 = 0x91,
  BB_CRSF_ADDR_ESC3 = 0x92,
  BB_CRSF_ADDR_ESC4 = 0x93,
  BB_CRSF_ADDR_ESC5 = 0x94,
  BB_CRSF_ADDR_ESC6 = 0x95,
  BB_CRSF_ADDR_ESC7 = 0x96,
  BB_CRSF_ADDR_ESC8 = 0x97,
  BB_CRSF_ADDR_VOLTAGE_CURRENT_SENSOR = 0xc0,
  BB_CRSF_ADDR_GPS = 0xc2,
  BB_CRSF_ADDR_TBS_BLACKBOX = 0xc4,
  BB_CRSF_ADDR_FC = 0xc8,
  BB_CRSF_ADDR_RACE_TAG = 0xcc,
  BB_CRSF_ADDR_VTX = 0xce,
  BB_CRSF_ADDR_REMOTE_CONTROL = 0xea,
  BB_CRSF_ADDR_REPEATER_RECV = 0xeb,
  BB_CRSF_ADDR_RC_CROSSFIRE_RX = 0xec,
  BB_CRSF_ADDR_REPEATER_TX = 0xed,
  BB_CRSF_ADDR_RC_CROSSFIRE_TX = 0xee
};

enum bb_crsf_frame_type : u8
{
  BB_CRSF_FRAME_TYPE_GPS = 0x02,
  BB_CRSF_FRAME_TYPE_GPS_TIME = 0x03,
  BB_CRSF_FRAME_TYPE_GPS_EXTENDED = 0x06,
  BB_CRSF_FRAME_TYPE_VARIOMETER_SENSOR = 0x07,
  BB_CRSF_FRAME_TYPE_BATTERY_SENSOR = 0x08,
  BB_CRSF_FRAME_TYPE_BAROMETRIC_ALT_VSPEED = 0x09,
  BB_CRSF_FRAME_TYPE_AIRSPEED = 0x0a,
  BB_CRSF_FRAME_TYPE_HEARTBEAT = 0x0b,
  BB_CRSF_FRAME_TYPE_RPM = 0x0c,
  BB_CRSF_FRAME_TYPE_TEMP = 0x0d,
  BB_CRSF_FRAME_TYPE_VOLTAGE_GRP = 0x0e,
  BB_CRSF_FRAME_TYPE_VTX_TELEMETRY = 0x10,
  BB_CRSF_FRAME_TYPE_BAROMETER = 0x11,
  BB_CRSF_FRAME_TYPE_MAGNOMETER = 0x12,
  BB_CRSF_FRAME_TYPE_ACCEL_GYRO = 0x13,
  BB_CRSF_FRAME_TYPE_LINK_STATS = 0x14,
  BB_CRSF_FRAME_TYPE_LINK_STATS_REPEATER = 0x15,
  BB_CRSF_FRAME_TYPE_RC_CHANNELS = 0x16,
  BB_CRSF_FRAME_TYPE_SUBSET_RC_CHANNELS = 0x17,
  BB_CRSF_FRAME_TYPE_RC_CHANNELS_PACKED_11BITS = 0x18,
  BB_CRSF_FRAME_TYPE_LINK_STATS_RX = 0x1c,
  BB_CRSF_FRAME_TYPE_LINK_STATS_TX = 0x1d,
  BB_CRSF_FRAME_TYPE_ATTITUDE = 0x1e,
  BB_CRSF_FRAME_TYPE_MAVLINK_FC = 0x1f,
  BB_CRSF_FRAME_TYPE_FLIGHT_MODE = 0x21,
  BB_CRSF_FRAME_TYPE_ESP_NOW = 0x22,

  BB_CRSF_FRAME_TYPE_PARAM_PING_DEV = 0x28,
  BB_CRSF_FRAME_TYPE_PARAM_DEV_INFO = 0x29,
  BB_CRSF_FRAME_TYPE_PARAM_SETTINGS = 0x2b
};

struct bb_crsf_frame_gps
{
  i32 latitude;
  i32 longitude;
  u16 groundspeed;
  u16 heading;
  u16 altitude;
  u8 satellites;
};

struct bb_crsf_frame_gps_time
{
  u16 year;
  u8 month;
  u8 day;
  u8 hour;
  u8 minute;
  u8 second;
  u16 millisecond;
};

struct bb_crsf_frame_gps_ext
{
  u8 fix_type;
  i16 n_speed;
  i16 e_speed;
  i16 v_speed;
  i16 h_speed_acc;
  i16 track_acc;
  i16 alt_allipsoid;
  i16 h_acc;
  i16 v_acc;
  i16 reserved;
  i16 hDOP;
  i16 vDOP;
};

struct bb_crsf_frame_variometer
{
  i16 v_speed;
};

struct bb_crsf_frame_battery
{
  i16 voltage;
  i16 current;
  u32 capacity_used;
  u8 remaining;
};

struct bb_crsf_frame_baro_alt_vspeed
{
  u16 altitude_packed;
  i8 vertical_speed_packed;
};

struct bb_crsf_frame_airspeed
{
  u16 speed;
};

struct bb_crsf_frame_heartbeat
{
  i16 origin_address;
};

struct bb_crsf_frame_rpm
{
  u8 rpm_source_id;
  i32 rpm_values[19];

  // Not (de)serialized.
  u32 count;
};

struct bb_crsf_frame_temp
{
  u8 temp_source_id;
  i16 temperature[20];

  // Not (de)serialized.
  u32 count;
};

struct bb_crsf_frame_voltages
{
  u8 voltage_source_id;
  u16 voltages[29];

  // Not (de)serialized.
  u32 count;
};

struct bb_crsf_frame_vtx_telemetry
{
  u8 origin_address;
  u8 power_dBm;
  u16 frequency_MHz;

  union
  {
    struct
    {
      u8 pit_mode:1;
      u8 pitmode_control:2;
      u8 pitmode_switch:4;
    };
    
    struct
    {
      u8 flags;
    };
  };
};

struct bb_crsf_frame_barometer
{
  i32 pressure_pa;
  i32 baro_temp;
};

struct bb_crsf_frame_magnometer
{
  i16 field_x;
  i16 field_y;
  i16 field_z;
};

struct bb_crsf_frame_accel_gyro
{
  u32 sample_time;
  i16 gyro_x;
  i16 gyro_y;
  i16 gyro_z;
  i16 acc_x;
  i16 acc_y;
  i16 acc_z;
  i16 gyro_temp;
};

struct bb_crsf_frame_link_stats
{
  u8 up_rssi_ant1;
  u8 up_rssi_ant2;
  u8 up_link_quality;
  i8 up_snr;
  u8 active_antenna;
  u8 rf_profile;
  u8 up_rf_power;
  u8 down_rssi;
  u8 down_link_quality;
  i8 down_snr;
};

struct bb_crsf_frame_rc_channels
{
  u16 channels[16];
};

struct bb_crsf_frame_link_stats_rx
{
  u8 rssi_db;
  u8 rssi_percent;
  u8 link_quality;
  i8 snr;
  u8 rf_power_db;
  u8 rssi_ant2_db;
  u8 active_antenna;
};

struct bb_crsf_frame_link_stats_tx
{
  u8 rssi_db;
  u8 rssi_percent;
  u8 link_quality;
  i8 snr;
  u8 rf_power_db;
  u8 fps;
  u8 rssi_ant2_db;
  u8 active_antenna;
};

struct bb_crsf_frame_attitude
{
  i16 pitch;
  i16 roll;
  i16 yaw;
};

struct bb_crsf_frame_mavlink_fc
{
  i16 airspeed;
  u8 base_mode;
  u32 custom_mode;
  u8 autopilot_type;
  u8 firmware_type;
};

struct bb_crsf_frame_flight_mode
{
  char flight_mode[62];
};

struct bb_crsf_bc_frame
{
  union
  {
    struct bb_crsf_frame_gps gps;
    struct bb_crsf_frame_gps_time gps_time;
    struct bb_crsf_frame_gps_ext gps_ext;
    struct bb_crsf_frame_variometer variometer;
    struct bb_crsf_frame_battery battery;
    struct bb_crsf_frame_baro_alt_vspeed baro;
    struct bb_crsf_frame_airspeed airspeed;
    struct bb_crsf_frame_heartbeat heartbeat;
    struct bb_crsf_frame_rpm rpm;
    struct bb_crsf_frame_temp temp;
    struct bb_crsf_frame_voltages voltages;
    struct bb_crsf_frame_vtx_telemetry vtx_telemetry;
    struct bb_crsf_frame_barometer barometer;
    struct bb_crsf_frame_magnometer magnometer;
    struct bb_crsf_frame_accel_gyro accel_gyro;
    struct bb_crsf_frame_link_stats link_stats;
    struct bb_crsf_frame_rc_channels rc_channels;

    // TODO
    struct bb_crsf_frame_link_stats_rx link_stats_rx;
    struct bb_crsf_frame_link_stats_tx link_stats_tx;
    struct bb_crsf_frame_attitude attitude;
    struct bb_crsf_frame_mavlink_fc mavlink;
    struct bb_crsf_frame_flight_mode flight_mode;
  };
};

struct bb_crsf_frame_param_dev_info
{
  u8 device_name[60];
  u32 serial_number;
  u32 hardware_id;
  u32 firmware_id;
  u8 parameters_total;
  u8 parameter_version_number;
};

struct bb_crsf_ext_frame
{
  union
  {
    struct bb_crsf_frame_param_dev_info param_dev_info;
  };
};

struct bb_crsf_frame
{
  u8 len;
  enum bb_crsf_frame_type type;

  // Only used for extended header frames.
  u8 dst_addr;
  u8 origin_addr;

  union
  {
    struct bb_crsf_bc_frame bc;
    struct bb_crsf_ext_frame ext;
  };

  u8 crc;
};

enum bb_crsf_port_rx_state
{
  BB_CRSF_PORT_RX_STATE_WAIT_SYNC,
  BB_CRSF_PORT_RX_STATE_WAIT_LEN,
  BB_CRSF_PORT_RX_STATE_WAIT_TYPE,
  BB_CRSF_PORT_RX_STATE_WAIT_PAYLOAD,
  BB_CRSF_PORT_RX_STATE_WAIT_CRC,
  BB_CRSF_PORT_RX_STATE_PARSE
};

enum bb_crsf_port_tx_state
{
  BB_CRSF_PORT_TX_STATE_READY,
  BB_CRSF_PORT_TX_STATE_IN_PROGRESS
};

#define BB_CRSF_PORT_INBUF_LEN (2048)

struct bb_crsf_port
{
  // volatile void* usart;
  // volatile void* dma;

  i32 idx;

  u8 sync_byte;

  u8 pktbuf[64];
  u32 pktcur;

  u8 inbuf[BB_CRSF_PORT_INBUF_LEN];
  u32 inbuf_rcur;
  u8 inpacket_len;
  u8 inpacket_type;
  u8 inpacket_bytes_left;
  u8 inpacket_crc;
  enum bb_crsf_port_rx_state rx_state;

  u8 _rawoutrb[256];
  struct nex_ring_buffer rbbuf_out;

  u8 seq_out_queue[64];

  u32 outbuf_wcur;
  u32 outbuf_rcur;

  u8 outpacket_len;
  u8 outpacket_type;
  u8 outpacket_bytes_left;
  u8 outpacket_crc;
  enum bb_crsf_port_tx_state tx_state;
};

struct bb_crsf_port_ops
{
  void (*on_packet_ready)(struct bb_crsf_port*, struct bb_crsf_frame*);
  void (*send)(u8*, u32);
  u32 (*get_items_left)(void);
  
  void (*on_parse_fail)(void);
};

struct bb_crsf_node
{
  struct bb_crsf_port ports[8];
  u32 ports_count;
  struct bb_crsf_port_ops* ops;
};

void
bb_crsf_init(
  struct bb_crsf_node* node
);

i32
bb_crsf_node_add_port(
  struct bb_crsf_node* node,
  volatile void* usart
);

void
bb_crsf_port_set_sync_byte(
  struct bb_crsf_node* node,
  i32 port_idx,
  u8 sync_byte
);

// Called by DMA ISR
void
bb_crsf_node_tx_complete(
  struct bb_crsf_node* node,
  i32 port_idx
);

void
bb_crsf_node_tick(
  struct bb_crsf_node* node
);

i32
bb_crsf_read_packet(
  struct bb_crsf_frame* frame,
  u8* buf,
  u32 len
);

i32
bb_crsf_decode_packet(
  struct bb_crsf_frame* frame,
  struct nex_bytebuf* buf
);

i32
bb_crsf_port_enqueue_packet(
  struct bb_crsf_node* node,
  i32 port_idx,
  struct bb_crsf_frame* frame
);

END_DECLARATIONS

#endif
