#ifndef LED_OPERATIONS_H
#define LED_OPERATIONS_H

#include <stdbool.h>

typedef struct {
  int led_no;
  bool *status;
} LED;

LED *initialise_leds(int n);
void set_led(LED *led_array, int index);
void reset_led(LED *led_array, int index);
void toggle_led(LED *led_array, int index);
void toggle_alternatively(LED *led_array, int n, int m);
void free_leds(LED *led_array, int n);

#endif // !#ifndef LED_OPERATIONS_H
