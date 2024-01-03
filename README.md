![enter image description here](https://res.cloudinary.com/practicaldev/image/fetch/s--5Y59vdPn--/c_imagga_scale,f_auto,fl_progressive,h_420,q_auto,w_1000/https://dev-to-uploads.s3.amazonaws.com/uploads/articles/s5s5kdrvqfyh363utvs2.png)
# Minitalk
Small project involving a server and client that exchange information using *kill(1)* signals.
## Overview

Minitalk consists of two main components: the server and the client. The server waits for messages from the client, and the client sends messages to the server. The communication is achieved using kill signals SIGUSR1 and SIGUSR2.
The goal is to transmit strings of characters from the client to the server in a binary format .

## Features

- **Client-Server Communication:** Minitalk demonstrates interprocess communication using signals, where the client sends strings to the server.

- **Binary Data Transmission:** Strings are converted to binary data using bitwise operations before being sent between the client and server.

## Usage

### Installation
1. Clone this repository: `git clone https://github.com/manugonz42/Minitalk.git`
2. Navigate to the project directory: `cd minitalk`
3. Compile the project: `make`

### Usage
1. Run the server: `./server`
2. Run the client: `./client [Server PID] [Message to send]`

## Example

#### Terminal 1 (Server)
```bash
./server
```
#### Terminal 2 (Client)
```bash
./client [Server PID] [Message to send]
```
