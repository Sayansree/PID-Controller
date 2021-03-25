#ifndef PID_H
#define PID_H
class PID{
    public:
        PID();
        ~PID();
        void reset();
        void setWeights(double , double , double);
        double update(double);
        

    private:
        double Kp,Ki,Kd;
        double I, Imin, Imax;
        double prevError;
        double PIDmin, PIDmax;
        bool firstRun;
        double trim(double, double, double);

};
#endif