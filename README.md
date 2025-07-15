# 🤖 Smart Dual-Mode Robot Car | Bluetooth & Line Following

Welcome to the official repository for a Mechatronics Engineering project — a dual-mode robot car that combines manual control via Bluetooth and autonomous line-following using infrared sensors.

> Designed and built at **October 6 University – Mechatronics Engineering Department**

---

## 📌 Project Highlights

- 🔹 Two operational modes:
  - **Manual Mode**: Real-time control via HC-05 Bluetooth module.
  - **Line Following Mode**: Autonomous navigation using TCRT5000 IR sensors.

- 🔹 Controlled by an **Arduino UNO** board.

- 🔹 Chassis custom-designed, laser-cut using CNC machine.

- 🔹 Modular and extendable design for future enhancements (e.g., PID, obstacle detection).

---

## ⚙️ System Architecture

<img width="3840" height="922" alt="software_behavior" src="https://github.com/user-attachments/assets/b40a0577-1245-4425-ae1b-9e29bc151674" />

---

## 🛠️ Hardware Used

| Component                 | Quantity | Description                              |
|--------------------------|----------|------------------------------------------|
| Arduino UNO              | 1        | Main microcontroller                     |
| L298N Motor Driver       | 1        | Dual H-Bridge for DC motors              |
| HC-05 Bluetooth Module   | 1        | Wireless serial communication            |
| TCRT5000 IR 5channel Sensors      | 1        | Line detection                           |
| DC Motors                | 2        | Propulsion                               |
| Li-ion Batteries (3.7V)  | 2        | Power source                             |
| Switch                   | 1        | Master power toggle                      |

---

## 🔌 Wiring & Circuit

> A simple and efficient wiring setup to handle sensor input, motor control, and serial communication.

---

## 💻 Software & Logic

The firmware is written in Arduino C/C++. It handles:

- Bluetooth input reading.
- Sensor state evaluation.
- Conditional motor actuation.


---

## 🧪 Testing & Results

- ✔️ Manual mode performed reliably under controlled conditions.
- ✔️ IR sensors enabled effective line tracking with minor tuning.
- ❗ Occasional signal noise was mitigated by delays and threshold calibration.
- ⚠️ PID control was researched but not fully implemented due to time constraints.

---

## 🔥 Challenges

> Planning was one of our biggest challenges — we started with very ambitious goals, but quickly realized the importance of prioritization and iterative design. By starting simple and building up, we managed to deliver a functional and elegant solution under time pressure.

---

## 📎 Files Included

- `codes/` → Arduino code for control and logic.
- `design/` → Mechanical designs (PDFs & sketches).
- `media/` → Photos and videos from testing.
- `docs/` → Project report and documentation.
- `components/` → List of hardware used.
- `wiring/` → Circuit diagrams and wiring plans.

---

## 📢 Let’s Connect!

Feel free to fork the repo, open issues, or reach out if you’re working on a similar project!

> “Start simple, build smart, and improve constantly.”

---
## 🙌 Note
> 🛠️ This repository documents the full technical work, design, and code developed personally by<br> **Abdallah Mousa**, as part of a larger university project.
---
