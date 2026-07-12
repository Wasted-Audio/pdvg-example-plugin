/*
 * Copyright (C) 2026 Wasted Audio
 * SPDX-License-Identifier: ISC
*/
#include "DistrhoPlugin.hpp"

START_NAMESPACE_DISTRHO

class PDVGWidgetsExamplePlugin : public Plugin
{
public:
  PDVGWidgetsExamplePlugin()
      : Plugin(kParameterCount, 0, 0)
  {
  }

protected:
  const char *getLabel() const override
  {
    return "PDVGWidgetsDemo";
  }

  const char *getDescription() const override
  {
    return "Plugin to demonstrate PDVG widgets";
  }

  const char *getMaker() const override
  {
    return "Wasted Audio";
  }

  const char *getHomePage() const override
  {
    return "https://github.com/Wasted-Audio";
  }

  const char *getLicense() const override
  {
    return "ISC";
  }

  uint32_t getVersion() const override
  {
    return d_version(0, 0, 0);
  }

  int64_t getUniqueId() const override
  {
    return d_cconst('p', 'd', 'v', 'E');
  }

  void initParameter(uint32_t index, Parameter &parameter) override
  {
    switch (index)
    {
    case kSlider:
      parameter.name = "mySlider";
      parameter.symbol = "myslider";
      parameter.hints = kParameterIsAutomatable | kParameterIsLogarithmic;
      parameter.ranges.def = 3.0f;
      parameter.ranges.min = 0.001f;
      parameter.ranges.max = 10.0f;
      break;
    case kSlider2:
      parameter.name = "mySlider2";
      parameter.symbol = "myslider2";
      parameter.hints = kParameterIsAutomatable;
      parameter.ranges.def = 0.6f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 1.0f;
      break;
    case kToggle:
      parameter.name = "myToggle";
      parameter.symbol = "mytoggle";
      parameter.hints = kParameterIsAutomatable | kParameterIsBoolean;
      parameter.ranges.def = 0.0f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 1.0f;
      break;
    case kToggle2:
      parameter.name = "myToggle2";
      parameter.symbol = "mytoggle2";
      parameter.hints = kParameterIsAutomatable | kParameterIsBoolean;
      parameter.ranges.def = 1.0f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 1.0f;
      break;
    case kRadio:
      parameter.name = "myRadio";
      parameter.symbol = "myradio";
      parameter.hints = kParameterIsAutomatable;
      parameter.ranges.def = 3.0f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 4.0f;
      break;
    case kRadio2:
      parameter.name = "myRadio2";
      parameter.symbol = "myradio2";
      parameter.hints = kParameterIsAutomatable;
      parameter.ranges.def = 3.0f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 7.0f;
      break;
    case kNumber:
      parameter.name = "myNumber";
      parameter.symbol = "myNumber";
      parameter.hints = kParameterIsAutomatable;
      parameter.ranges.def = 666.6f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 1000.0f;
      break;
    case kFloat:
      parameter.name = "myFloat";
      parameter.symbol = "myFloat";
      parameter.hints = kParameterIsAutomatable;
      parameter.ranges.def = 3.333f;
      parameter.ranges.min = -10.0f;
      parameter.ranges.max = 10.0f;
      break;
    case kKnob:
      parameter.name = "myKnob";
      parameter.symbol = "myKnob";
      parameter.hints = kParameterIsAutomatable;
      parameter.ranges.def = 99.0f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 127.0f;
      break;
    case kKnob2:
      parameter.name = "myKnob2";
      parameter.symbol = "myKnob2";
      parameter.hints = kParameterIsAutomatable;
      parameter.ranges.def = 99.0f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 127.0f;
      break;
    case kKnob3:
      parameter.name = "myKnob3";
      parameter.symbol = "myKnob3";
      parameter.hints = kParameterIsAutomatable | kParameterIsLogarithmic;
      parameter.ranges.def = 99.0f;
      parameter.ranges.min = 1.0f;
      parameter.ranges.max = 127.0f;
      break;
    case kBang:
      parameter.name = "myBang";
      parameter.symbol = "myBang";
      parameter.hints = kParameterIsAutomatable | kParameterIsTrigger;
      parameter.ranges.def = 0.0f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 1.0f;
      break;
    case kPopmenu:
      parameter.name = "myPopmenu";
      parameter.symbol = "myPopmenu";
      parameter.hints = kParameterIsAutomatable;
      parameter.ranges.def = 0.0f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 3.0f;
      break;
    default:
      break;
    }
  }

  float getParameterValue(uint32_t index) const override
  {
    float value = 0.0f;
    switch (index)
    {
    case kSlider:
      value = fSlider;
      break;
    case kSlider2:
      value = fSlider2;
      break;
    case kToggle:
      value = fToggle;
      break;
    case kToggle2:
      value = fToggle2;
      break;
    case kRadio:
      value = fRadio;
      break;
    case kRadio2:
      value = fRadio2;
      break;
    case kNumber:
      value = fNumber;
      break;
    case kFloat:
      value = fFloat;
      break;
    case kKnob:
      value = fKnob;
      break;
    case kKnob2:
      value = fKnob2;
      break;
    case kKnob3:
      value = fKnob3;
      break;
    case kPopmenu:
      value = fPopmenu;
      break;
    default:
      break;
    }
    return value;
  }

  void setParameterValue(uint32_t index, float value) override
  {
    switch (index)
    {
    case kSlider:
      fSlider = value;
      break;
    case kSlider2:
      fSlider2 = value;
      break;
    case kToggle:
      fToggle = value;
      break;
    case kToggle2:
      fToggle2 = value;
      break;
    case kRadio:
      fRadio = value;
      break;
    case kRadio2:
      fRadio2 = value;
      break;
    case kNumber:
      fNumber = value;
      break;
    case kFloat:
      fFloat = value;
      break;
    case kKnob:
      fKnob = value;
      break;
    case kKnob2:
      fKnob2 = value;
      break;
    case kKnob3:
      fKnob3 = value;
      break;
    case kPopmenu:
      fPopmenu = value;
      break;
    default:
      break;
    }
  }

  void run(const float **inputs, float **outputs, uint32_t frames) override
  {
    if (outputs[0] != inputs[0])
      std::memcpy(outputs[0], inputs[0], sizeof(float) * frames);
  }

private:
  float fSlider;
  float fSlider2;
  float fToggle;
  float fToggle2;
  float fRadio;
  float fRadio2;
  float fNumber;
  float fFloat;
  float fKnob;
  float fKnob2;
  float fKnob3;
  float fBang;
  float fPopmenu;

  DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PDVGWidgetsExamplePlugin)
};

Plugin *createPlugin()
{
  return new PDVGWidgetsExamplePlugin();
}

END_NAMESPACE_DISTRHO
