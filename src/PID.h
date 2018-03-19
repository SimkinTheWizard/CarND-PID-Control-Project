#ifndef PID_H
#define PID_H

class PID {
private:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double sq_error;
  int time_count;
  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

	
  /*
  * Constructor
  */
public:
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
	
	/*
	 * Calculate the total RMS error.
	 */
	double RmsError();
};

#endif /* PID_H */
