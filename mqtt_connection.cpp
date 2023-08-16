// mqtt_connection.cpp
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include "mqtt_keys/aws_cert.h"
#include "mqtt_keys/aws_private_key.h"
#include "aws_root_ca.h"

// AWS IoT Core settings
const char* awsIotEndpoint = "a38d1rguil9yk3-ats.iot.us-west-2.amazonaws.com";

// MQTT client
WiFiClientSecure wifiClientSecure;
PubSubClient mqttClient(wifiClientSecure);

void mqttConnect() {
  // Set MQTT TLS certificates
  wifiClientSecure.setCACert(aws_root_ca_pem);
  wifiClientSecure.setCertificate(aws_cert);
  wifiClientSecure.setPrivateKey(aws_private_key);

  // Set MQTT server settings
  mqttClient.setServer(awsIotEndpoint, 8883);
  mqttClient.setKeepAlive(15);

  // Attempt to connect to AWS IoT Core
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT connection...");
     /* We use CLIENT_NAME (which is not defined). Should use mac address here*/
    if (mqttClient.connect(CLIENT_NAME)) {
      Serial.println(mqttClient.state());
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void mqttPublish(const char* topic, const char* payload) {
  if (mqttClient.connected()) {
    mqttClient.publish(topic, payload);
    Serial.println("MQTT message published");
  } else {
    mqttClient.connect(CLIENT_NAME);
    Serial.print(mqttClient.state());
    // Serial.println("MQTT client not connected, unable to publish");
  }
}
