#pragma once

#include "boid_simulator.h"

#include <SDL.h>
#include <SDL_image.h>
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include "logger.h"
#include "im_framerate_graph.h"
#include "utility.h"

class Application {
public:
    SDL_Window*             window              = nullptr;
    SDL_Renderer*           renderer            = nullptr;
    SDL_Texture*            boid_texture        = nullptr;
    SDL_RendererInfo        info;

    ImGuiIO*                io                  = nullptr;

    int                     window_width        = 1000;
    int                     window_height       = 600;
    int                     reset_boid_count    = 100;
    bool                    keep_alive          = true;

    ImFramerateGraph        framerateGraph      = ImFramerateGraph();
    SimulationConfiguration configuration;
    BoidSimulator           simulator;

    Application();
    ~Application();

    void Run();

private:
    void HandleEvent(SDL_Event& event);
    void Render();
};

