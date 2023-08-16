#ifndef AWS_CERT_H
#define AWS_CERT_H

#include <Arduino.h>

const char aws_cert[] = R"EOF(
-----BEGIN CERTIFICATE-----
certificate contents here
-----END CERTIFICATE-----
)EOF";

const char aws_private_key[] = R"EOF(
-----BEGIN RSA PRIVATE KEY-----
key contents here
-----END RSA PRIVATE KEY-----
)EOF";


#endif