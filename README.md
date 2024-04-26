# Load Cell Sensor Project: Noise Filtering and Signal Amplification with ESP-8266

## Overview
This project involves building a signal conditioning circuit for a load cell sensor, which generates a low-level signal of approximately 2 mV. The circuit includes a low-pass active filter to remove noise, followed by an amplification stage to boost the signal level. The amplified signal is then fed into an ESP-8266 microcontroller, where it is mapped and transmitted to a Blynk dashboard for real-time visualization on both web and app interfaces.

## Hardware Components
- Load cell sensor
- LM358 dual operational amplifier
- ESP-8266 microcontroller
- Resistors, capacitors, and other passive components for filter and amplification circuits
- LEDs and a buzzer for feedback
- Blynk dashboard for visualization

## Circuit Design
1. **Low-pass Active Filter**: The signal from the load cell is first passed through a low-pass active filter to remove high-frequency noise. This filter is designed using an operational amplifier (op-amp) and passive components such as resistors and capacitors.

2. **Amplification**: After filtering, the signal is amplified using another stage with the LM358 op-amp. This step ensures the signal is strong enough to be accurately read by the ESP-8266's analog-to-digital converter (ADC).

3. **Microcontroller and Data Transmission**: The amplified signal is sent to the ESP-8266 microcontroller, where it is converted into a digital value and transmitted to the Blynk dashboard for visualization. The ESP-8266 is connected to WiFi, enabling remote monitoring and control through the Blynk app and web dashboard.

## Software
The ESP-8266 code manages the following tasks:
- **Initialization**: Configures the ESP-8266 to connect to a specified WiFi network and sets up the Blynk dashboard for data transmission.
- **Analog Signal Reading**: Reads the analog signal from the load cell sensor, applies a mapping function to convert it into a specific weight range, and sends it to the Blynk dashboard.
- **LED and Buzzer Control**: Depending on the weight range, the code controls LEDs and a buzzer to provide visual and auditory feedback. A green LED indicates a normal weight range, while a red LED and buzzer indicate a high weight range.
- **Debugging and Monitoring**: Serial output is used to display the raw signal value and the calculated weight for debugging and monitoring purposes.

## Blynk Dashboard
The Blynk dashboard is used to visualize the data sent from the ESP-8266. It displays the weight in real-time and provides an interface for monitoring the load cell's behavior. The Blynk dashboard can be accessed via a web browser or the Blynk mobile app, allowing remote monitoring and control.

## Usage Instructions
1. **Setup**: Connect the load cell sensor to the filtering and amplification circuit, then connect the output to the ESP-8266's analog input.
2. **Configure WiFi**: Update the WiFi credentials in the ESP-8266 code to match your local network.
3. **Deploy Code**: Upload the provided code to the ESP-8266 and ensure it connects to your WiFi network.
4. **Monitor via Blynk**: Use the Blynk app or web dashboard to visualize the data and monitor the weight readings.
5. **Feedback Control**: Observe the LEDs and buzzer for feedback on the weight range.

## Note
Ensure the correct wiring and connections between the load cell, filter, amplification circuit, and ESP-8266. Test the circuit with known weights to validate accuracy and adjust the mapping as needed. If using an external power source for the ESP-8266, ensure it meets the required specifications.
