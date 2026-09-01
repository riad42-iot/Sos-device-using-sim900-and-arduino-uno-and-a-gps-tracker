<h1 align="center">
  🚨 SOS Emergency Device
  <br />
  <sub>GPS + GSM Tracker · One Button to Save Lives 🆘</sub>
</h1>

<p align="center">
  <img src="https://img.shields.io/badge/MCU-Arduino%20Uno-00979D?style=for-the-badge&logo=arduino&logoColor=white" />
  <img src="https://img.shields.io/badge/GSM-SIM900L-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/GPS-NEO--6M-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Communication-SMS%20%26%20Call-brightgreen?style=for-the-badge" />
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" />
</p>

<p align="center">
  <b>An emergency alert system that sends your exact location via SMS and calls for help with one button.</b>
  <br />
  <i>Built with Arduino Uno, SIM900L GSM, and NEO-6M GPS.</i>
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
- [📱 How It Works](#-how-it-works)
- [🏠 Real-World Applications](#-real-world-applications)
- [🔮 Future Upgrades & Ideas](#-future-upgrades--ideas)
- [🤝 Acknowledgments](#-acknowledgments)

---

## 💡 Concept & Inspiration

In emergencies, every second counts. But in Bangladesh and many developing countries, emergency services often lack precise location information, leading to delayed responses.

This project solves that problem by creating a **portable, standalone SOS device** that:
- 🔴 Sends an **SMS with GPS coordinates** to pre-saved emergency contacts
- 📞 Makes an **automatic voice call** to the emergency number
- 🗺️ Provides **real-time location tracking** via Google Maps link

> 🎯 **Real-World Use Case:** Elderly individuals, solo travelers, women in distress, or anyone in an emergency can press a single button to instantly alert their family and emergency services with their exact location.

---

## ⚙️ System Architecture

```mermaid
flowchart TD
    A[Power ON Device] --> B[Initialize GPS & GSM]
    B --> C[Wait for GPS Fix]
    C --> D{Button Pressed?}
    D -->|No| C
    D -->|Yes| E[Get GPS Coordinates]
    E --> F[Convert to Google Maps Link]
    F --> G[Send SMS to Emergency Numbers]
    G --> H[Make Emergency Call]
    H --> I[LED Feedback: Blink]
    I --> C
