#pragma once

#include <vector>

#include "imgui.h"

#define MAX_FRAME_HISTORY 300

class ImFramerateGraph {
public:
    inline void Draw(float fps) {
        float width = ImGui::GetWindowWidth() - (ImGui::GetStyle().WindowPadding.x * 2);

        if (frames.size() > MAX_FRAME_HISTORY) {
            frames.erase(frames.begin());
        }
        frames.insert(frames.end(), fps);

        ImGui::PlotLines("", &frames[0], frames.size(), 0, NULL, 0.0f, 60.0f, ImVec2(width, 100));
    }

private:
    std::vector<float> frames;
};

