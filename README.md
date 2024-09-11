The IoT-based coal mine monitoring system is designed to enhance safety by continuously monitoring crucial
environmental parameters, such as smoke, temperature, and humidity, inside the coal mine. It utilizes various
hardware components, including an ESP32 microcontroller, an MQ2 gas sensor, a DHT11 humidity and
temperature sensor, an I2C LCD display, LED and buzzer. The system integrates with the Blynk cloud platform
to provide real-time monitoring and alerts to the mine owner. The MQ2 gas sensor and DHT11 sensor are
connected to the analog and digital input pins of the ESP32, respectively. The I2C LCD display is connected to
the ESP32's I2C pins to visualize the current sensor readings. The LED and buzzer are connected to specific
output pins of the ESP32.The ESP32 reads data from the MQ2 gas sensor to detect the presence of smoke or
flammable gases in the coal mine. The MQ2 sensor outputs an analog voltage, which the ESP32 converts to a
digital value for processing. Simultaneously, the DHT11 sensor provides the temperature and humidity readings,
which are directly read by the ESP32 from its digital output. The ESP32 processes the sensor data, converting the
analog reading from the MQ2 sensor into meaningful smoke concentration values. It then checks whether the
smoke level exceeds the predetermined threshold set for safe operations inside the coal mine. The system provides
a local display using the I2C LCD. The ESP32 shows the real-time readings of smoke, temperature, and humidity
on the LCD screen. Additionally, it continuously monitors the smoke level. If the smoke concentration surpasses
the defined threshold, the LED is activated to blink rapidly, indicating the hazardous condition. Simultaneously,
the buzzer is activated to produce an audible warning, alerting the on-site personnel to the potential danger. The
ESP32 is connected to the internet via Wi-Fi and integrated with the Blynk cloud platform. The system uses the
Blynk app or platform for remote monitoring and alerts. The sensor readings (including smoke level, temperature,
and humidity) are continuously sent by the ESP32 to the Blynk cloud. The mine owner can access these real-time
readings through the Blynk app on their smartphone or web interface. The data is updated periodically, ensuring
the owner has up-to-date information about the mine's environmental conditions. When the smoke concentration
exceeds the threshold level, the ESP32 triggers an alert on the Blynk platform. The Blynk app can be configured
to send notifications to the mine owner's mobile device or email address. The alert message includes the current
sensor readings, such as the smoke level, temperature, and humidity, indicating the severity of the situation.
Additionally, the GPS location of the monitoring system inside the coal mine, helping the owner pinpoint the
hazardous area precisely.
