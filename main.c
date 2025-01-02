#include "led_operations.h"
#include <stdio.h>
#include <stdlib.h>

LED *initialise_leds(int n) {
  LED *led_array = (LED *)malloc(n * sizeof(LED));
  if (!led_array) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < n; i++) {
    led_array[i].led_no = i + 1;
    led_array[i].status = (bool *)malloc(sizeof(bool));
    if (!led_array[i].status) {
      perror("Failed to allocate memore for LED status");
      exit(EXIT_FAILURE);
    }
    *(led_array[i].status) = false;
  }
  return led_array;
}

void set_led(LED *led_array, int index) { *(led_array[index].status) = true; }

void reset_led(LED *led_array, int index) {
  *(led_array[index].status) = false;
}

void toggle_led(LED *led_array, int index) {
  *(led_array[index].status) = !*(led_array[index].status);
}

// void toggle_alternatively(LED *led_array, int n, int m) {
//   for (int i = 0; i < m; i++) {
//     for (int j = 0; j < n; j++) {
//       if (j % 2 == i % 2) {
//         toggle_led(led_array, j);
//       }
//     }
//     printf("Iteration %d\n", i + 1);
//     for (int j = 0; j < n; j++) {
//       printf("LED %d is %s\n", led_array[j].led_no,
//              *(led_array[j].status) ? "ON" : "OFF");
//     }
//     printf("\n");
//   }
// }

void print_led_status(LED *led_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", *(led_array[i].status));
    }
    printf("\n");
}

void toggle_alternatively(LED *led_array, int n, int m) {
  for (int i = 1; i <= m; i++) {
    printf("Iteration %d:\n", i );


    for (int j = 0; j < n; j++) {
      if ((i>>j) & 1) {
        set_led(led_array, n - j - 1);
      } else {
        reset_led(led_array, n - j - 1);
      }
    }

    printf("After Toggle:  ");
    print_led_status(led_array, n);

    printf("\n");
  }
}



void free_leds(LED *led_array, int n) {
  for (int i = 0; i < n; i++) {
    free(led_array[i].status);
  }
  free(led_array);
}

int main() {
  int n, m;
  printf("Enter the number of LEDs (n): ");
  scanf("%d", &n);
  printf("Enter the number of times to toggle (m): ");
  scanf("%d", &m);

  LED *led_array = initialise_leds(n);
  toggle_alternatively(led_array, n, m);
  free_leds(led_array, n);

  return 0;
}
