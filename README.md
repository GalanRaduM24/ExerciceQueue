# Restaurant Order Scheduling Simulation: FIFO Queue Modeling

[![C++](https://img.shields.io/badge/C%2B%2B-11%20%7C%2014%20%7C%2017-00599C?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Data Structures](https://img.shields.io/badge/Data%20Structure-Custom%20Queue-blue.svg)]()
[![Algorithms](https://img.shields.io/badge/Algorithm-Event--Driven%20Scheduling-orange.svg)]()
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

A discrete-event simulation implemented in C++ modeling a restaurant kitchen order pipeline using custom templated **FIFO Queue** data structures. The system tracks dynamic customer arrivals, kitchen preparation times, idle intervals, order fulfillment latency, and closing cutoff metrics.

---

## Simulation Pipeline

| Stage | Component | Operation | Description |
|:---|:---|:---|:---|
| **1. Ingestion** | File Stream (`test.txt`) | Line Parsing | Reads closing time and chronological order stream |
| **2. Buffering** | `timeQueue` (`Queue<int>`) | `enqueue()` / `dequeue()` | Buffers customer arrival timestamps |
| **3. Queuing** | `orderQueue` (`Queue<int>`) | `enqueue()` / `dequeue()` | Buffers cooking / preparation durations |
| **4. Scheduling** | Event Dispatcher | Clock Tracking | Advances kitchen clock, handles idle gaps, and completes orders |
| **5. Cutoff** | Reporting Engine | Threshold Check | Discards late arrivals past closing time and outputs summary metrics |

---

## Key Features

- **Templated Queue Implementation**: Custom `Queue<T>` data structure providing standard FIFO primitives (`enqueue`, `dequeue`, `peek`, `isEmpty`).
- **Synchronized Multi-Queue Scheduling**: Processes arrival times and cooking durations in lockstep.
- **Idle Interval Detection**: Identifies and logs downtime between consecutive orders.
- **Operational Metric Reporting**:
  - Total successfully prepared orders
  - Dropped / lost orders arriving past kitchen cutoff
  - Effective closing time accounting for in-flight orders

---

## Project Structure

```text
├── Queue.h                # Templated generic Queue<T> class implementation
├── Main.cpp               # Event scheduler simulation, execution loop, and reporting
├── test.txt               # Input dataset (closing time, count, order timelines)
└── README.md              # Project documentation
```

---

## Input / Output Format

### Input Format (`test.txt`)
- Line 1: Closing time `T` and total order count `N`
- Subsequent Lines: Order pairs containing `(arrival_time, preparation_duration)`

```text
20 4
0 5
3 7
15 4
22 3
```

---

## Getting Started

### Prerequisites
- Standard C++ compiler (`g++`, `clang++`, or MSVC).

### Compilation & Execution

1. **Clone the repository**:
   ```bash
   git clone https://github.com/GalanRaduM24/ExerciceQueue.git
   cd ExerciceQueue
   ```

2. **Compile the source**:
   ```bash
   g++ -O2 -std=c++11 Main.cpp -o restaurant_sim
   ```

3. **Run the simulation**:
   ```bash
   # On Windows
   .\restaurant_sim.exe

   # On Linux / macOS
   ./restaurant_sim
   ```
