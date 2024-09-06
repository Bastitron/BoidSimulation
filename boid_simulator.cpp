#include "boid_simulator.h"

#include "logger.h"

void BoidSimulator::Advance(SDL_Window *window, SimulationConfiguration* configuration) {
    int screen_width;
    int screen_height;
    SDL_GetWindowSize(window, &screen_width, &screen_height);

    for (int i = 0; i < boids.size(); i++) {
        Boid *boid = &boids[i];


        Cohesion(boid, configuration->cohesion_force, configuration->visual_range);
        Separation(boid, configuration->separation_force, configuration->boid_margin);
        Alignment(boid, configuration->alignment_force, configuration->visual_range);


        LimitSpeed(boid, configuration->maximal_speed);
        //PortalEdges(boid, screen_width, screen_height);
        AvoidEdges(boid, screen_width, screen_height, configuration->visual_range);

        boid->position.x += boid->velocity.x;
        boid->position.y += boid->velocity.y;
    }
}

void BoidSimulator::Render(SDL_Renderer *renderer, SDL_Texture *boid_texture) {
    for (auto &i: boids) {
        Boid *boid = &i;

        SDL_FRect rect;
        rect.x = (float) boid->position.x - 12;
        rect.y = (float) boid->position.y - 12;
        rect.w = 24;
        rect.h = 24;

        SDL_FPoint texture_center;
        texture_center.x = 12;
        texture_center.y = 12;

        SDL_RenderCopyExF(renderer, boid_texture, nullptr, &rect,
                          VelocityToAngle(boid->velocity.x, -boid->velocity.y), &texture_center, SDL_FLIP_NONE);
    }
}

void BoidSimulator::AvoidEdges(Boid *boid, int screen_width, int screen_height, float visual_range) {
    double x = boid->position.x;
    double y = boid->position.y;

    if (x < visual_range ) {
        boid->velocity.x += 0.5;
    }
    if (x > screen_width - visual_range) {
        boid->velocity.x -= 0.5;
    }
    if (y < visual_range) {
        boid->velocity.y += 0.5;
    }
    if (y > screen_height - visual_range) {
        boid->velocity.y -= 0.5;
    }
}

void BoidSimulator::PortalEdges(Boid *boid, int screen_width, int screen_height) {
    if (boid->position.x < 0)
        boid->position.x += screen_width;
    if (boid->position.x > screen_width)
        boid->position.x -= screen_width;
    if (boid->position.y < 0)
        boid->position.y += screen_height;
    if (boid->position.y > screen_height)
        boid->position.y -= screen_height;
}

void BoidSimulator::Separation(Boid *boid, float force, float BoidPersonalSpace) {
    float avoid_vx = 0;
    float avoid_vy = 0;

    for (auto &i: boids) {
        Boid *neighbor_boid = &i;

        if (neighbor_boid != boid) {
            if (boid->position.Distance(neighbor_boid->position) < BoidPersonalSpace) {
                avoid_vx += boid->position.x - neighbor_boid->position.x;
                avoid_vy += boid->position.y - neighbor_boid->position.y;
            }
        }
    }

    boid->velocity.x += avoid_vx * force;
    boid->velocity.y += avoid_vy * force;
}

void BoidSimulator::LimitSpeed(Boid *boid, float max_speed) {
    float speed = boid->velocity.Magnitude();

    if (speed > max_speed) {
        boid->velocity.x = (boid->velocity.x / speed) * max_speed;
        boid->velocity.y = (boid->velocity.y / speed) * max_speed;
    }
}

void BoidSimulator::Alignment(Boid *boid, float force, float visual_range) {
    float avg_vx = 0;
    float avg_vy = 0;

    int neighbors = 0;

    for (auto &i: boids) {
        Boid *neighbor_boid = &i;

        if (boid->position.Distance(neighbor_boid->position) < visual_range) {
            avg_vx += neighbor_boid->velocity.x;
            avg_vy += neighbor_boid->velocity.y;
            neighbors++;
        }
    }

    if (neighbors) {
        avg_vx = avg_vx / neighbors;
        avg_vy = avg_vy / neighbors;

        boid->velocity.x += (avg_vx - boid->velocity.x) * force;
        boid->velocity.y += (avg_vy - boid->velocity.y) * force;
    }
}

void BoidSimulator::Cohesion(Boid *boid, float force, float visual_range) {
    float avg_px = 0;
    float avg_py = 0;

    int neighbors = 0;

    for (auto &i: boids) {
        Boid *neighbor_boid = &i;

        if (boid->position.Distance(neighbor_boid->position) < visual_range) {
            avg_px += neighbor_boid->velocity.x;
            avg_py += neighbor_boid->velocity.y;
            neighbors++;
        }
    }

    if (neighbors) {
        avg_px = avg_px / neighbors;
        avg_py = avg_py / neighbors;

        boid->velocity.x += avg_px * force;
        boid->velocity.y += avg_py * force;
    }
}

double BoidSimulator::VelocityToAngle(double xv, double yv) {
    return atan2(xv, yv) * (180 / 3.1415926535);
}

void BoidSimulator::Repopulate(int amount, int spawn_area_width, int spawn_area_height) {
    boids.clear();

    for (int i = 0; i < amount; i++) {
        Boid boid {
                {randomFloat() * spawn_area_width, randomFloat() * spawn_area_height},
                {randomFloat() * 10 - 5, randomFloat() * 10 - 5}
        };

        this->boids.push_back(boid);
    }
}
