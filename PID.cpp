#include "PID.h"

PID::PID(){

}
PID::~PID(){

}
void PID::setWeights(double Kp, double Ki, double kd){
    this->Kp=Kp;
    this->Ki=Ki;
    this->Kd=kd
}
double PID::update(double error){
    I=trim(I+error,Imin,Imax);
    if(firstRun){
        prevError=error;
        firstRun=false;
    }
    double p= Kp*error;
    double i= Ki*I;
    double d= Kd*(error-prevError);
    double pid = trim(p+i+d,PIDmin,PIDmax);
    prevError=error;
    return pid;
}
void PID::reset(){
    I=0;
    prevError=0;
    firstRun=true;
}
