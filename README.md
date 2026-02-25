# Nex
Modular embedded framework for STM32 microcontrollers.

Nex is a lightweight, layer-based embedded framework designed for building performance-critical applications on STM32 microcontrollers. Currently being developed as the foundation for a custom flight controller.

**Status:** Beta (v0.1) - Core functionality working, API may change.

The framework is organized in modular layers:
- **Libcom** - Hardware-agnostic utilities (ring buffers, queues, formatters).
- **Synapse** - Hardware Abstraction Layer (currently supports STM32F4).
- **System** - OS-like components (scheduler, profiler, system time).
- **Blackbird** - The flight controller (Not implemented yet).

## Project Goals
Building a fully functional drone from scratch: hardware, firmware, and flight control algorithms. This framework serves as the embedded software foundation for that goal.

## Roadmap
- stm32f1/f7 support (More in the future).
- Drivers interfaces.
- Sensor drivers.
- Flight controller.
- Bootloader.
- File system.
- Improve CMake build system.
- Multi-repo (?)
- Doxygen docs.
- More tests.
- ...

## Quick Start 
### Build examples 
```sh
tools/builder/build.py --target=targets/{family}/{series}/{fullname}.json --build-type=Release --examples
``` 
### Build and run tests 
```sh
tools/builder/build.py --target=targets/{family}/{series}/{fullname}.json --build-type=Release --tests
```
Where:
- {family} -> The microcontroller family. Currently supported: stm32.
- {series} -> The microcontroller series. Currently supported: f4.
- {fullname} -> The full microcontroller name. Examples: stm32f411ce, stm32f446re, stm32f429bg.

## License
MIT license. See LICENSE file for details.

