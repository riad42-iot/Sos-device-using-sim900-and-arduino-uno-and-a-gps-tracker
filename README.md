<h1 align="center">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=700&size=30&pause=1000&color=6C63FF&center=true&vCenter=true&width=600&lines=🏠+ESP32+Home+Automation;Wi-Fi+Controlled+Relay;Smart+Lighting+at+Your+Fingertips+💡" alt="Typing SVG" />
</h1>

<p align="center">
  <img src="https://img.shields.io/badge/MCU-ESP32-000000?style=for-the-badge&logo=espressif&logoColor=white" />
  <img src="https://img.shields.io/badge/Connectivity-Wi--Fi-1A73E8?style=for-the-badge&logo=wifi&logoColor=white" />
  <img src="https://img.shields.io/badge/Actuator-Relay%20Module-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Interface-Web%20Server-brightgreen?style=for-the-badge&logo=html5&logoColor=white" />
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" />
</p>

<p align="center">
  <b>Control your home appliances from any device with a web browser.</b>
  <br />
  <i>No cloud dependency — just pure local Wi-Fi control.</i>
</p>

---

## 📖 Table of Contents

- [💡 Concept & Inspiration](#-concept--inspiration)
- [⚙️ System Architecture](#️-system-architecture)
- [✨ Unique Features](#-unique-features)
- [🧩 Hardware Bill of Materials](#-hardware-bill-of-materials-bom)
- [🔌 Pin Mapping (Wiring Diagram)](#-pin-mapping-wiring-diagram)
- [💻 Software Architecture](#-software-architecture)
- [🚀 Getting Started](#-getting-started-setup--upload)
- [🖥️ Web Interface Preview](#️-web-interface-preview)
- [🏠 Real-World Applications](#-real-world-applications)
- [🔮 Future Upgrades & Ideas](#-future-upgrades--ideas)
- [🤝 Acknowledgments](#-acknowledgments)

---

## 💡 Concept & Inspiration

Traditional wall switches are fixed, inconvenient, and require physical access. This project transforms a standard electrical appliance (like a bulb) into a **smart device** using an **ESP32** microcontroller and a relay module.

By hosting a lightweight **web server** directly on the ESP32, you can control the appliance from your smartphone, tablet, or laptop — as long as you're on the same Wi-Fi network.

> 🎯 **Real-World Use Case:** Turn on your room lights without getting out of bed, or control your workshop equipment remotely without touching a switch.

---

## ⚙️ System Architecture

The ESP32 acts as both a **Wi-Fi client** and a **web server**. Here's how it works:

```mermaid
flowchart TD
    A[Power ON ESP32] --> B[Load Wi-Fi Credentials from Code]
    B --> C[Attempt Wi-Fi Connection]
    C --> D{Connected to Router?}
    D -->|No| E[Retry / Error]
    D -->|Yes| F[Obtain Local IP Address]
    F --> G[Print IP to Serial Monitor]
    G --> H[Start Web Server]
    H --> I[Wait for Client Request]
    I --> J[User Opens Browser at ESP32 IP]
    J --> K[ESP32 Serves HTML Page]
    K --> L[User Clicks ON/OFF Button]
    L --> M[Browser Sends HTTP Request]
    M --> N[ESP32 Toggles Relay]
    N --> O["Relay Switches Bulb (ON/OFF)"]
    O --> I
