
# 🔐 Password Protected Security System (Arduino)

## 📌 (What this project is)

This project is a **microcontroller-based security system** that uses a keypad for password input and provides feedback using LEDs and a buzzer. It also includes a **security lockout mechanism** after multiple failed attempts.

The system simulates real-world access control systems used in doors, safes, and security panels.

---

## ⚙️ Working Principle

The system works based on **input validation and state control**:

1. User enters password using a keypad
2. Input is hidden using * (masking)
3. User presses # to submit password
4. Arduino compares input with stored password
5. System gives feedback:

   * Green LED → Correct password
   * Red LED + buzzer → Wrong password
6. After multiple wrong attempts, system locks for a fixed time

---

## 🔒 Security Logic

The system includes:

* **Attempt tracking** (counts wrong inputs)
* **Lockout mechanism** after 3 failed attempts
* **Time-based unlock using millis()
* Prevents further input during lock state

This mimics real-world security systems where repeated failures trigger temporary lockouts.

---

## 💻 Code Explanation

### 1. Keypad Input Handling

The keypad is used to take password input one character at a time.

* getKey() reads button presses
* Characters are stored in a string (inputPassword)
* * is displayed instead of actual digits for security

---

### 2. Password Verification

When '#'is pressed:

* Input password is compared with stored password
* If correct → access granted
* If wrong → attempt counter increases

---

### 3. Feedback System

#### ✅ Correct Password

* Green LED ON for 2 seconds
* System resets attempts

#### ❌ Wrong Password

* Red LED ON
* Buzzer beeps 3 times
* Attempts increase

---

### 4. Lockout System

If wrong attempts exceed limit (3):

* System enters LOCK state
* Red LED + buzzer activated
* No input is accepted
* After 30 seconds, system unlocks automatically

This is handled using:

* 'millis()' → tracks time without stopping program
* 'isLocked' → controls system state

---

### 5. Special Keys

* '*' → Clears current input
* '#' → Submits password

---

## 🧠 Key Concepts Used

* Digital input/output (LED, buzzer, keypad)
* String handling
* Conditional logic (if-else)
* State machine concept (LOCK / UNLOCK)
* Timing without delay (millis())

---

## 🎯 Real-World Applications

* Digital door locks
* ATM security systems (basic logic)
* Smart lockers
* Access control systems in offices

---

OUTPUT:
<img width="1662" height="596" alt="Screenshot 2026-05-03 140351" src="https://github.com/user-attachments/assets/b06ca462-f11b-444c-be49-21b05a0d80b8" />
<img width="1738" height="581" alt="Screenshot 2026-05-03 141252" src="https://github.com/user-attachments/assets/73240ba6-b17d-482f-a063-65c54dbfc3d6" />


---




