# Weller-to-JBC-converter

This project is about convert an old Weller WECP-20 into a modern JCB soldering station with the following: 

* Model Predictive Control with quadratic programming
* Kalman-Bucy filtering
* Modbus for parameter setting and logging
* eFuse for safety

The goal of this project is not to create a JCB clone to compete against JCB soldering station manufacturer. The goal is to create
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

# Performance

Due to the weak 50W transformer inside the Weller WECP-20 soldering sation, the output of the step response is slowly minimizing the steady state error. In other words, the 50W transformer cannot produce enought of current to ramp up the heat at the soldering time. Hence, the steady state still minimize the error between the reference and the trajectory due to internal integral action of the MPC controller. The measurements of the soldering station can be measured by the C++ software [GoobySoft](https://github.com/DanielMartensson/GoobySoft) via [nanoMODBUS](https://github.com/debevv/nanoMODBUS) through a FTDI 232 UART USB Device.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Feedback%20control%20MPC.png?raw=true)

# Calibration parameters

This is the current calibration parameters. The parameters can be set by using the C++ software [GoobySoft](https://github.com/DanielMartensson/GoobySoft).

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Calibration%20&%20settings.png?raw=true)

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

Buck DC/DC converter from 36VDC to 7.5VDC and then 7.5VDC to 3.3VDC through an 3.3V LDO.

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Buck%20converter.jpg?raw=true)

eFuse current.

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

![a](https://github.com/DanielMartensson/Weller-to-JBC-converter/blob/main/Pictures/Transformer.jpg?raw=true)


