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

The MPC controller has the objective function 

$\underset{\bar U}{min} \phi = \frac{1}{2}\bar U^T \bar H \bar U + \bar g^T \bar U$
$\text{s.t} \;\;\;\; \bar U_{min} \leqslant \bar U \leqslant \bar U_{max}$
$\bar U_{min} \leqslant \bar U \leqslant \bar U_{max}
$\;\;\;\; b_{min} \leqslant A\bar U \leqslant b_{max}$

The MPC controller inside the microcontroller has the following properties:

* Input constraints
* Soft output constraints
* Regularization
* Integral action with anti-windup
* Rate of change constraints

# Performance

Due to the weak 50W transformer inside the Weller WECP-20 soldering sation, the output of the step response is slowly minimizing the steady state error. In other words, the 50W transformer cannot produce enought of current to ramp up the heat at the soldering time. Hence, the steady state still minimize the error between the reference and the trajectory due to internal integral action of the MPC controller.

# Calibration parameters

This is the current calibration parameters. The parameters can be set by using the C++ software [GoobySoft](https://github.com/DanielMartensson/GoobySoft)






