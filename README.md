# Qt ChatApp 💬

A simple **client-server chat application** built using **C++ (Qt framework)** for the GUI client and **sockets** for the server.  
This project demonstrates networking concepts, event handling, and GUI development — forming the foundation for a real-time chat system.

---

## 📖 Description
The project consists of:
- A **server** program built with C++ sockets that listens for incoming connections.
- A **Qt-based GUI client** that connects to the server and sends/receives messages.
- Basic functionality such as handling button clicks, sending text, and displaying server responses.

It is designed as a beginner-friendly introduction to **network programming with GUI integration**.

---

## 🚀 Features
- Client with an interactive **Qt GUI**.
- Server using **C++ sockets**.
- Real-time message exchange (client → server → client).
- Event handling for button clicks and message logs.
- Extensible structure to add new features.

---

## 🛠️ Tech Stack
- **C++**  
- **Qt Framework** (GUI)  
- **Winsock / Sockets API** (Networking)  

---

## ⚙️ How to Run

### 🔹 1. Build & Run the Server
```bash
cd server
g++ server.cpp -o server.exe -lws2_32   # On Windows
./server.exe

