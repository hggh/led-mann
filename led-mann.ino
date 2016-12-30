
#include <Bounce2.h>

#define BUTTON_PIN 1
#define LED_PIN 0

uint8_t brightness = 255;
uint8_t fadeByStep = 5;
int led_mode = 1;

Bounce debouncer = Bounce(); 

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN,INPUT_PULLUP);

  debouncer.attach(BUTTON_PIN);
  debouncer.interval(0);
}

void loop() {
   debouncer.update();

   if ( debouncer.fell() ) {
     led_mode = !led_mode;
   }
   
   if (led_mode == 1) {
    analogWrite(LED_PIN, brightness);
    if (brightness == 255) {
      delay(10);
    }
    brightness = brightness - fadeByStep;

    if (brightness <= 5 || brightness >= 255) {
      fadeByStep = -fadeByStep;
    }
    uint8_t timer = random(25, 35);
    delay(timer);
  }
  else {
    analogWrite(LED_PIN, 255);
    delay(2);
  }
}
