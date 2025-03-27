constexpr uint8_t PIEZO_PIN = 13;
constexpr uint8_t SWITCH_PIN = A0;

// The amount of values within this range should be divisible by LED_COUNT
constexpr uint8_t MIN_CYCLES = 27;
constexpr uint8_t MAX_CYCLES = 45;

constexpr uint8_t LED_PINS[]{12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
constexpr uint8_t LED_COUNT = sizeof(LED_PINS) / sizeof(uint8_t);

void cycle_led() {
  static int last_led_index = 0;

  digitalWrite(LED_PINS[last_led_index], LOW);

  last_led_index = ++last_led_index % LED_COUNT;

  digitalWrite(LED_PINS[last_led_index], HIGH);
}


void setup() {
  pinMode(SWITCH_PIN, INPUT);
  pinMode(PIEZO_PIN, OUTPUT);
  
  for(uint8_t i = 0; i < LED_COUNT; ++i) {
    pinMode(LED_PINS[i], OUTPUT);
  }

  randomSeed(analogRead(1));
}

void loop() {
  if(digitalRead(SWITCH_PIN) == HIGH) {
    int pre_cycles = random(LED_COUNT * 3, LED_COUNT * 4);
    int cycles = random(MIN_CYCLES, MAX_CYCLES);
    int base_delay = random(1000, 2000);

    while(cycles > 0) {
      cycle_led();
      tone(PIEZO_PIN, pre_cycles == 0 ? 1100 : 1000);
      delay(20);
      noTone(PIEZO_PIN);
      
      --pre_cycles;
      delay(base_delay / cycles);
      if(pre_cycles <= 0)
        --cycles;
    }
  }
}
