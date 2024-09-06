#pragma once

#include <imgui.h>

namespace ImSketch {

    void Setup() {
        // ImSketch style from ImThemes
        ImGuiStyle &style = ImGui::GetStyle();

        style.Alpha = 1.0f;
        style.DisabledAlpha = 0.2000000029802322f;
        style.WindowPadding = ImVec2(20.0f, 20.0f);
        style.WindowRounding = 0.0f;
        style.WindowBorderSize = 1.0f;
        style.WindowMinSize = ImVec2(20.0f, 32.0f);
        style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
        style.WindowMenuButtonPosition = ImGuiDir_Left;
        style.ChildRounding = 5.0f;
        style.ChildBorderSize = 1.0f;
        style.PopupRounding = 5.0f;
        style.PopupBorderSize = 1.0f;
        style.FramePadding = ImVec2(20.0f, 5.0f);
        style.FrameRounding = 5.0f;
        style.FrameBorderSize = 1.0f;
        style.ItemSpacing = ImVec2(5.0f, 5.0f);
        style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
        style.CellPadding = ImVec2(5.0f, 5.0f);
        style.IndentSpacing = 5.0f;
        style.ColumnsMinSpacing = 0.0f;
        style.ScrollbarSize = 5.699999809265137f;
        style.ScrollbarRounding = 5.0f;
        style.GrabMinSize = 5.0f;
        style.GrabRounding = 5.0f;
        style.TabRounding = 5.0f;
        style.TabBorderSize = 1.0f;
        style.TabMinWidthForCloseButton = 0.0f;
        style.ColorButtonPosition = ImGuiDir_Left;
        style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
        style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

        style.Colors[ImGuiCol_Text] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
        style.Colors[ImGuiCol_TextDisabled] = ImVec4(9.999918120229268e-07f, 9.999899930335232e-07f,
                                                     9.999999974752427e-07f, 0.7768239974975586f);
        style.Colors[ImGuiCol_WindowBg] = ImVec4(0.9372549057006836f, 0.9372549057006836f, 0.9372549057006836f, 1.0f);
        style.Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
        style.Colors[ImGuiCol_PopupBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.9800000190734863f);
        style.Colors[ImGuiCol_Border] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
        style.Colors[ImGuiCol_BorderShadow] = ImVec4(9.999999974752427e-07f, 9.999899930335232e-07f,
                                                     9.999899930335232e-07f, 0.0f);
        style.Colors[ImGuiCol_FrameBg] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                       1.0f);
        style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                      1.0f);
        style.Colors[ImGuiCol_TitleBg] = ImVec4(0.95686274766922f, 0.95686274766922f, 0.95686274766922f, 1.0f);
        style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.8196078538894653f, 0.8196078538894653f, 0.8196078538894653f,
                                                      1.0f);
        style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.0f, 1.0f, 1.0f, 0.5099999904632568f);
        style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.8588235378265381f, 0.8588235378265381f, 0.8588235378265381f, 1.0f);
        style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.9764705896377563f, 0.9764705896377563f, 0.9764705896377563f,
                                                    0.5299999713897705f);
        style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.686274528503418f, 0.686274528503418f, 0.686274528503418f,
                                                      0.800000011920929f);
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.4862745106220245f, 0.4862745106220245f,
                                                             0.4862745106220245f, 0.800000011920929f);
        style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.4862745106220245f, 0.4862745106220245f,
                                                            0.4862745106220245f, 1.0f);
        style.Colors[ImGuiCol_CheckMark] = ImVec4(9.999899930335232e-07f, 9.999946541938698e-07f,
                                                  9.999999974752427e-07f, 1.0f);
        style.Colors[ImGuiCol_SliderGrab] = ImVec4(9.999899930335232e-07f, 9.999943131333566e-07f,
                                                   9.999999974752427e-07f, 1.0f);
        style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(9.999899930335232e-07f, 9.999945405070321e-07f,
                                                         9.999999974752427e-07f, 1.0f);
        style.Colors[ImGuiCol_Button] = ImVec4(0.9999899864196777f, 0.9999945759773254f, 1.0f, 1.0f);
        style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                      1.0f);
        style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                     1.0f);
        style.Colors[ImGuiCol_Header] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f, 1.0f);
        style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                      1.0f);
        style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                     1.0f);
        style.Colors[ImGuiCol_Separator] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f, 1.0f);
        style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                         1.0f);
        style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                        1.0f);
        style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f, 1.0f);
        style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                          1.0f);
        style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                         1.0f);
        style.Colors[ImGuiCol_Tab] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f, 1.0f);
        style.Colors[ImGuiCol_TabHovered] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f, 1.0f);
        style.Colors[ImGuiCol_TabActive] = ImVec4(0.9999899864196777f, 1.0f, 0.9999939203262329f, 1.0f);
        style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                     1.0f);
        style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.8235294222831726f, 0.8156862854957581f,
                                                           0.8588235378265381f, 1.0f);
        style.Colors[ImGuiCol_PlotLines] = ImVec4(9.999999974752427e-07f, 9.999899930335232e-07f,
                                                  9.999899930335232e-07f, 1.0f);
        style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(9.999999974752427e-07f, 9.999911299019004e-07f,
                                                         9.999899930335232e-07f, 1.0f);
        style.Colors[ImGuiCol_PlotHistogram] = ImVec4(9.999999974752427e-07f, 9.99997837425326e-07f,
                                                      9.999899930335232e-07f, 1.0f);
        style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.8235294222831726f, 0.8156862854957581f,
                                                             0.8588235378265381f, 1.0f);
        style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                      1.0f);
        style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                          1.0f);
        style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                         1.0f);
        style.Colors[ImGuiCol_TableRowBg] = ImVec4(1.0f, 0.9999899864196777f, 0.9999899864196777f, 1.0f);
        style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(0.8232818841934204f, 0.8150403499603271f, 0.8588235378265381f,
                                                      0.4980392158031464f);
        style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                       1.0f);
        style.Colors[ImGuiCol_DragDropTarget] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                       1.0f);
        style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.8235294222831726f, 0.8156862854957581f, 0.8588235378265381f,
                                                     1.0f);
        style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.6980392336845398f, 0.6980392336845398f,
                                                              0.6980392336845398f, 0.699999988079071f);
        style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.8232818841934204f, 0.8150403499603271f, 0.8588235378265381f,
                                                          0.4980392158031464f);
        style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.8232818841934204f, 0.8150403499603271f, 0.8588235378265381f,
                                                         0.4980392158031464f);
    }
}