# Aquarium Management System
A console-based management system for aquariums, built in C++ as a 1st semester Programming Fundamentals project at Bahria University.

> **Group project** — developed collaboratively by Mohid Ali, Usman, and Shafay.

---

## What It Does
This program simulates the backend operations of an aquarium facility. It lets staff manage day-to-day operations through a menu-driven interface.

**Five core modules:**

- **Customer Services** — Buy tickets (Adult/Child/Group), view revenue, clear revenue records, submit and display star-rated feedback
- **Tank Management** — Add tanks (water type, pH, temperature), add animals to tanks, display and search tank/animal records
- **Staff Management** — Record staff info (name, role, contact, shift), assign and reassign tasks (Feeding, Tank Cleaning, Health Checks)
- **Inventory Management** — Add/update/delete/search inventory items, log equipment maintenance tasks and schedules
- **File Persistence** — All data (tanks, animals, staff, revenue, feedback) is saved to `.txt` files so records survive between sessions

---

## Tech Used
- **Language:** C++
- **Concepts:** Structs, arrays, file I/O (fstream), functions, loops, input validation
- **Interface:** Console/terminal (menu-driven)

---

## How to Run

**Requirements:** A C++ compiler (g++ recommended)

```bash
# Clone the repo
git clone https://github.com/YOUR_USERNAME/aquarium-management-system.git
cd aquarium-management-system

# Compile
g++ main.cpp -o aquarium

# Run
./aquarium          # Linux/Mac
aquarium.exe        # Windows
```

> Note: The program generates `.txt` files (tank.txt, animal.txt, revenue.txt, etc.) in the same directory when you run it. These store your data between sessions.

---

## Project Structure
```
aquarium-management-system/
│
├── main.cpp          # All source code
├── README.md
└── (generated at runtime)
    ├── tank.txt
    ├── animal.txt
    ├── revenue.txt
    ├── Staff Information.txt
    └── 1_star.txt ... 5_star.txt
```

---

## Key Features Implemented
- Input validation throughout (invalid IDs, out-of-range values, duplicate tank IDs)
- Ticket billing system with itemized bill display
- Star-rating based feedback system stored in separate files per rating
- Task reassignment between staff members
- Low stock warning in inventory (triggers below quantity of 5)

---

## Context
Built as a 1st semester project for the Programming Fundamentals course (BSCS) at Bahria University, Lahore. The goal was to apply core C++ concepts — structs, file handling, functions, and arrays — in a real-world scenario.
