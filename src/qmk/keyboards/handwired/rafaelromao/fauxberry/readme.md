## FauxBerry
### A handwired unibody split keyboard.

![img](../../../../../../img/fauxberry.jpg)

### Build Details

FauxBerry is a handwired board built using a [RP2040](https://pt.aliexpress.com/item/1005004096147070.html) in a [FFKB](https://fingerpunch.xyz/product/faux-fox-keyboard) case.

This board has two encoders, a programmable LED and an OLED screen, used for layer and other statuses indication.
Some build pictures can be found [here](../../../../../../docs/fauxberry.md).

Parts:
- 34 MX switches
- 34 1u MX keycaps (MT3 3277 Ergodox Set).
- 36 keys [FFKB](https://fingerpunch.xyz/product/faux-fox-keyboard) case.
- [RP2040](https://pt.aliexpress.com/item/1005004096147070.html).
- [1n4148 diodes](https://pt.aliexpress.com/item/1005003540554760.html).
- [Angled pins](https://pt.aliexpress.com/item/1005004427303224.html).
- [24 AWG Wires](https://pt.aliexpress.com/item/32904950428.html).
- [Dupont cables](https://pt.aliexpress.com/item/1005004155181609.html).
- [M3 screws and spacers](https://pt.aliexpress.com/item/1005002581025420.html).
- [Rotary Encoders](https://pt.aliexpress.com/item/1005003532687682.html).
- [Rotary Encoder caps](https://pt.aliexpress.com/item/1005003527482683.html).
- [Rotary Encoder adapters](https://www.thingiverse.com/thing:3770166).
- [MX Hotswap sockets](https://pt.aliexpress.com/item/1005003873653184.html).
- [MX Hotswap socket holders](https://www.thingiverse.com/thing:3117549).
- [Zipf Kit](https://www.thingiverse.com/thing:5364986).
- [OLED Screen](https://youtu.be/NAUxTR4vGys). 

### QMK

#### Compile

`qmk compile -kb handwired/rafaelromao/fauxberry -km rafaelromao`

#### Flash

`qmk flash -kb handwired/rafaelromao/fauxberry -km rafaelromao`

## Resources

- [Home](https://github.com/rafaelromao/keyboards)
- [QMK Docs](https://docs.qmk.fm)
- [Keyboard Tester](https://config.qmk.fm/#/test)
