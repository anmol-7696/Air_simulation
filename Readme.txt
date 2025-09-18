# Event-Driven Air Control Simulation ✈️

This project is an **event-driven simulation in C++** that models the scheduling of planes landing on available runways. The simulation considers planes as events in a queue, processes their arrival times, and manages runway allocation to ensure an orderly and efficient landing schedule.

---

## 📌 Features
- Simulates **multiple planes** requesting to land.
- **Runway scheduling** using an event-driven approach.
- Prioritizes planes based on arrival times and queue management.
- Generates a **landing schedule** for all planes in the simulation.
- Implemented in **C++** with efficient event handling (priority queue / linked list).

---

## 🛠️ Technologies Used
- **C++** (Core implementation)
- **Object-Oriented Design** (Event, Plane, Runway classes)
- **Event-driven simulation techniques**

---

---

## ⚡ How It Works
1. Planes are generated as **events** with specific arrival times.  
2. A **priority queue / event list** manages events in chronological order.  
3. The simulator assigns planes to available runways.  
4. A **landing schedule** is printed, showing which plane landed on which runway and at what time.  

---

## ▶️ Getting Started

### Prerequisites
- A C++17 compatible compiler (e.g., `g++`, `clang++`).

### Compilation
```bash
g++ -std=c++17 -o airsim main.cpp
./airsim
