# Minitalk

Minitalk is a simple client-server communication program that uses UNIX signals to send messages from a client to a server. The server receives the messages and prints them to the console.

## Installation

1. Clone the repository:
	```sh
	git clone https://github.com/vsennikov/minitalk.git
	cd minitalk
	```
2. Build the project:
	```sh
	make
	```

## Usage

1. Start the server:
	```sh
	./server
	```
2. In another terminal, send a message from the client:
	```sh
	./client <server_pid> "Your message here"
	```
	Replace `<server_pid>` with the PID of the running server process.

## Functions

### Server Functions

- `handle_sigusr1`: Handles the SIGUSR1 signal.
- `handle_sigusr2`: Handles the SIGUSR2 signal.
- `handle_sigint`: Handles the SIGINT signal.
- `handler`: Main signal handler function.
- `main`: Entry point for the server program.

### Client Functions

- `send_sequence`: Sends a sequence of signals.
- `send_bit`: Sends a single bit as a signal.
- `send_message`: Sends a message to the server.
- `c_handler`: Handles signals received by the client.
- `main`: Entry point for the client program.

### Utility Functions

- `error_exit`: Prints an error message and exits the program.
- `atoi_wrap`: Converts a string to an integer with additional checks.
