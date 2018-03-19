#include "PID.h"
#include <cmath>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	i_error = 0;
	p_error = 0;
	d_error = 0;
	sq_error = 0;
	time_count = 0;
}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;
	sq_error += cte * cte;
	time_count ++;

}

double PID::TotalError() {
	return -Kp*p_error -Ki*i_error-Kd*d_error;
}


double PID::RmsError(){
	return sqrt(sq_error/time_count);
}
