// mqtt_connection.h
#ifndef MQTT_CONNECTION_H
#define MQTT_CONNECTION_H

void mqttConnect();
void mqttPublish(const char* topic, const char* payload);

#endif // MQTT_CONNECTION_H