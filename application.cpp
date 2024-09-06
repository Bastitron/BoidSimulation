#include "application.h"

#include "im_sketch.h"
#include "GUI.h"

Application::Application() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        Logger::Log(Logger::ERROR, "SDL_Init Error: {}", SDL_GetError());
        exit(1);
    }

#ifdef SDL_HINT_IME_SHOW_UI
    SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
#endif

    window = SDL_CreateWindow("Boid Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width,
                              window_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

    if (window == nullptr) {
        Logger::Log(Logger::ERROR, "SDL_CreateWindow Error: {}", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1,  SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) {
        Logger::Log(Logger::ERROR, "SDL_CreateRenderer Error: {}", SDL_GetError());
        exit(1);
    }

    SDL_GetRendererInfo(renderer, &info);

    boid_texture = IMG_LoadTexture(renderer, "./assets/boid.png");

    if (boid_texture == nullptr) {
        Logger::Log(Logger::ERROR, "IMG_LoadTexture Error: {}", IMG_GetError());
    }

    SDL_SetTextureScaleMode(boid_texture, SDL_ScaleModeLinear);
    simulator.Repopulate(reset_boid_count, window_width, window_height);
}

void Application::Run() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = &ImGui::GetIO();
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io->Fonts->AddFontFromFileTTF("./assets/font.ttf", 18.0f);

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    ImSketch::Setup();

    while (keep_alive) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            HandleEvent(event);
        }

        if (SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED) {
            SDL_Delay(100);
            continue;
        }

        Render();
    }
}

void Application::Render() {
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    GUI::Draw(this);
    SDL_RenderSetScale(renderer, io->DisplayFramebufferScale.x, io->DisplayFramebufferScale.y);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    simulator.Advance(window, &configuration);
    simulator.Render(renderer, boid_texture);

    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);

    SDL_RenderPresent(renderer);
}

void Application::HandleEvent(SDL_Event& event) {
    ImGui_ImplSDL2_ProcessEvent(&event);

    if (event.type == SDL_QUIT) {
        keep_alive = false;
    }
    if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE &&
        event.window.windowID == SDL_GetWindowID(window)) {
        keep_alive = true;
    }

    if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED &&
        event.window.windowID == SDL_GetWindowID(window)) {
        SDL_GetWindowSize(window, &window_width, &window_height);
    }

    if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            if (!ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow)) {
                Boid boid {
                        {(float) event.button.x - 18, (float) event.button.y - 18},
                        {randomFloat() * 10 - 5, randomFloat() * 10 - 5}
                };

                simulator.boids.insert(simulator.boids.end(), boid);
            }
        }
    }
}

Application::~Application() {
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyTexture(boid_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}