#include <HTTPClient.h>
#include "esp_camera.h"
#include <base64.h>

HTTPClient http;

void sendMsg() {
  http.begin("https://hooks.slack.com/services/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");
  http.addHeader("Content-Type", "application/json");
  http.POST("{\"text\": \"esp32 here\"}");
  Serial.println("HTTP sent");
}

void sendCapture(uint8_t *image_buffer, int len) {
  http.begin("https://2aczcmrqs4.execute-api.eu-west-1.amazonaws.com/dev/capture");
  http.addHeader("Content-Type", "application/json");

  String imageString = base64::encode(image_buffer, len);

  http.POST("{\"image\":\"" + imageString  + "\"}");
  Serial.println("HTTP sent");
}
