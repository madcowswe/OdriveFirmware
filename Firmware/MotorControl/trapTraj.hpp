#ifndef _TRAP_TRAJ_H
#define _TRAP_TRAJ_H

struct TrajectoryStep_t {
    float Y;
    float Yd;
    float Ydd;
};

class TrapezoidalTrajectory {
   public:
    Axis* axis_ = nullptr;  // set by Axis constructor

    TrapezoidalTrajectory();

    float planTrapezoidal(float Xf, float Xi,
                          float Vi, float Vmax,
                          float Amax, float Dmax);

    TrajectoryStep_t evalTrapTraj(float t);

   private:
    float yAccel_;

    float Xi_;
    float Xf_;
    float Vi_;

    float Ar_;
    float Dr_;
    float Vr_;

    float Ta_;
    float Tv_;
    float Td_;
    float Tav_;
};

#endif