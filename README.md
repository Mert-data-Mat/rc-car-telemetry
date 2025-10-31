# RC Car Telemetry System

This repository documents the development of a **custom telemetry system** for my **Traxxas T-Maxx 2.5** — a legendary nitro RC truck that I’m bringing back to life and upgrading with modern electronics.  

The goal is to build a fully functional **real-time telemetry link** using **Arduino Nano**, **ESP32**, and **nRF24L01+ PA+LNA** modules to monitor key parameters such as **RPM**, **temperature**, **voltage** and **acceleration**.

---

## 🏁 The Story So Far

I bought the **Traxxas T-Maxx 2.5** as a **salvage truck** — it hadn’t run in years, and it came with missing screws, cracked plastics, burned electronics and a non-starting engine.  

After a complete teardown and rebuild, including a **new glow plug**, **fuel line**, **gaskets**, and **carburetor cleaning**, the TRX 2.5 engine finally came back to life.  

Once it was running again, I realized how much data this little engine produces — RPM, temperature, voltage, vibration — and that’s when the idea of this project was born.

The project started as a simple curiosity but quickly evolved into a full embedded engineering experiment combining **hardware, firmware, and automotive-style data acquisition**.

---

## ⚙️ Hardware Foundation

The telemetry system is being designed around two microcontrollers:

| Unit | Description |
|------|--------------|
| **Transmitter (Car Unit)** | Arduino Nano-based module inside the car. It reads sensors and transmits data over nRF24. |
| **Receiver (Base Unit)** | ESP32 module that receives telemetry packets and displays or logs them in real time. |

Wireless communication uses **nRF24L01+ PA+LNA** modules for reliable long-range transmission.  
Power is managed through **LM2596** (step-down converter) and **AMS1117** (3.3V regulator) for clean voltage delivery to sensitive components.

---

## 🧰 Components

| Component | Function |
|------------|-----------|
| **Arduino Nano / Uno** | Main MCU for data acquisition |
| **ESP32** | Receiver, dashboard processor, and future data logger |
| **nRF24L01+ PA+LNA** | Wireless transceiver for telemetry |
| **AMS1117-3.3V** | 3.3V power regulator for RF module |
| **LM2596** | Buck converter for system power |
| **Hall Effect Sensor** | Measures clutch or wheel RPM |
| **MAX6675 + K-Type Thermocouple** | Engine head temperature sensor |
| **MPU6050** | Detects vibration, tilt, and acceleration |
| **Voltage Divider** | Monitors battery voltage |

---

## 🚙 Test Platform: Traxxas T-Maxx 2.5

| Specification | Details |
|----------------|----------|
| **Engine** | TRX 2.5 Nitro (2-stroke) |
| **Fuel Type** | 16% Nitro |
| **Drive System** | 4WD Shaft Driven |
| **Transmission** | 2-Speed Automatic |
| **Scale** | 1:10 |
| **Electronics** | Standard 2.4GHz Radio System |

This truck is an ideal testbed — loud, raw, and mechanical. Every vibration and throttle pull gives a new data point.  
The challenge is making the electronics survive **heat, vibration, and fuel residue** — a perfect embedded test environment.

---

### Current Goals

- Set up a solid wireless link between the Arduino Nano and ESP32. ✅ DONE
- Bring core sensors online — RPM, temperature, and voltage. ☑️ Currently working on it.
- Get the hardware stable and power lines clean.
- Once everything runs smooth, start logging data and plan the dashboard.

---

## 🗓️ Roadmap

| Stage | Description                                 | Status |
|--------|---------------------------------------------|---------|
| **Hardware Planning** | Component selection, last checks on the car | ✅ Done |
| **RF Link Test** | nRF24 communication tests                   | 🔄 In Progress |
| **Sensor Setup** | Connect & test RPM, temp, motion sensors    | ✅ Done |
| **Firmware Development** | Telemetry data structure & transmission     | ⏳ Planned |
| **Dashboard Display** | Visualization on the remote control         | ⏳ Future Goal |

---

### 📔 Project Logs
For the full build story, technical notes, and progress updates, see the [Project logs](./logs).

## 🧠 Author

**Mert Mat**
