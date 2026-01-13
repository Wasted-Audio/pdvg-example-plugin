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
      parameter.hints = kParameterIsAutomable;
      parameter.ranges.def = 0.5f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 1.0f;
      break;
    case kSlider2:
      parameter.name = "mySlider2";
      parameter.symbol = "myslider2";
      parameter.hints = kParameterIsAutomable;
      parameter.ranges.def = 0.5f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 1.0f;
      break;
    case kToggle:
      parameter.name = "myToggle";
      parameter.symbol = "mytoggle";
      parameter.hints = kParameterIsAutomable;
      parameter.ranges.def = 0.0f;
      parameter.ranges.min = 0.0f;
      parameter.ranges.max = 1.0f;
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

  DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PDVGWidgetsExamplePlugin)
};

Plugin *createPlugin()
{
  return new PDVGWidgetsExamplePlugin();
}

END_NAMESPACE_DISTRHO
