#  Contact Management System (Console-Based)

This is a simple **Contact Management System** built in **C++**. The project is designed as a console-based application and allows users to manage their personal or professional contacts.

---

##  Purpose

I created this project to:

- Practice building **small, real-world projects in C++**.
- Learn and apply **Object-Oriented Programming (OOP)** concepts.
- Understand how to structure a project with **file I/O** for data persistence.
- Improve my problem-solving and software design skills.

---

##  Features

- Add a new contact with:
  - Name (required)
  - Phone number (required)
  - Email (optional)
  - Address (optional)
- Display all saved contacts.
- Update existing contact information.
- Delete a contact by name.
- Search contacts by **name** or **phone number**.
- Save all contact data to a file (`contacts.txt`) for persistence.
- Load saved contacts from the file on startup.

---

## 🛠 Tech Stack

- **Language:** C++
- **File Handling:** Standard file streams (`fstream`)
- **Data Structure:** `std::vector` for storing contacts in memory

---

##  Future Enhancements

I plan to add the following features in future updates:

- Case-insensitive search
- Duplicate contact detection
- Input validation (e.g., valid phone number, no empty names)
- Auto-save after each operation (not just on exit)
- Contact backups or versioning
- Structured file format (like CSV or JSON)
- UI-based or web-based version in the long term

---

##  What I Learned

- How to design a class with multiple constructors and optional fields.
- How to use file I/O to read/write persistent data.
- How to handle user input with `cin` and `getline()`.
- How to build a functional and modular C++ program.

---

##  How to Run

1. Compile the code:
   ```bash
   g++ main.cpp -o contact_app
