#include <vector>
#include "Boid.h"

class Rules {
    void Flock(std::vector<Boid>* boids, Boid* boid, double view_distance, double power);

    void Align(std::vector<Boid>* boids, Boid* boid, double view_distance, double power);

    void Avoid(std::vector<Boid>* boids, Boid* boid, double view_distance, double power);
};

