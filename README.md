# Minitalk
Small project involving a server and client that exchange information using *kill(1)* signals.
## Overview

Minitalk consists of two main components: the server and the client. The server waits for messages from the client, and the client sends messages to the server. The communication is achieved using kill signals SIGUSR1 and SIGUSR2.
The goal is to transmit strings of characters from the client to the server in a binary format .

## Features

- **Client-Server Communication:** Minitalk demonstrates interprocess communication using signals, where the client sends strings to the server.

- **Binary Data Transmission:** Strings are converted to binary data using bitwise operations before being sent between the client and server.

## Usage

### Compilation

Compile the server and client programs using the provided Makefile:

```bash
make
