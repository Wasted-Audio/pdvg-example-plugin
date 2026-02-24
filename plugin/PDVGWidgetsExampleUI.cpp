/*
 * Copyright (C) 2026 Wasted Audio
 * SPDX-License-Identifier: ISC
*/

#include "DistrhoUI.hpp"
#include "DistrhoPluginInfo.h"
#include "nanovg.h"

#include "Common.hpp"
#include "PDVGWidgetsExampleUI.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

PDVGWidgetsExampleUI::PDVGWidgetsExampleUI()
    : UI(DISTRHO_UI_DEFAULT_WIDTH, DISTRHO_UI_DEFAULT_HEIGHT)
{

    const float width = getWidth();
    const float height = getHeight();
    const double scaleFactor = getScaleFactor();

    // mainpatch
    mainPatch = new PDMainpatch(this);
    mainPatch->setSize(width * scaleFactor, height * scaleFactor);

    // subpatch
    subPatch = new PDSubpatch(mainPatch);
    subPatch->setSize(200 * scaleFactor, 140 * scaleFactor);
    subPatch->setAbsolutePos(464 * scaleFactor, 190 * scaleFactor);
    subPatch->setColors(nvgRGBA(0x38, 0x38, 0x38, 0xFF));
    mainPatch->addManagedChild(subPatch);

    // subCanvas
    subCanvas = new PDCanvas(subPatch);
    subCanvas->setSize(136 * scaleFactor, 97 * scaleFactor);
    subCanvas->setAbsolutePos(-9 * scaleFactor, -13 * scaleFactor);
    subCanvas->setColors(nvgRGBA(0x00, 0x62, 0x04, 0xFF));

    // subCanvas2
    subCanvas2 = new PDCanvas(subPatch);
    subCanvas2->setSize(131 * scaleFactor, 102 * scaleFactor);
    subCanvas2->setAbsolutePos(89 * scaleFactor, 52* scaleFactor);
    subCanvas2->setColors(nvgRGBA(0x62, 0x0A, 0x00, 0xFF));

    // subsubpatch
    subsubPatch = new PDSubpatch(subPatch);
    subsubPatch->setSize(118 * scaleFactor, 75 * scaleFactor);
    subsubPatch->setAbsolutePos(53 * scaleFactor, 36 * scaleFactor);
    subsubPatch->setColors(nvgRGBA(0x38, 0x38, 0x38, 0xFF));
    subPatch->addManagedChild(subsubPatch);

    // subsubcanvas
    subsubCanvas = new PDCanvas(subsubPatch);
    subsubCanvas->setSize(163 * scaleFactor,131 * scaleFactor);
    subsubCanvas->setAbsolutePos(-20 * scaleFactor, -13 * scaleFactor);
    subsubCanvas->setColors(nvgRGBA(0x00, 0x08, 0x62, 0xFF));

    // toggle2
    myToggle2 = new PDToggle(subsubPatch, this);
    myToggle2->setId(kToggle2);
    myToggle2->setSize(25 * scaleFactor, 25 * scaleFactor);
    myToggle2->setAbsolutePos(49 * scaleFactor, 24 * scaleFactor);
    myToggle2->setColors(
        nvgRGBA(0x19, 0x19, 0x19, 0xFF),
        nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
    );
    subsubPatch->addManagedChild(myToggle2);

    // canvas
    myCanvas = new PDCanvas(mainPatch);
    myCanvas->setSize(269 * scaleFactor, 181 * scaleFactor);
    myCanvas->setAbsolutePos(75 * scaleFactor, 49 * scaleFactor);
    myCanvas->setColors(
        nvgRGBA(0x63, 0xFF, 0xA9, 0xFF)
    );
    myCanvas->setLabel("tester", nvgRGBA(0x70, 0x70, 0x70, 0xFF), 20 * scaleFactor, 12 * scaleFactor, 16 * scaleFactor);

    // comment
    myComment = new PDComment(mainPatch);
    std::string myCommentString = "test comment";
    myComment->setText(myCommentString);
    myComment->setColors(nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF));
    myComment->setAbsolutePos(45 * scaleFactor, 264 * scaleFactor);
    myComment->setSize(8 * std::string(myCommentString).length() * scaleFactor, 16 * scaleFactor);

    // comment wrapped
    myComment2 = new PDComment(mainPatch);
    std::string myComment2String = "comment verylongtextthatdoesnotfit wrapped";
    myComment2->setText(myComment2String);
    myComment2->setColors(nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF));
    myComment2->setAbsolutePos(428 * scaleFactor, 98 * scaleFactor);
    myComment2->setSize(8 * 13 * scaleFactor, 16 * scaleFactor);

    // vslider
    mySlider = new PDSlider(mainPatch, this);
    mySlider->setId(kSlider);
    mySlider->setSize(17 * scaleFactor, 128 * scaleFactor);
    mySlider->setAbsolutePos(160 * scaleFactor, 10 * scaleFactor);
    mySlider->setSliderArea(0, 0, 17 * scaleFactor, 128 * scaleFactor);
    mySlider->setStartPos(0 * scaleFactor, 128 * scaleFactor);
    mySlider->setEndPos(0 * scaleFactor, 0 * scaleFactor);
    mySlider->setInverted(true);
    mySlider->setRange(0.0001f, 10.0f);
    mySlider->setDefault(3.0f);
    mySlider->setUsingLogScale(true);
    mySlider->setSteadyOnClick(true);
    mySlider->setColors(
        nvgRGBA(0x38, 0x38, 0x38, 0xFF),
        nvgRGBA(0x19, 0x19, 0x19, 0xFF),
        nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
    );
    mainPatch->addManagedChild(mySlider);

    // hslider
    mySlider2 = new PDSlider(mainPatch, this);
    mySlider2->setId(kSlider2);
    mySlider2->setSize(128 * scaleFactor, 17 * scaleFactor);
    mySlider2->setAbsolutePos(160 * scaleFactor, 160 * scaleFactor);
    mySlider2->setSliderArea(0, 0, 128 * scaleFactor, 17 * scaleFactor);
    mySlider2->setStartPos(0 * scaleFactor, 0 * scaleFactor);
    mySlider2->setEndPos(128 * scaleFactor, 0 * scaleFactor);
    mySlider2->setHorizontal();
    mySlider2->setRange(0.0f, 1.0f);
    mySlider2->setDefault(0.6f);
    mySlider2->setColors(
        nvgRGBA(0x38, 0x38, 0x38, 0xFF),
        nvgRGBA(0x19, 0x19, 0x19, 0xFF),
        nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
    );
    mainPatch->addManagedChild(mySlider2);

    // toggle
    myToggle = new PDToggle(mainPatch, this);
    myToggle->setId(kToggle);
    myToggle->setSize(25 * scaleFactor, 25 * scaleFactor);
    myToggle->setAbsolutePos(100 * scaleFactor, 100 * scaleFactor);
    myToggle->setColors(
        nvgRGBA(0x19, 0x19, 0x19, 0xFF),
        nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
    );
    mainPatch->addManagedChild(myToggle);

    // vradio
    myRadio = new PDRadio(mainPatch, this);
    myRadio->setId(kRadio);
    myRadio->setSize(20 * scaleFactor, 100 * scaleFactor);
    myRadio->setAbsolutePos(200 * scaleFactor, 200 * scaleFactor);
    myRadio->setStep(5);
    myRadio->setColors(
        nvgRGBA(0x19, 0x19, 0x19, 0xFF),
        nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF)
    );
    mainPatch->addManagedChild(myRadio);

    // hradio
    myRadio2 = new PDRadio(mainPatch, this);
    myRadio2->setId(kRadio2);
    myRadio2->setSize(160 * scaleFactor, 20 * scaleFactor);
    myRadio2->setAbsolutePos(250 * scaleFactor, 250 * scaleFactor);
    myRadio2->setStep(8);
    myRadio2->setHorizontal();
    myRadio2->setColors(
        nvgRGBA(0xFF, 0xFF, 0xFF, 0xFF),
        nvgRGBA(0x19, 0x19, 0x19, 0xFF)
    );
    myRadio2->setLabel("hradio label", nvgRGBA(0xFF, 0x00, 0x00, 0xFF), 0 * scaleFactor, 0 * scaleFactor, 12 * scaleFactor);
    mainPatch->addManagedChild(myRadio2);

    // number
    myNumber = new PDNumber(mainPatch, this);
    myNumber->setId(kNumber);
    myNumber->setSize(8 * (2 + 4) * scaleFactor, (2 + 16) * scaleFactor);
    myNumber->setAbsolutePos(272 * scaleFactor, 68 * scaleFactor);
    myNumber->setColors(
        nvgRGBA(0x19, 0x19, 0x19, 0xFF),
        nvgRGBA(0x38, 0x38, 0x38, 0xFF),
        nvgRGBA(0xFF, 0xAC, 0xAB, 0xFF)
    );
    mainPatch->addManagedChild(myNumber);

    // float
    myFloat = new PDFloat(mainPatch, this);
    myFloat->setId(kFloat);
    myFloat->setSize(8 * 5 * scaleFactor, (6 + 12) * scaleFactor);
    myFloat->setAbsolutePos(272 * scaleFactor, 100 * scaleFactor);
    myFloat->setColors(
        nvgRGBA(0x19, 0x19, 0x19, 0xFF),
        nvgRGBA(0x38, 0x38, 0x38, 0xFF),
        nvgRGBA(0xFF, 0xAC, 0xAB, 0xFF)
    );
    mainPatch->addManagedChild(myFloat);
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

    nvgFillColor(nvg, bgColor);
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
    case kToggle2:
        myToggle2->setDown(static_cast<bool>(value));
        break;
    case kRadio:
        myRadio->setValue(value);
        break;
    case kRadio2:
        myRadio2->setValue(value);
        break;
    case kNumber:
        myNumber->setValue(value);
        break;
    case kFloat:
        myFloat->setValue(value);
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

void PDVGWidgetsExampleUI::numberValueChanged(SubWidget *const widget, float value)
{
    printf("number value changed: %f\n", value);
    const uint id = widget->getId();
    setParameterValue(id, value);
}


UI *createUI()
{
    return new PDVGWidgetsExampleUI();
}

// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
