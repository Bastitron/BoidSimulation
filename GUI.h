#pragma once

namespace GUI {
    void Draw(Application* instance) {
        ImGui::Begin("Controller");

        ImGui::Text("Application average : %.3f ms/frame (%.1f FPS)", 1000.0f / instance->io->Framerate, instance->io->Framerate);

        instance->framerateGraph.Draw(instance->io->Framerate);

        ImGui::Text("Renderer : %s", instance->info.name);
        ImGui::Separator();
        ImGui::Text("Boid amount : %zu", instance->simulator.boids.size());

        ImGui::Separator();

        if (ImGui::CollapsingHeader("Configuration")) {
            float dummy = 1;

            ImGui::SliderFloat("Separation", &instance->configuration.separation_force, 0, .25);
            ImGui::SliderFloat("Alignment", &instance->configuration.alignment_force, 0, .25);
            ImGui::SliderFloat("Cohesion", &instance->configuration.cohesion_force, 0, .25);
            ImGui::Separator();
            ImGui::SliderFloat("Max speed", &instance->configuration.maximal_speed, 0, 50);
            ImGui::SliderFloat("Visual range", &instance->configuration.visual_range, 0, 500);
            ImGui::SliderFloat("Boid personal space", &instance->configuration.boid_margin, 0, 500);
            if (ImGui::Button("Reset to default")) {
                instance->configuration = SimulationConfiguration();
            }
        }

        ImGui::Separator();
        if (ImGui::Button("Reset")) {
            instance->simulator.Repopulate(instance->reset_boid_count, instance->window_width, instance->window_height);
        }
        ImGui::SameLine();
        ImGui::SliderInt("Boid amount", &instance->reset_boid_count, 0, 5000);

        ImGui::End();
        ImGui::Render();
    }
}