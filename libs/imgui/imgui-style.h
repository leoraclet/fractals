#include "imgui.h"

void setImGuiStyle()
{
    ImGui::StyleColorsDark();
    ImGuiIO &io = ImGui::GetIO();
    ImGuiStyle &style = ImGui::GetStyle();

    // ImGui Flags
    //io.ConfigFlags |= ImGuiWindowFlags_AlwaysAutoResize;
    //io.ConfigFlags |= ImGuiWindowFlags_NoResize;

    // ImGui Style
    style.Colors[ImGuiCol_Border]                 = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_Button]                 = ImVec4(0.11f, 0.12f, 0.15f, 1.00f);
    style.Colors[ImGuiCol_ButtonActive]           = ImVec4(0.13f, 0.15f, 0.18f, 1.00f);
    style.Colors[ImGuiCol_ButtonHovered]          = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_CheckMark]              = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_ChildBg]                = ImVec4(0.16f, 0.17f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_COUNT]                  = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_DragDropTarget]         = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_FrameBg]                = ImVec4(0.11f, 0.12f, 0.15f, 1.00f);
    style.Colors[ImGuiCol_FrameBgActive]          = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_Header]                 = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_HeaderActive]           = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_HeaderHovered]          = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_MenuBarBg]              = ImVec4(0.11f, 0.12f, 0.15f, 1.00f);
    style.Colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.11f, 0.12f, 0.15f, 1.00f);
    style.Colors[ImGuiCol_NavHighlight]           = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(0.10f, 0.50f, 1.00f, 0.30f);
    style.Colors[ImGuiCol_PlotHistogram]          = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_PlotLines]              = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered]       = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_PopupBg]                = ImVec4(0.16f, 0.17f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_ResizeGrip]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.30f, 0.33f, 0.37f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.30f, 0.33f, 0.37f, 1.00f);
    style.Colors[ImGuiCol_Separator]              = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_SeparatorActive]        = ImVec4(0.30f, 0.33f, 0.37f, 1.00f);
    style.Colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.30f, 0.33f, 0.37f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab]             = ImVec4(1.00f, 1.00f, 1.00f, 0.25f);
    style.Colors[ImGuiCol_SliderGrabActive]       = ImVec4(1.00f, 1.00f, 1.00f, 0.55f);
    style.Colors[ImGuiCol_Tab]                    = ImVec4(0.16f, 0.17f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_TabActive]              = ImVec4(0.34f, 0.36f, 0.40f, 1.00f);
    style.Colors[ImGuiCol_TabHovered]             = ImVec4(0.24f, 0.27f, 0.31f, 1.00f);
    style.Colors[ImGuiCol_TableBorderLight]       = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_TableRowBgAlt]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_TabUnfocused]           = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.34f, 0.36f, 0.40f, 1.00f);
    style.Colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_TextDisabled]           = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.26f, 0.29f, 0.34f, 1.00f);
    style.Colors[ImGuiCol_TitleBg]                = ImVec4(0.21f, 0.24f, 0.28f, 1.00f);
    style.Colors[ImGuiCol_TitleBgActive]          = ImVec4(0.11f, 0.12f, 0.15f, 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.21f, 0.24f, 0.28f, 1.00f);
    style.Colors[ImGuiCol_WindowBg]               = ImVec4(0.16f, 0.17f, 0.20f, 1.00f);

    style.TabRounding        = 7.00f;
    style.GrabRounding       = 7.00f;
    style.ChildRounding      = 7.00f;
    style.FrameRounding      = 7.00f;
    style.PopupRounding      = 7.00f;
    style.WindowRounding     = 7.00f;
    style.ScrollbarRounding  = 7.00f;
    style.IndentSpacing      = 6.00f;
    style.ScrollbarSize      = 12.0f;
    style.WindowTitleAlign.x = 0.50f;
    style.FrameBorderSize    = 0.00f;
    style.WindowBorderSize   = 1.00f;
    style.WindowPadding      = ImVec2(15, 25);
    style.FramePadding       = ImVec2(7, 7);
    style.ItemSpacing        = ImVec2(5, 5);
    style.ItemInnerSpacing   = ImVec2(1, 1);
    style.TouchExtraPadding  = ImVec2(0, 0);
}