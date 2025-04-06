# Classroom Management System

A simple terminal-based application developed in **C** to manage classroom operations, including handling student and teacher records, class schedules, and notices.

## 📁 Project Structure
```bash
Classroom-project/
├── classroom.c        # Main application source code
├── class.txt          # Data file for class schedules
├── notice.txt         # Data file for notices
├── student.txt        # Data file for student records
├── teacher.txt        # Data file for teacher records
├── .gitignore         # Git ignore file
├── LICENSE            # License file
└── README.md          # Project documentation
```

## Features

### 👩‍🎓 Student Management
- Add, view, and delete student records.
- Store details such as name, roll number, and contact information.

### 👨‍🏫 Teacher Management
- Add, view, and delete teacher records.
- Store details such as name, employee ID, and contact information.

### 📅 Class Scheduling
- Schedule classes with details like subject, time, and assigned teacher.
- View and manage the class timetable.

### 📝 Notice Board
- Post, view, and delete notices for students and staff.


## Requirements

- **Operating System:** Linux or macOS (Windows may require a compatible terminal environment)
- **Compiler:** GCC or any standard C compiler


## Installation

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/nazmul-islam00/Classroom-project.git
   cd Classroom-project
   ```
2. **Compile the Code:**
   ```bash
   gcc classroom.c -o classroom
   ```
3. **Run the Application:**
   ```bash
   ./classroom
   ```

## 📝 License
This repository is licensed under the [MIT License](LICENSE).
