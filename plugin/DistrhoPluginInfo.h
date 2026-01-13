#pragma once

#define DISTRHO_PLUGIN_BRAND "Wasted Audio"
#define DISTRHO_PLUGIN_NAME "PDVG Widgets Demo"
#define DISTRHO_PLUGIN_URI "https://wasted.audio/software/pdvg-widgets-demo"

#define DISTRHO_PLUGIN_HAS_UI 1
#define DISTRHO_PLUGIN_IS_RT_SAFE 1
#define DISTRHO_PLUGIN_NUM_INPUTS 2
#define DISTRHO_PLUGIN_NUM_OUTPUTS 2
#define DISTRHO_UI_USE_NANOVG 1

enum Parameters
{
    kSlider,
    kSlider2,
    kParameterCount
};
