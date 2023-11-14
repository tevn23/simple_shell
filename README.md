# Simple Shell Implementation in C

This is a basic implementation of a shell in C that reads user input, tokenizes it, and attempts to execute commands using the `execve` system call.
Usage:
The shell will display a prompt (Eshell) $. Enter commands and press Enter to execute them.

Exiting the Shell:
To exit the shell, use CTRL + D or enter the "exit" command.

Code Overview
main.c: Contains the main function for the shell.

main.h: Header file for main.c containing function prototypes.

Features
Reads user input and tokenizes it into separate arguments.

Attempts to execute commands using the execve system call.

Handles basic memory allocation for tokens.

Known Issues
No advanced features or error handling.
Contributions
Contributions are welcome! Feel free to open issues or submit pull requests.
