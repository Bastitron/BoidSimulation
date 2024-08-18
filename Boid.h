#include "vector"


struct Boid {
    double x;
    double y;
    double x_vel;
    double y_vel;
};

class BoidSimulator {
    std::vector<Boid> boids;

    void Render();

    void Advance();
};

