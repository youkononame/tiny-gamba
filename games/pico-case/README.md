# pico-case
> A CS2 case simulator written for the [Orpheus Pico](https://hack.club/pico)

> [!NOTE]
> Although this game is intended to be played on an Orpheus Pico using the built in I/O, the code could theoretically run on any [MicroPython](https://micropython.org/) compatible microcontroller. Additional parts and assembly would be required.

## How to Play
Press the builtin pushbutton to roll a skin.

Each colour on the neopixel LED corresponds to a CS2 skin rarity.

If the green LED lights up, the skin you have rolled is StatTrak.

## Odds
| Rarity            | Colour | Chance (%) | Chance (X in Y) |
| ----------------- | ------ | ---------- | --------------- |
| Mil-Spec          | Blue   | 79.92%     | 4 in 5          |
| Restricted        | Purple | 15.98%     | 1 in 6          |
| Classified        | Pink   | 3.2%       | 1 in 31         |
| Covert            | Red    | 0.64%      | 1 in 156        |
| Rare Special Item | Gold   | 0.26%      | 1 in 385        |

The odds of any given roll being StatTrak is **1 in 10**.
