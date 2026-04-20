#include "esp_task_wdt.h"

char command[64] = "";
int current_index = 0;


void setup() {
  Serial.begin(115200);
  esp_reset_reason_t reason = esp_reset_reason();
  if (reason == ESP_RST_TASK_WDT) {
    Serial.println(">>> Rebooted by watchdog! <<<");
  } else {
    Serial.println("Normal boot");
  }
  esp_task_wdt_config_t wdt_config = {
    .timeout_ms = 7000,
    .idle_core_mask = 0,
    .trigger_panic = true
};
esp_task_wdt_deinit();
esp_task_wdt_init(&wdt_config);
esp_task_wdt_add(NULL);

}

void handleCommand(){
    if (strcmp(command, "hang") == 0) {
      Serial.println("Just hanging out...");
      while(1){

      }
    }else if (strcmp(command,  "status") == 0){
      Serial.println(millis());
      Serial.println(ESP.getFreeHeap());
      Serial.println(temperatureRead());
    }
    memset(command, 0, sizeof(command));
    current_index = 0;
}

void loop() {
  while(Serial.available()){
    char currentChar = Serial.read();
    if (currentChar == '\n'){
      handleCommand();
    }else {
      command[current_index] = currentChar;
      current_index++;
    }
  }
  esp_task_wdt_reset();
}
