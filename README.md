# IoT Project: Automated Plant Watering System

## Overview
This project is an IoT-based automated plant watering system that monitors soil moisture, temperature, and humidity levels using a NodeMCU microcontroller. The system automates watering using a 5V pump controlled by a relay, ensuring the plant receives optimal care while minimizing manual effort.

---

## Components
1. **NodeMCU v1 (ESP8266)**
   - WiFi-enabled microcontroller for IoT functionality.
2. **DHT22 Sensor**
   - Measures temperature and humidity.
   - Pin: `D1`
3. **Capacitive Soil Moisture Sensor**
   - Measures soil moisture level.
   - Pin: `A0`
4. **3.3V 1-Channel Relay Module**
   - Controls the 5V pump.
   - Pin: `D2`
5. **5V Water Pump**
   - Provides water to the plant.
6. **Power Supply**
   - External power supply for the pump.

---

## Features
- Monitors soil moisture levels using the capacitive soil moisture sensor.
- Measures temperature and humidity using the DHT22 sensor.
- Automatically activates the water pump via the relay when soil moisture drops below a threshold.
- Displays sensor data on a web interface via the NodeMCU's WiFi capabilities.

---

## Circuit Connections

### **Pin Mapping**
| Component                | Pin on NodeMCU | Notes                   |
|--------------------------|----------------|-------------------------|
| **DHT22 (Humidity/Temp)**| `D1`           | Data pin to GPIO D1     |
| **Soil Moisture Sensor** | `A0`           | Analog input to A0      |
| **Relay Module**         | `D2`           | IN pin to GPIO D2       |
| **5V Pump**              | Relay-controlled | External 5V power     |

![circuit_image](https://github.com/user-attachments/assets/4b4e3cec-9351-4d48-b507-76a14252dccd)

---

## Software Setup
### **Prerequisites**
- Arduino IDE installed.
- ESP8266 library installed in the Arduino IDE.
- DHT22 sensor library installed (`DHT22.h`).

### **Installation Steps**

TO BE ADDED

---

## Usage
1. Connect all components as per the circuit diagram.(Will be added)
2. Power up the NodeMCU and the 5V pump.
3. Monitor the sensor readings on the web interface.
4. The system will automatically activate the pump when the soil moisture drops below the defined threshold.

---

## Calibration
- **Soil Moisture Sensor:**
  - Test the sensor in dry and wet soil to determine the corresponding analog values.
  - Adjust the `moistureThreshold` in the code accordingly.

---

## Future Improvements
- Add a water level sensor to monitor the pump reservoir.
- Integrate notifications (e.g., email or SMS) for critical conditions.
- Add a web interface - In progress!

---

## License
This project is open-source and available under the MIT License.

---

## Author
Marius Babin

