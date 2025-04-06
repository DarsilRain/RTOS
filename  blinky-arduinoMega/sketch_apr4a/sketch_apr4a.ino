//******************************************************************************
// Author: Haley Burnell
// Date: 4 April 2025
// Purpose: begin learning RTOS by making some therads 
//          that blink a LED
//******************************************************************************

#include <Arduino_FreeRTOS.h>

// blink LED task
void toggleLED(void *parameter) 
{
  while(1)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    // wait 500ms
    vTaskDelay(500/portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(500/portTICK_PERIOD_MS);

  }
}

void setup() {
  // configure LED pin
  pinMode(LED_BUILTIN, OUTPUT);

  // RTOS task
  xTaskCreate(
    toggleLED, //function to call
    "Toggle LED", // name of task
    1024, // stack size (in words)
    NULL, // parameter to pass to function
    1, // task priority (higher num means higher priority)
    NULL // task handle
  );

}

void loop() {
  vTaskStartScheduler();

}
