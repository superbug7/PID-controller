#include "PID.h"

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
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  prev_cte = 0.0;


}

void PID::UpdateError(double cte) {
  p_error = cte;

  i_error += cte;

  d_error = cte - prev_cte;

  prev_cte = cte;
}

double PID::TotalError() {
   double delta;    
   delta = -1 * (p_error * Kp + i_error * Ki + d_error * Kd);
  
   if ( delta > 1.0 ) delta = 1.0;	
   if ( delta < -1.0 ) delta = -1.0;

   return  (-1) * delta;	
}


