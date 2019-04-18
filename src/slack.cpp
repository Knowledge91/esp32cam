#include <HTTPClient.h>
#include "esp_camera.h"

HTTPClient http;

void sendMsg() {
  http.begin("https://hooks.slack.com/services/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");
  http.addHeader("Content-Type", "application/json");
  http.POST("{\"text\": \"esp32 here\"}");
  Serial.println("HTTP sent");
}

void sendCapture() {
  camera_fb_t * fb = NULL;
  fb = esp_camera_fb_get();

  http.begin("https://hooks.slack.com/services/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");
  http.addHeader("Content-Type", "image/jpeg");


}
