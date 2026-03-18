NAME = PDVGWidgetsExamplePlugin
FILES_DSP = $(filter-out plugin/PDVGWidgetsExampleUI.cpp, $(wildcard plugin/*.cpp))
FILES_DSP += $(wildcard *.c)
FILES_UI = plugin/PDVGWidgetsExampleUI.cpp
FILES_UI += $(wildcard dep/pdvg/src/*.cpp)
FILES_UI +=	dep/pdvg/src/Fonts/*.cpp


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
TARGETS += clap
TARGETS += jack


all: $(TARGETS)
