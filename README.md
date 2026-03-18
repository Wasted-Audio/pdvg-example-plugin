# Example plugin for PDVG

This example plugin showcases how [PDVG](https://github.com/Wasted-Audio/PDVG) implements various plugdata UI objects in order to match with very similar output drawing style and user interaction.

The plugin itself does not do any DSP processing and is only used to build the GUI. All widgets are placed and configured by hand, based on the `example.pd` patch file coordinates and configuration.

## Instructions

To build the project:

```bash
git clone https://github.com/Wasted-Audio/pdvg-example-plugin.git
cd pdvg-example-plugin/
git submodule update --init --recursive
make -j
```

To test the build either use a compatible plugin host or run the jack standalone:

```bash
./bin/PDVGWidgetsExamplePlugin
```

## Comparison

Here we see a comparison of the graphics between plugdata (top) and the PDVG based DPF build (bottom):

![comparing plugdata (top) and PDVG (bottom) output](example.png)
