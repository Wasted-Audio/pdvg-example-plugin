/*
 * Copyright (C) 2026 Wasted Audio
 * SPDX-License-Identifier: ISC
*/

#include "DistrhoUI.hpp"
#include "DistrhoPluginInfo.h"
#include "nanovg.h"

#include "PDVGWidgetsExampleUI.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

PDVGWidgetsExampleUI::PDVGWidgetsExampleUI()
    : UI(DISTRHO_UI_DEFAULT_WIDTH, DISTRHO_UI_DEFAULT_HEIGHT)
{

    const float width = getWidth();
    const float height = getHeight();
    const double scaleFactor = getScaleFactor();

    // vslider
    mySlider = new PDSlider(this, this);
    mySlider->setId(kSlider);
    mySlider->setSize(17 * scaleFactor, 128 * scaleFactor);
    mySlider->setAbsolutePos(160 * scaleFactor, 10 * scaleFactor);
    mySlider->setSliderArea(0, 0, 17 * scaleFactor, 128 * scaleFactor);
    mySlider->setStartPos(0 * scaleFactor, 128 * scaleFactor);
    mySlider->setEndPos(0 * scaleFactor, 0 * scaleFactor);
    mySlider->setInverted(true);
    mySlider->setColors(
        nvgRGBA(0x38, 0x38, 0x38, 0xFF),
        nvgRGBA(0x19, 0x19, 0x19, 0xFF),
        nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
    );

    // hslider
    mySlider2 = new PDSlider(this, this);
    mySlider2->setId(kSlider2);
    mySlider2->setSize(128 * scaleFactor, 17 * scaleFactor);
    mySlider2->setAbsolutePos(160 * scaleFactor, 160 * scaleFactor);
    mySlider2->setSliderArea(0, 0, 128 * scaleFactor, 17 * scaleFactor);
    mySlider2->setStartPos(0 * scaleFactor, 0 * scaleFactor);
    mySlider2->setEndPos(128 * scaleFactor, 0 * scaleFactor);
    mySlider2->setHorizontal();
    mySlider2->setColors(
        nvgRGBA(0x38, 0x38, 0x38, 0xFF),
        nvgRGBA(0x19, 0x19, 0x19, 0xFF),
        nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
    );

    // toggle
    myToggle = new PDToggle(this, this);
    myToggle->setId(kToggle);
    myToggle->setSize(25 * scaleFactor, 25 * scaleFactor);
    myToggle->setAbsolutePos(100 * scaleFactor, 100 * scaleFactor);
    myToggle->setColors(
        nvgRGBA(0x19, 0x19, 0x19, 0xFF),
        nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
    );

    // vradio
    myRadio = new PDRadio(this, this);
    myRadio->setId(kRadio);
    myRadio->setSize(20 * scaleFactor, 100 * scaleFactor);
    myRadio->setAbsolutePos(200 * scaleFactor, 200 * scaleFactor);
    myRadio->setStep(5);
    myRadio->setColors(
        nvgRGBA(0x19, 0x19, 0x19, 0xFF),
        nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
    );

    // hradio
    myRadio2 = new PDRadio(this, this);
    myRadio2->setId(kRadio2);
    myRadio2->setSize(160 * scaleFactor, 20 * scaleFactor);
    myRadio2->setAbsolutePos(250 * scaleFactor, 250 * scaleFactor);
    myRadio2->setStep(8);
    myRadio2->setHorizontal();
    myRadio2->setColors(
        nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF),
        nvgRGBA(0x19, 0x19, 0x19, 0xFF)
    );
}

PDVGWidgetsExampleUI::~PDVGWidgetsExampleUI()
{
}

void PDVGWidgetsExampleUI::onNanoDisplay()
{
    const float width = getWidth();
    const float height = getHeight();
    const double scaleFactor = getScaleFactor();

    auto bgColor = nvgRGBA(0x38, 0x38, 0x38, 0xFF);
    NVGcontext* nvg = getContext();
    NVGpaint p;
    memset(&p, 0, sizeof(p));
    nvgTransformIdentity(p.xform);

    p.innerColor = bgColor;
    p.outerColor = bgColor;
    nvgFillPaint(nvg, p);
    nvgBeginPath(nvg);
    nvgRect(nvg, 0, 0, width * scaleFactor, height * scaleFactor);
    nvgFill(nvg);
    nvgStroke(nvg);
}

void PDVGWidgetsExampleUI::parameterChanged(uint32_t index, float value)
{
    switch (index)
    {
    case kSlider:
        mySlider->setValue(value);
        break;
    case kSlider2:
        mySlider2->setValue(value);
        break;
    case kToggle:
        myToggle->setDown(static_cast<bool>(value));
        break;
    case kRadio:
        myRadio->setValue(value);
        break;
    case kRadio2:
        myRadio2->setValue(value);
        break;
    default:
        break;
    }
    repaint();
}

void PDVGWidgetsExampleUI::sliderDragStarted(SubWidget *const widget) {}
void PDVGWidgetsExampleUI::sliderDragFinished(SubWidget *const widget) {}
void PDVGWidgetsExampleUI::sliderValueChanged(SubWidget *const widget, float value)
{
    printf("value changed: %f\n", value);
    const uint id = widget->getId();
    setParameterValue(id, value);
}

void PDVGWidgetsExampleUI::switchClicked(SubWidget *const widget, bool down)
{
    printf("switch clicked: %d\n", down);
    const uint id = widget->getId();
    setParameterValue(id, static_cast<float>(down));
}

void PDVGWidgetsExampleUI::radioValueChanged(SubWidget *const widget, uint index)
{
    printf("radio clicked: %d\n", index);
    const uint id = widget->getId();
    setParameterValue(id, static_cast<float>(index));
}


UI *createUI()
{
    return new PDVGWidgetsExampleUI();
}

// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
