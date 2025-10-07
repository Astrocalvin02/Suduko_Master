# Sudoku — C++ (with optional Armadillo solver) + Web UI

![C++](https://img.shields.io/badge/-C++-00599C?style=flat-square\&logo=c%2B%2B\&logoColor=white)
![Python](https://img.shields.io/badge/-Python-3776AB?style=flat-square\&logo=python\&logoColor=white)
![Armadillo](https://img.shields.io/badge/-Armadillo%20Library-5C2D91?style=flat-square\&logo=matrix\&logoColor=white)
![HTML](https://img.shields.io/badge/-HTML5-E34F26?style=flat-square\&logo=html5\&logoColor=white)
![CSS](https://img.shields.io/badge/-CSS3-1572B6?style=flat-square\&logo=css3\&logoColor=white)
![JavaScript](https://img.shields.io/badge/-JavaScript-F7DF1E?style=flat-square\&logo=javascript\&logoColor=black)
![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)

🎯 **A complete Sudoku playground built with C++ — featuring a lightning-fast backtracking solver, a mathematical Douglas–Rachford (Armadillo) solver, and a sleek little web interface for your browser fun!**

> 💡 Solve. Play. Benchmark. Learn. — All from one project.

---

## 🚀 Table of contents

* [Overview](#-overview)
* [✨ Highlights & Features](#-highlights--features)
* [🧠 Tech Stack](#-tech-stack)
* [⚙️ Setup & Requirements](#️-setup--requirements)
* [💻 Build & Run (CLI)](#-build--run-cli)
* [🎮 Gameplay](#-gameplay)
* [🌐 Web UI](#-web-ui)
* [📁 Project Structure](#-project-structure)
* [🧩 Development Notes](#-development-notes)
* [⏱️ Tests & Benchmarking](#️-tests--benchmarking)
* [🗺️ Roadmap](#️-roadmap)
* [🤝 Contributing](#-contributing)
* [📜 License](#-license)
* [👨‍💻 Authors & Acknowledgements](#-authors--acknowledgements)

---

## 🧩 Overview

This is a full-featured Sudoku project written in **C++**, combining an **interactive terminal game**, a **backtracking solver**, and an **experimental Douglas–Rachford (Random Projections)** solver powered by **Armadillo**. It even includes a **lightweight web UI** for playing Sudoku right in your browser!

🕹️ Whether you want to **play**, **solve**, or **benchmark algorithms**, this project has it all.

---

## ✨ Highlights & Features

✅ Command-line Sudoku game (9×9 by default)
✅ Classic backtracking algorithm for solving puzzles
✅ Optional **Douglas–Rachford solver** (with Armadillo) for advanced math fun
✅ Unit and speed test harness for benchmarking
✅ Simple web-based version with instant solving
✅ Clean, extensible C++ codebase

---

## 🧠 Tech Stack

| Layer               | Technologies                     |
| ------------------- | -------------------------------- |
| **Core Logic**      | C++11, STL                       |
| **Optional Solver** | Armadillo Linear Algebra Library |
| **Web Interface**   | HTML, CSS, JavaScript            |
| **Build System**    | Makefile                         |

---

## ⚙️ Setup & Requirements

### 🧱 Prerequisites

* C++ compiler (C++11+)
* `make`
* *(Optional)* Armadillo library — `sudo apt install libarmadillo-dev`
* For the web UI: any modern browser

### 🔧 Build

```bash
make
./sudoku   # Run interactive version
```

To enable the Armadillo solver:

```bash
# Edit Makefile:
OBJ=solver.o game.o tests.o altproj.o
LDFLAGS=-larmadillo -lm

make clean && make
```

---

## 🎮 Gameplay

🧩 **Play interactively in terminal:**

```
./sudoku
```

Type your moves using:
**column row value** → e.g. `4 1 9` sets column 4, row 1 to value 9.

🕹️ Commands:

* `solve` — instantly solve current board
* `clear` — reset puzzle
* `exit` — quit game

💡 The solver won’t let you overwrite immutable cells.

---

## 🌐 Web UI

A mini browser-based Sudoku under `web/` 🎨
Simply run:

```bash
cd web
python3 -m http.server 8000
```

Visit 👉 **[http://localhost:8000](http://localhost:8000)**

Features:

* Interactive grid
* Instant solve button
* Clean minimal style

---

## 📁 Project Structure

```
/ (root)
├─ main.cpp           # Entry point & CLI
├─ solver.cpp/hpp     # Sudoku board & backtracking logic
├─ altproj.cpp/hpp    # Douglas–Rachford solver (Armadillo)
├─ game.cpp/hpp       # Interactive play logic
├─ tests.cpp/hpp      # Speed tests & benchmarks
├─ web/               # Static browser-based version
├─ Makefile
└─ README.md
```

---

## 🧩 Development Notes

🧹 **Pro tips:**

* Add `.gitignore` to exclude `*.o`, `*.exe`, and binaries
* Add MIT License for open-source clarity
* Migrate memory management to `std::vector`
* Introduce unit testing with Catch2

---

## ⏱️ Tests & Benchmarking

Benchmark solver speeds:

```bash
./sudoku --unittest 50 --verbose
```

Compare classic vs Armadillo solver performance.

---

## 🗺️ Roadmap

🚧 Planned improvements:

* ✅ Add CMake build
* ✅ GitHub Actions CI
* 🧩 Save/Load Sudoku puzzles
* 🧠 GUI (Qt / SDL)
* 📈 Visualization of solver steps

---

## 🤝 Contributing

💬 Fork → Branch → Commit → PR
Pull requests welcome! Include unit tests for major changes.

---

## 📜 License

🪪 Recommended: [MIT License](https://opensource.org/licenses/MIT) — free to use, modify, and distribute.

---

## 👨‍💻 Authors & Acknowledgements

👨‍💻 **Matt Olson** — Core logic & architecture
👨‍💻 **Alex Izydorczyk** — Solver design & optimizations
📚 Inspired by algorithms from [moritz.faui2k3.org](http://moritz.faui2k3.org/en/yasss)
🔬 Douglas–Rachford solver reference: *Recent Results on Douglas–Rachford Methods for Combinatorial Optimization Problems*

---

✨ *Solve smarter. Code cleaner. Play harder.* ✨
