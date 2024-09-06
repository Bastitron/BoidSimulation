#pragma once

#include <vector>

#include <SDL_render.h>

#include "vector2.h"
#include "utility.h"

struct Boid {
    Vector2 position;
    Vector2 velocity;
};

struct SimulationConfiguration {
    float separation_force  = 0.05;
    float cohesion_force    = 0.05;
    float alignment_force   = 0.005;
    float maximal_speed     = 8;
    float visual_range      = 75;
    float boid_margin       = 20;
};

class BoidSimulator {

public:
    std::vector<Boid> boids;

    void Render(SDL_Renderer* renderer, SDL_Texture* boid_texture);

    void Advance(SDL_Window* window, SimulationConfiguration* configuration);

    void Repopulate(int amount, int spawn_area_width, int spawn_area_height);

private:

    void AvoidEdges(Boid* boid, int screen_width, int screen_height, float visual_range);

    void PortalEdges(Boid* boid, int screen_width, int screen_height);

    void LimitSpeed(Boid* boid, float max_speed);

    void Separation(Boid* boid, float force, float BoidPersonalSpace);

    void Alignment(Boid* boid, float force, float visual_range);

    void Cohesion(Boid* boid, float force, float visual_range);

    double VelocityToAngle(double xv, double yv);
};

