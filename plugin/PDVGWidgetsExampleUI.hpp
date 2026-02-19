/*
 * Copyright (C) 2026 Wasted Audio
 * SPDX-License-Identifier: ISC
*/

#include "DistrhoUI.hpp"
#include "DistrhoPluginInfo.h"
#include "nanovg.h"

#include "Background.hpp"
#include "Canvas.hpp"
#include "Slider.hpp"
#include "Toggle.hpp"
#include "Radio.hpp"
#include "Label.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class PDVGWidgetsExampleUI : public UI,
                             public PDSliderEventHandler::Callback,
                             public PDToggleEventHandler::Callback,
                             public PDRadioEventHandler::Callback
{
public:
    PDVGWidgetsExampleUI();
    ~PDVGWidgetsExampleUI();

protected:
    void parameterChanged(uint32_t index, float value) override;
    void onNanoDisplay() override;
    void sliderDragStarted(SubWidget *const widget) override;
    void sliderDragFinished(SubWidget *const widget) override;
    void sliderValueChanged(SubWidget *const widget, float value) override;
    void switchClicked(SubWidget *const widget, bool down) override;
    void radioValueChanged(SubWidget *const widget, uint index) override;

private:
    ScopedPointer<PDBackground> subBackground;
    ScopedPointer<PDBackground> mainBackground;
    ScopedPointer<PDCanvas> subCanvas;
    ScopedPointer<PDCanvas> subCanvas2;
    ScopedPointer<PDCanvas> myCanvas;
    ScopedPointer<PDLabel> myComment;
    ScopedPointer<PDLabel> myComment2;
    ScopedPointer<PDSlider> mySlider;
    ScopedPointer<PDSlider> mySlider2;
    ScopedPointer<PDToggle> myToggle;
    ScopedPointer<PDRadio> myRadio;
    ScopedPointer<PDRadio> myRadio2;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PDVGWidgetsExampleUI)
};

END_NAMESPACE_DISTRHO
