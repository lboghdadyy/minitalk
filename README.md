# Minitalk

## Description
Minitalk is a 42 school project that involves creating a simple messaging system using UNIX signals. The project consists of a **server** and a **client**, where the client sends messages to the server using `SIGUSR1` and `SIGUSR2` signals.

## Features
- Sends messages from a client to a server using signals.
- Handles and decodes binary-encoded characters.
- Implements signal handling with `SIGUSR1` and `SIGUSR2`.
- Ensures proper synchronization between client and server.

## Usage
### Compilation
To compile the project, run:
```bash
make
```
This generates the `server` and `client` executables.

### Running the Server
Start the server and note the displayed Process ID (PID):
```bash
./server
```
Example output:
```
Server PID: 12345
```

### Sending a Message
To send a message to the server, use:
```bash
./client <server_pid> "Your message here"
```
Example:
```bash
./client 12345 "Hello, Minitalk!"
```

## Implementation Details
- The **client** converts each character into binary and sends it bit by bit using `SIGUSR1` (0) and `SIGUSR2` (1).
- The **server** catches the signals, reconstructs the characters, and prints the received message.
- The communication follows a synchronous approach to avoid signal loss.

## Handling Edge Cases
- Supports long messages by handling continuous signal reception.
- Manages unexpected signal interruptions gracefully.
- Ensures proper memory management and avoids race conditions.

## Author
Soufiane Baghdadi

