/*
 * Copyright (C) 2026 Wasted Audio
 * SPDX-License-Identifier: ISC
*/

#include "DistrhoUI.hpp"
#include "DistrhoPluginInfo.h"
#include "nanovg.h"

#include "pdvg.hpp"


START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class PDVGWidgetsExampleUI : public UI,
                             public PDSliderEventHandler::Callback,
                             public PDToggleEventHandler::Callback,
                             public PDRadioEventHandler::Callback,
                             public PDNumberEventHandler::Callback,
                             public PDKnobEventHandler::Callback,
                             public PDBangEventHandler::Callback,
                             public PDPopmenuEventHandler::Callback
{
public:
    PDVGWidgetsExampleUI();
    ~PDVGWidgetsExampleUI();

protected:
    void parameterChanged(uint32_t index, float value) override;
    void onNanoDisplay() override;
    void sliderValueChanged(SubWidget *const widget, float value) override;
    void switchClicked(SubWidget *const widget, bool down) override;
    void bangClicked(SubWidget *const widget) override;
    void radioValueChanged(SubWidget *const widget, uint index) override;
    void numberValueChanged(SubWidget *const widget, float value) override;
    void knobValueChanged(SubWidget *const widget, float value) override;
    void popmenuClicked(SubWidget *const widget, uint index) override;

private:
    ScopedPointer<PDMainpatch> mainPatch;
    ScopedPointer<PDSubpatch> subPatch;
    ScopedPointer<PDCanvas> subCanvas;
    ScopedPointer<PDCanvas> subCanvas2;
    ScopedPointer<PDSubpatch> subsubPatch;
    ScopedPointer<PDCanvas> subsubCanvas;
    ScopedPointer<PDCanvas> myCanvas;
    ScopedPointer<PDComment> myComment;
    ScopedPointer<PDComment> myComment2;
    ScopedPointer<PDSlider> mySlider;
    ScopedPointer<PDSlider> mySlider2;
    ScopedPointer<PDToggle> myToggle;
    ScopedPointer<PDToggle> myToggle2;
    ScopedPointer<PDRadio> myRadio;
    ScopedPointer<PDRadio> myRadio2;
    ScopedPointer<PDNumber> myNumber;
    ScopedPointer<PDFloat> myFloat;
    ScopedPointer<PDKnob> myKnob;
    ScopedPointer<PDKnob> myKnob2;
    ScopedPointer<PDKnob> myKnob3;
    ScopedPointer<PDBang> myBang;
    ScopedPointer<PDPopmenu> myPopmenu;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PDVGWidgetsExampleUI)
};

END_NAMESPACE_DISTRHO
