# Nex
Nex is a lightweight, layer-based embedded framework designed for building performance-critical applications on STM32 microcontrollers. Currently being developed as the foundation for a custom flight controller.

**Status:** Beta - Core functionality working, API may change.

The framework is organized in modular layers:
- **Libcom** - Hardware-agnostic utilities (ring buffers, queues, formatters).
- **Synapse** - Hardware Abstraction Layer (currently supports STM32F4).
- **System** - OS-like components (scheduler, profiler, system time).
- **Blackbird** - The flight controller (Not implemented yet).

## Building
### Build Examples 
```sh
tools/builder/build.py --target={target} --build-type=Release --examples
``` 
### Build and Run Tests 
```sh
tools/builder/build.py --target={target} --build-type=Release --tests
```
Where:
- `{target}` -> The target microcontroller to build for. Examples: `stm32f411ce`, `stm32f446re`, `stm32f429bg`.

## Project Goals
Building a fully functional drone from scratch: hardware, firmware, and flight control algorithms. This framework serves as the embedded software foundation for that goal.

## Roadmap
- Extend stm32 support to other families.
- Driver interfaces.
- Sensor drivers.
- Flight controller.
- Bootloader.
- File system.
- Multi-repo (?)
- Doxygen docs.
- More tests.
- ...

## License
MIT license. See LICENSE file for details.



