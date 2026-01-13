NAME = PDVGWidgetsExamplePlugin
FILES_DSP = $(filter-out PDVGWidgetsExampleUI.cpp, $(wildcard plugin/*.cpp))
FILES_DSP += $(wildcard *.c)
FILES_UI = plugin/PDVGWidgetsExampleUI.cpp \
	dep/pdvg/src/ExtraEventHandlers.cpp \
	dep/pdvg/src/Slider.cpp \
	dep/pdvg/src/Toggle.cpp


DPF_TARGET_DIR = bin
DPF_BUILD_DIR = build
DPF_PATH = dep/dpf

include dep/dpf/Makefile.plugins.mk

BASE_FLAGS += -Iplugin
BASE_FLAGS += -Idep/pdvg/
BASE_FLAGS += -Idep/dpf/dgl/src/nanovg

BUILD_C_FLAGS += -Wno-unused-parameter -std=c11 -fno-strict-aliasing -pthread
BUILD_CXX_FLAGS += -Wno-unused-parameter -fno-strict-aliasing -pthread
LINK_FLAGS += -pthread

TARGETS += lv2_sep
TARGETS += vst3
TARGETS += jack


all: $(TARGETS)
