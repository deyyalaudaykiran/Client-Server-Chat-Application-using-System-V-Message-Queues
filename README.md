# Client-Server-Chat-Application-using-System-V-Message-Queues
A powerful Inter-Process Communication (IPC) based chat application developed in C Programming using System V Message Queues. This project demonstrates real-time communication between multiple clients through a centralized server process in Linux.

The application allows multiple clients to:

* Send messages to each other
* Communicate through a server
* Use unique client IDs
* Exchange messages concurrently

---

# ✨ Features

## 🖥️ Centralized Server Communication

* Dedicated server process handles all communication
* Receives and forwards messages between clients

## 👥 Multi-Client Support

* Multiple clients can connect simultaneously
* Each client uses a unique ID

## 📨 Real-Time Messaging

* Instant message delivery using IPC message queues
* Sender and receiver identification included

## ⚡ Concurrent Communication

* Uses `fork()` for simultaneous:

  * Sending messages
  * Receiving messages

## 🔒 System V IPC Mechanism

* Implements:

  * `msgget()`
  * `msgsnd()`
  * `msgrcv()`
  * `ftok()`

## 🧠 Structured Message Handling

Custom message structure includes:

* Message Type
* Sender ID
* Receiver ID
* Message Content

---

# 🛠️ Technologies Used

* **C Programming**
* **Linux System Programming**
* **System V Message Queues**
* **Inter Process Communication (IPC)**
* **Process Management (`fork`)**
* **Linux Kernel IPC APIs**

---

# 📂 Project Structure

```bash id="w4k6vl"
.
├── server.c
├── client.c
├── header.h
└── README.md
```

---

# 📌 Working Principle

1. Server creates a message queue
2. Clients connect to the same queue
3. Client sends message to server
4. Server forwards message to intended receiver
5. Receiver client reads the message

---

# 🔥 Key Concepts Demonstrated

✔️ Inter Process Communication (IPC)

✔️ Message Queue Communication

✔️ Concurrent Processing

✔️ Process Creation using `fork()`

✔️ Linux System Calls

✔️ Client-Server Architecture


---

# ⚙️ Setup & Installation Guide

## 📥 Clone the Repository

```bash id="yzl4q2"

git clone https://github.com/client-server-chat-application-using-system-v-message-queues.git

cd ipc-chat-application
```

---

# 🛠️ Requirements

## Linux Environment Required

This project is designed for:

* Ubuntu
* Debian
* Kali Linux
* Fedora
* Arch Linux

## Required Compiler

Install GCC Compiler:

### Ubuntu / Debian

```bash id="hqgzls"
sudo apt update
sudo apt install build-essential
```

### Fedora

```bash id="x4z2ic"
sudo dnf install gcc
```

### Arch Linux

```bash id="7qjlwm"
sudo pacman -S gcc
```

---

# ▶️ Compile the Programs

## Compile Server

```bash id="v3x1kq"
gcc server.c -o server
```

## Compile Client

```bash id="w2q1kg"
gcc client.c -o client
```

---

# ▶️ Run the Application

## Step 1: Start the Server

```bash id="v38czf"
./server
```

Output:

```bash id="9g6dxk"
Server Started...
```

---

## Step 2: Start Clients in Separate Terminals

### Client 1

```bash id="v7e0hq"
./client 1
```

### Client 2

```bash id="n77imx"
./client 2
```

### Client 3

```bash id="h16jk9"
./client 3
```

---

# 💬 Example Communication

## Client 1

```bash id="nbo9lo"
Enter Receiver ID : 2
Enter Message : Hello Client 2
```

## Client 2 Receives

```bash id="qcmzv5"
Message from Client 1 : Hello Client 2
```

---

# 🧩 Message Structure

```c id="3v4i44"
struct msgbuf{
    long mtype;
    int sender_id;
    int receiver_id;
    char msg[100];
};
```

---

# 📚 Important System Calls Used

| Function   | Purpose                     |
| ---------- | --------------------------- |
| `ftok()`   | Generate unique IPC key     |
| `msgget()` | Create/access message queue |
| `msgsnd()` | Send messages               |
| `msgrcv()` | Receive messages            |
| `fork()`   | Create concurrent process   |

---

# 🚀 Future Enhancements

* Group Chat Support
* Broadcast Messaging
* Message Encryption
* Client Authentication
* GUI Interface
* Online User List
* Chat History Storage

---

# ⚠️ Important Notes

* Works only on Linux/Unix systems
* Server must start before clients
* Each client should have unique ID
* Message queue persists until system reboot or manual removal

---

# 🧹 Remove Message Queue Manually

If needed, remove existing IPC queue:

```bash id="r1a5kl"
ipcs -q
```

Remove queue:

```bash id="y1x63x"
ipcrm -q <queue_id>
```

---

# 👨‍💻 Learning Outcomes

This project helps understand:

* Linux IPC mechanisms
* Client-server communication
* Concurrent programming
* System-level programming in C
* Message queue implementation

---

# ⭐ Support

If you found this project useful:

* ⭐ Star the repository
* 🍴 Fork the project
* 🛠️ Contribute improvements

---
