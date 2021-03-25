#include "PID.h"

PID::PID(){
    setWeights(0,0,0);
    reset();
}
PID::~PID(){

}
void PID::setWeights(double Kp, double Ki, double kd){
    this->Kp=Kp;
    this->Ki=Ki;
    this->Kd=kd;
}
void PID::setILimits(double Imin, double Imax){
    this->Imax=Imax;
    this->Imin=Imin;
}
void PID::setPIDLimits(double PIDmin, double PIDmax){
    this->PIDmax=PIDmax;
    this->PIDmin=PIDmin;
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
double PID::trim(double val, double min, double max){
    if(val>max)return max;
    if(val<min)return min;
    return val;
}
