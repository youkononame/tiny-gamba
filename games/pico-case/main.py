from machine import Pin
from neopixel import NeoPixel
from random import uniform, randint

colours = {
    (255, 218, 0): 0.26,
    (237, 73, 73): 0.9,
    (212, 42, 231): 4.1,
    (136, 72, 255): 20.08,
    (74, 105, 255): 100,
}


def get_random_colour():
    ticket = uniform(0, 100)
    for colour, rarity in colours.items():
        if ticket <= rarity:
            return colour

    return (0, 0, 0)


button = Pin(25, Pin.IN, Pin.PULL_UP)
neopixel_led = NeoPixel(Pin(24, Pin.OUT), 1)
led = Pin(23, Pin.OUT)


def roll(change):
    neopixel_led[0] = get_random_colour()
    neopixel_led.write()

    if randint(1, 10) == 1:
        led.on()
    else:
        led.off()


button.irq(handler=roll, trigger=Pin.IRQ_FALLING)

