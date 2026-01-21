/*
 * Copyright (C) 2026 Wasted Audio
 * SPDX-License-Identifier: ISC
*/

#include "DistrhoUI.hpp"
#include "DistrhoPluginInfo.h"
#include "nanovg.h"

#include "Slider.hpp"
#include "Toggle.hpp"
#include "Radio.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class PDVGWidgetsExampleUI : public UI,
                             public PDSliderEventHandler::Callback,
                             public PDToggleEventHandler::Callback,
                             public PDRadioEventHandler::Callback
{
public:
    static const uint kInitialWidth = 600;
    static const uint kInitialHeight = 350;

    PDVGWidgetsExampleUI()
        : UI(kInitialWidth, kInitialHeight),
          mySlider(this, this),
          mySlider2(this, this),
          myToggle(this, this),
          myRadio(this, this),
          myRadio2(this, this)
    {
        // vslider
        mySlider.setId(kSlider);
        mySlider.setSize(17, 128);
        mySlider.setAbsolutePos(160, 10);
        mySlider.setSliderArea(0, 0, 17, 128);
        mySlider.setStartPos(0, 128);
        mySlider.setEndPos(0, 0);
        mySlider.setInverted(true);
        mySlider.setColors(
            nvgRGBA(0x38, 0x38, 0x38, 0xFF),
            nvgRGBA(0x19, 0x19, 0x19, 0xFF),
            nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
        );

        // hslider
        mySlider2.setId(kSlider2);
        mySlider2.setSize(128, 17);
        mySlider2.setAbsolutePos(160, 160);
        mySlider2.setSliderArea(0, 0, 128, 17);
        mySlider2.setStartPos(0, 0);
        mySlider2.setEndPos(128, 0);
        mySlider2.setHorizontal();
        mySlider2.setColors(
            nvgRGBA(0x38, 0x38, 0x38, 0xFF),
            nvgRGBA(0x19, 0x19, 0x19, 0xFF),
            nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
        );

        // toggle
        myToggle.setId(kToggle);
        myToggle.setSize(25, 25);
        myToggle.setAbsolutePos(100, 100);
        myToggle.setColors(
            nvgRGBA(0x19, 0x19, 0x19, 0xFF),
            nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
        );

        // vradio
        myRadio.setId(kRadio);
        myRadio.setSize(20, 100);
        myRadio.setAbsolutePos(200, 200);
        myRadio.setStep(5);
        myRadio.setColors(
            nvgRGBA(0x19, 0x19, 0x19, 0xFF),
            nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
        );

        // hradio
        myRadio2.setId(kRadio);
        myRadio2.setSize(160, 20);
        myRadio2.setAbsolutePos(250, 250);
        myRadio2.setStep(8);
        myRadio2.setHorizontal();
        myRadio2.setColors(
            nvgRGBA(0x19, 0x19, 0x19, 0xFF),
            nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
        );
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
        case kToggle:
            myToggle.setDown(static_cast<bool>(value));
            break;
        default:
            break;
        }
        repaint();
    }

    void onNanoDisplay() override
    {
        auto bgColor = nvgRGBA(0x38, 0x38, 0x38, 0xFF);
        NVGcontext* nvg = getContext();
        NVGpaint p;
        memset(&p, 0, sizeof(p));
        nvgTransformIdentity(p.xform);

        p.innerColor = bgColor;
        p.outerColor = bgColor;
        nvgFillPaint(nvg, p);
        nvgBeginPath(nvg);
        nvgRect(nvg, 0, 0, kInitialWidth, kInitialHeight);
        nvgFill(nvg);
        nvgStroke(nvg);
    }

    void sliderDragStarted(SubWidget *const widget) override {}
    void sliderDragFinished(SubWidget *const widget) override {}
    void sliderValueChanged(SubWidget *const widget, float value) override
    {
        printf("value changed: %f\n", value);
        const uint id = widget->getId();
        setParameterValue(id, value);
    }

    void switchClicked(SubWidget *const widget, bool down)
    {
        printf("switch clicked: %d\n", down);
        const uint id = widget->getId();
        setParameterValue(id, static_cast<float>(down));
    }

    void radioValueChanged(SubWidget *const widget, uint index)
    {
        printf("radio clicked: %d\n", index);
        const uint id = widget->getId();
        setParameterValue(id, static_cast<float>(index));
    }

private:
    Slider mySlider;
    Slider mySlider2;
    Toggle myToggle;
    Radio myRadio;
    Radio myRadio2;

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
