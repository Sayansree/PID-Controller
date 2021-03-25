#ifndef PID_H
#define PID_H
class PID{
    public:
        PID();
        ~PID();
        double update(double);

    private:
        double Kp,Ki,Kd;
        double I, Imin, Imax;
        double prevError;
        double PIDmin, PIDmax;

        double trim(double, double, double);

};
#endif