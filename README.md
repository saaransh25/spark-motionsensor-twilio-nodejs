spark-motionsensor-twilio-nodejs
================================

Spark core is used to detect motion using a Radioshack PIR sensor and Spark.publish() is used to publish motion sensing events. These events are then received by code in nodejs and twilio APIs are used to send a SMS when motion is detected. 

How I connect the RadioShack PIR sensor to SparkCore:

1 - Connect GND to GND
2 - Connect VCC to 3V
3 - Connect out to D0

