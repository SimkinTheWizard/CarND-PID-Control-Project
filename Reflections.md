# UDACITY SELF DRIVING CAR NANODEGREE 
# Project 9: PID Control

This project aims to control the vehicle using a PID control algorithm. It includes an implementation and tuning of this control methods.

## Description of P, I, and D Parameters
PID control algorithm is a feedback based algorithm that works well in many systems where control is necessary, and consists of three main parts. These are **P**roportional, **I**ntegral, and **D**ifferential components. These three components, together, compansate for the different parts of the impulse response of the controlled system.

**Proportional** component is the main component of this algorithm. As the name suggests the response of this component is proportional to the instantaneous magnitude of the error. The problem with this component is when there is a delay in the system between actuation and output, as in most systems, the output will continue past the desired point and oscillate back and forth. In the project, this component is also the main factor that is steering the vehicle.

**Derivative** components aim to reduce, and if possible eliminate, the oscillations caused by the proportional component. The derivative component is proportional to the derivative, i.e. change of the error with time. The larger the change of error with time, the larger will the derivative component be. Hence it will try to minimize the change of error. In this project, the derivative component was employed for reducing oscillations that is caused by the proportional component.

**Integral** component is component proportional to the error integrated over time. When the signal is oscillating around the desired value (or error is oscillating around zero) the effect of the integral component will be zero. But when there is a residual error in the system, the integral component will work to reduce this error. In the project, this component helped reduce the large, low frequency errors that occured around the large curvature turns.


## Hyperparameter Tuning Process Used
In this project, I implemented a simple PID control class. I used this class for both steering and throttle. The steering control takes the error and uses the output of the PID controller to steer the vehicle, whereas  the throttle control uses the absolute value of the output of the PID controller and subtracts this from the pre-defined maximum throttle value.

For both throttle and steering I began with small P and D values, and zero I values. My method for setting the parameters was to go over _twiddle_ algorithm manually and incrementing and decrementing the each of the values by hand, with 10% incrments to reduce the error. To use _twiddle_ I implemented another function to calculate the RMS error into the PID class.

As I started, I first adjusted to P and D parameters to smoothly navigate the first small curve. As the vehicle approached the larger curves, I introduced I parameters.  Until the vehicle completed the one full lap around the track, I used the heuristics of distance travelled by car, instead of error in _twiddle_ algorithm. After vehicle completed one full lap around the track, I began using RMS error calculated until roughly the same landmark at the end of the lap (the bushes at the right side of the road). I incremented and decremented these values until I could no longer reduce the error by adjusting the parameters.

