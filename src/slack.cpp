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

void sendCapture() {
  camera_fb_t * fb = NULL;

  fb = esp_camera_fb_get();

  Serial.println("jpg to base64");
  String base64String = base64::encode((uint8_t *)fb->buf, fb->len);
  Serial.println(base64String);
}
