# Weller to JBC converter

This project is about convert an old Weller WECP-20 into a modern JBC soldering station with the following: 

* Model Predictive Control with quadratic programming
* Kalman-Bucy filtering
* Modbus for parameter setting and logging
* eFuse with 7400 logic family for safety feature
* Sleep functionality
* Power consumption alarm 

The goal of this project is not to create a JBC clone to compete against JBC soldering station manufacturer. The goal is to create
a Model Predictive Control controller (MPC) together with Kalman-Bucy filtering that works on low cost devices. In this case STM32F051R8 has been used successfully with MPC and Kalman-Bucy filtering. The STM32F051R8 has the following properties:

* ARM®Cortex®-M0 32-bit RISC core
* 48 MHz CPU
* 64 kB in Flash
* 8 kB in SRAM
* 12-bit ADC
* 32-bit PWM
* USART

# Model Predictive Control

The MPC controller has the objective function:

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Objective%20function.png?raw=true)

The MPC controller inside the microcontroller has the following properties:

* Input constraints
* Soft output constraints
* Regularization
* Integral action with anti-windup
* Rate of change constraints
* Disturbance input handling

The code and example for the MPC controller can be found at [CControl](https://github.com/DanielMartensson/CControl).

# Kalman-Bucy filter

The famous Kalman-Bucy filter that was successfully used in Apollo 11 program. The same filter is used inside the microcontroller of this soldering station for estimate the next state vector for the MPC controller. The microcontroller solves the [Algebratic Riccati Equation](https://en.wikipedia.org/wiki/Algebraic_Riccati_equation) for finding the optimal Kalman gain matrix directly.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/DARE.png?raw=true)
![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/LQR.png?raw=true)

The Algebratic Riccati Equation is solved by using Runge-Kutta 4:th order.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/RK4.png?raw=true)

The code and example for the Kalman-Bucy filter can be found at [CControl](https://github.com/DanielMartensson/CControl).

# Performance

Due to the weak 50W transformer inside the Weller WECP-20 soldering sation, the output of the step response is slowly minimizing the steady state error. In other words, the 50W transformer cannot produce enought of current to ramp up the heat at the soldering time. Hence, the steady state still minimize the error between the reference and the trajectory due to internal integral action of the MPC controller. The measurements of the soldering station can be measured by the C++ software [GoobySoft](https://github.com/DanielMartensson/GoobySoft) via [nanoMODBUS](https://github.com/debevv/nanoMODBUS) through a FTDI 232 UART USB Device.

One good thing to mention! This MPC controller giving the soldering tip a more rapidly heat than the original analog PI-controller. Even though they were using the same 50W transformer. So this PCB board heats up the soldering tip much faster than the original does.

It takes about 5 to 6 seconds for the soldering tip to go from sleep (about 20-50 degrees) to 320 degrees. That's a major improvement compared to the old Weller station.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Feedback%20control%20MPC.png?raw=true)

# Calibration parameters

This is the current calibration parameters. The parameters can be set by using the C++ software [GoobySoft](https://github.com/DanielMartensson/GoobySoft). I have been using the genuine JBC tips when I made the calibration.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Calibration%20&%20settings.png?raw=true)

# Build the PCB circuit

The gerber files of the PCB can be found at my [CircuitMaker project](https://workspace.circuitmaker.com/Projects/Details/DanielMrtensson/Weller-to-JBC-converter).

Here is the schematic. I have been purchased the T245 handle and holder from Ali Express.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Schematic.png?raw=true)

Handle: https://www.aliexpress.com/item/1005006125308446.html

Holder: https://www.aliexpress.com/item/1005006533444952.html

DC 5.5x2.1 plug: https://www.aliexpress.com/item/1005006942560340.html

# Pictures

Soldering station.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Weller%20WECP-20.jpg?raw=true)

Soldering station with holder.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Soldering%20station.jpg?raw=true)

Circuit attached.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Circuit%20attached%201.jpg?raw=true)

Circuit attached.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Circuit%20attached%202.jpg?raw=true)

Circuit attached.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Attachment.jpg?raw=true)

Glue.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Glue.jpg?raw=true)

Circuit front. Made with Altium CircuitMaker.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Circuit%20front.png?raw=true)

Circuit back. Made with Altium CircuitMaker.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Circuit%20back.png?raw=true)

Buck DC/DC converter from 36VDC to 7.5VDC and then 7.5VDC to 3.3VDC through a 3.3V LDO.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Buck%20converter.jpg?raw=true)

eFuse with 7400 logic family for safety feature.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Current%20limit.jpg?raw=true)

Current and temperature measurement with high precision operational amplifiers.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Measurement.jpg?raw=true)

STM32F051R8 microcontroller.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Microcontroller.jpg?raw=true)

P-MOSFET.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/P-MOS.jpg?raw=true)

Thread connection to the PCB.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Thread.jpg?raw=true)

Complete Circuit.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Complete.jpg?raw=true)

Flashing.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Flashing.jpg?raw=true)

Potentiometer for temperature settings.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Potentiometer.jpg?raw=true)

Sleep connection.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Sleep%20connection%201.jpg?raw=true)

Sleep connection.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Sleep%20connection%202.jpg?raw=true)

Switch connection.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Switch%20connection%201.jpg?raw=true)

Switch connection.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Switch%20connection%202.jpg?raw=true)

Transformer 50W.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Transformator.jpg?raw=true)


