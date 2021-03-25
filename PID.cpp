#include "PID.h"

PID::PID(){

}
PID::~PID(){

}
double PID::update(double error){
    I=trim(I+error,Imin,Imax);
    double p= Kp*error;
    double i= Ki*I;
    double d= Kd*(error-prevError);
    double pid = trim(p+i+d,PIDmin,PIDmax);
    return pid;
}
