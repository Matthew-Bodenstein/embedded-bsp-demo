# Embedded BSP Demo

This project demonstrates a **board support package (BSP)-style embedded system** using the **FreeRTOS Windows Simulator**.  
It simulates real-time tasks for communication, sensor drivers, error handling, and memory testing, showing how FreeRTOS handles  
**queues, semaphores, and task scheduling** in an embedded environment.

---

## Features
- **Task A (Communication / UART):** Sends simulated UART heartbeat messages.  
- **Task B (Sensor Driver):** Generates random sensor values and sends them via a queue.  
- **Task C (Error Handling):** Reads sensor values, flags errors if out of range.  
- **Task D (Memory Test – optional):** Simulates system memory diagnostics.  
- Uses **queues** for inter-task communication.  
- Uses **semaphores** for resource protection.  
- Includes **timestamped logging** for each task action.  

---

## File Structure
```
embedded-bsp-demo/
src/
main.c              # Application code (task creation, scheduler)
uart_driver.c/.h    # UART driver (heartbeat)
sensor_driver.c/.h  # Sensor driver (random values)
memory_test.c/.h    # Memory test task (optional diagnostics)
FreeRTOSConfig.h    # RTOS configuration
README.md
.gitignore
```

---

## Example Output
```
Starting FreeRTOS demo...
[1 ticks | 0.00 s][Task A] Sending heartbeat...
[1 ticks | 0.00 s][Task B] Sensor value = 41
[1 ticks | 0.00 s][Task C] Sensor value OK: 41
[201 ticks | 0.20 s][Task C] Sensor value out of range! Error flagged: 107
[481 ticks | 0.48 s][Task A] Sending heartbeat...
[804 ticks | 0.80 s][Task C] Sensor value OK: 89
```

---

## How to Build & Run
This project is designed to run on top of the **FreeRTOS Windows Simulator**.  
If you download this repo by itself, it will not compile straight away — you also need the FreeRTOS kernel sources and headers.

### Steps:
1. Install **Visual Studio (Community Edition)**.  
2. Download the **FreeRTOS Windows Simulator** from [FreeRTOS.org](https://www.freertos.org/Documentation/02-Kernel/03-Supported-devices/04-Demos/02-Supported-demos).  
3. Open the Visual Studio solution that comes with the simulator.  
4. Add the files from this repo’s `src/` folder (`main.c`, `uart_driver.c`, `sensor_driver.c`, `memory_test.c`, and `FreeRTOSConfig.h`) into the project.  
5. Build and run in Debug mode.  
6. The console will display timestamped logs (see screenshot above).  

---

## Why Isn’t the Full FreeRTOS Included?
FreeRTOS is a full real-time operating system with many source files and ports.  
Including the entire kernel here would make the repository unnecessarily large and messy.  

Instead:  
- This repo contains **only the custom BSP demo code and config** that I wrote.  
- The README explains how to run it with FreeRTOS.  
- Engineers familiar with embedded systems will already have FreeRTOS or know how to get it.  

This keeps the repo clean and professional, while still being reproducible.

---

## Why This Project?
This demo highlights:  
- **Embedded BSP software** principles.  
- **Real-time task scheduling** using FreeRTOS.  
- **Inter-task communication** with queues/semaphores.  
- **System health monitoring** with memory diagnostics.  // This can be added but was not added in this project.

It mirrors real-world engineering tasks such as:  
- Developing board support packages for SoC-based systems.  
- Integrating drivers into third-party hardware.  
- Following coding standards in multi-threaded embedded environments.

