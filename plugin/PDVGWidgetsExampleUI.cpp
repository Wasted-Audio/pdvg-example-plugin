/*
 * Copyright (C) 2026 Wasted Audio
 * SPDX-License-Identifier: ISC
*/

#include "DistrhoUI.hpp"
#include "DistrhoPluginInfo.h"

#include "Slider.hpp"
#include "nanovg.h"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class PDVGWidgetsExampleUI : public UI,
                             public PDSliderEventHandler::Callback
{
public:
    static const uint kInitialWidth = 600;
    static const uint kInitialHeight = 350;

    PDVGWidgetsExampleUI()
        : UI(kInitialWidth, kInitialHeight),
          mySlider(this, this),
          mySlider2(this, this)
    {
        // vslider
        mySlider.setId(kSlider);
        mySlider.setSize(17, 128);
        mySlider.setAbsolutePos(160, 10);
        mySlider.setSliderArea(0, 0, 17, 128);
        mySlider.setStartPos(0, 128);
        mySlider.setEndPos(0, 0);
        mySlider.setInverted(true);

        // hslider
        mySlider2.setId(kSlider2);
        mySlider2.setSize(128, 17);
        mySlider2.setAbsolutePos(160, 160);
        mySlider2.setSliderArea(0, 0, 128, 17);
        mySlider2.setStartPos(0, 0);
        mySlider2.setEndPos(128, 0);
        mySlider2.setHorizontal();
    };

protected:

    void parameterChanged(uint32_t index, float value) override
    {
        switch (index)
        {
        case kSlider:
            mySlider.setValue(value);
            break;
        case kSlider2:
            mySlider2.setValue(value);
            break;
        default:
            break;
        }
        repaint();
    }

    void onNanoDisplay() override
    {
        auto bgColour = nvgRGBA(0x38, 0x38, 0x38, 0xFF);
        NVGcontext* ctx = getContext();
        NVGpaint p;
        memset(&p, 0, sizeof(p));
        nvgTransformIdentity(p.xform);

        p.innerColor = bgColour;
        p.outerColor = bgColour;
        nvgFillPaint(ctx, p);
        nvgBeginPath(ctx);
        nvgRect(ctx, 0, 0, kInitialWidth, kInitialHeight);
        nvgFill(ctx);
        nvgStroke(ctx);
    }

    void sliderDragStarted(SubWidget *const widget) override {}
    void sliderDragFinished(SubWidget *const widget) override {}
    void sliderValueChanged(SubWidget *const widget, float value) override
    {
        printf("value changed: %f\n", value);
        const uint id = widget->getId();
        setParameterValue(id, value);
    }


private:
    Slider mySlider;
    Slider mySlider2;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PDVGWidgetsExampleUI)
};

/* ------------------------------------------------------------------------------------------------------------
 * UI entry point, called by DPF to create a new UI instance. */

UI *createUI()
{
    return new PDVGWidgetsExampleUI();
}

// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
