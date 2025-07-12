# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is U-Boot (Das U-Boot), a universal boot loader for embedded systems supporting PowerPC, ARM, MIPS, RISC-V, x86, and other architectures. U-Boot provides hardware initialization, device drivers, and booting capabilities for embedded boards and devices.

## Build System and Common Commands

### Configuration and Building
- **Configure**: `make <board>_defconfig` (e.g., `make am62x_evm_a53_defconfig`)
- **Build**: `make` or `make all` 
- **Clean**: `make clean` (remove build artifacts), `make mrproper` (clean + config files)
- **Help**: `make help` - shows all available targets and configuration options

### Configuration Tools
- `make menuconfig` - TUI-based configuration
- `make defconfig` - use default configuration for current architecture
- `make savedefconfig` - save minimal configuration to ./defconfig

### Testing
- `make check` - run automated sandbox tests
- `make pcheck` - run tests in parallel

### Key Build Variables
- `V=1` - verbose build output
- `O=<dir>` - build in separate output directory
- `CROSS_COMPILE=<prefix>` - cross-compilation toolchain prefix

## Architecture and Code Structure

### Core Directories
- **arch/**: Architecture-specific code (ARM, x86, RISC-V, PowerPC, etc.)
- **board/**: Board-specific implementations and configurations
- **common/**: Core U-Boot functionality (boot logic, command line, etc.)
- **cmd/**: Command implementations for U-Boot console
- **drivers/**: Device drivers organized by subsystem
- **include/**: Header files and configuration definitions
- **lib/**: Shared libraries and utilities
- **boot/**: Boot flow and image handling
- **configs/**: Board configuration files (_defconfig format)
- **dts/**: Device tree source files
- **scripts/**: Build scripts and utilities
- **tools/**: Host tools for building and debugging

### Configuration System
- Kconfig-based configuration system similar to Linux kernel
- Board configurations in `configs/<board>_defconfig` files
- Configuration headers in `include/configs/<board>.h`
- Device tree support for hardware description

### Key Subsystems
- **Drivers Model (DM)**: Modern driver framework with device trees
- **SPL/TPL**: Secondary/Tertiary Program Loaders for multi-stage boot
- **UEFI**: UEFI runtime services and boot support  
- **FIT Images**: Flattened Image Tree format for verified boot
- **Networking**: lwIP stack and legacy networking support
- **Storage**: Support for eMMC, SD, NAND, NOR, SPI flash, SATA, USB storage

### Boot Process
1. **Early Init**: Basic hardware setup, memory controller, clocks
2. **SPL** (if enabled): Load main U-Boot from storage
3. **Main U-Boot**: Full initialization, driver model, command shell
4. **Boot Target**: Load and execute operating system (Linux, RTOS, etc.)

### Development Workflow
- Board ports start by creating defconfig and device tree files
- Driver development follows Linux kernel patterns where possible
- Configuration via Kconfig and device trees
- Extensive use of weak functions for board-specific overrides

### Important Files
- `Makefile`: Top-level build configuration  
- `Kconfig`: Main configuration options
- `README`: Comprehensive documentation (large file, read in sections)
- `include/common.h`: Core function declarations
- `common/main.c`: Main execution loop
- `common/board_f.c` and `common/board_r.c`: Board initialization sequences

## Notes
- This is a complex embedded systems codebase with hardware-specific code
- Many configurations are board-specific via defconfig files
- Supports dozens of different architectures and hundreds of boards
- Build system generates board-specific binaries for firmware flashing
- Heavy use of conditional compilation based on CONFIG_ options