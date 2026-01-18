*This project has been created as part of the 42 curriculum by aalemami*

# mini_talk

## Description

mini_talk is a small educational project implementing inter-process communication using UNIX signals. The goal is to send text from a client to a server by encoding each byte as eight signals (SIGUSR1 for bit 1, SIGUSR2 for bit 0). The server reconstructs bytes from the incoming signals and prints the received message. This project is intended to teach low-level IPC, signal handling, and synchronization considerations.

## Instructions

Compilation
- Build the project with the top-level Makefile:
  ```sh
  make
  ```

Execution
1. Start the server in a terminal:
   ```sh
   ./server
   ```
   The server prints its PID on start.
2. From another terminal, send a message with the client:
   ```sh
   ./client <SERVER_PID> "Your message here"
   ```

Notes
- Ensure server and client binaries are up-to-date after building.
- Run client and server in separate terminals. If messages are garbled, try adding short delays between signals in the client.

## Resources

References
- signal(7) — Linux manual pages: https://man7.org/linux/man-pages/man7/signal.7.html
- kill(1) — sending signals: https://man7.org/linux/man-pages/man1/kill.1.html
- POSIX signal handling documentation

AI usage
- This README was drafted with assistance from GPT-5 mini to structure and compose the documentation only. Code and core project logic were implemented by the author.

## License

No license.

