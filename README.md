# SafeLink – Smart Personal Safety Wristband (IoT Project)

SafeLink is an IoT-based personal safety wearable designed to send emergency SMS alerts with real-time GPS location. The system uses a microcontroller, GSM, and GPS modules to provide a reliable SOS alert mechanism during emergency situations.

---

## 🔹 Project Overview

The goal of SafeLink is to create a compact and portable safety device that allows users to trigger an emergency alert instantly. The device works without internet connectivity and relies on GSM-based SMS communication for maximum reliability.

---

## 🔹 Key Features

- SOS emergency alert via SMS  
- Real-time GPS location sharing  
- Fallback SMS alert when GPS signal is unavailable  
- Battery-powered portable hardware setup  
- Reliable serial communication between modules  

---

## 🔹 Technologies & Components Used

### Hardware
- Arduino Nano – Microcontroller  
- SIM800 GSM Module – SMS communication  
- Neo-6M GPS Module – Location tracking  
- Push Button – SOS trigger  
- Li-ion Battery – Power supply  

### Software
- Embedded C  
- Arduino IDE  
- TinyGPS++ Library  
- UART Serial Communication  

---

## 🔹 Working Logic

- The Arduino Nano continuously monitors the SOS push button.
- When the button is pressed:
  - GPS coordinates are read from the Neo-6M module.
  - A formatted emergency message is prepared.
  - The SIM800 GSM module sends an SMS to predefined contacts.
- If GPS data is unavailable, the system still sends an emergency SMS to ensure alert delivery.

---

## 📸 Hardware Prototype Image

![WhatsApp Image 2026-01-04 at 5 33 44 PM](https://github.com/user-attachments/assets/bb495897-5bdc-4b67-86cb-a1153a0a7b58)

---

## 🔹 Use Cases

- Personal safety and emergency alert systems  
- Women safety wearable devices  
- IoT-based security solutions  
- Portable emergency communication devices  

---

## 🔹 Project Status

- ✅ Hardware prototype assembled  
- ✅ GSM-based SMS alert tested  
- ✅ GPS location tracking integrated  
- ✅ Fallback logic implemented  

---

## 🔹 Future Improvements

- Compact PCB-based wearable design  
- Battery charging and power management module  
- Mobile application integration  
- Additional safety sensors  

---

## 🔹 Author

**Sujit Kumar**  
B.Tech – Electronics and Communication Engineering  
📍 Dhanbad, Jharkhand, India  

- LinkedIn: https://www.linkedin.com/in/sujit-kumar-931447291/  
- GitHub: https://github.com/Sujitpw  

---

## 🔹 License

This project is created for academic and learning purposes.
