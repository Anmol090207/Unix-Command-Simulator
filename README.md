# UNIX Command Simulator (Windows)

This project is a basic command-line simulator written in C that mimics a subset of UNIX commands on a Windows system.

## 🚀 Features
- `pwd` – Display current working directory
- `ls` – List files and directories
- `mkdir` – Create a new directory
- `rm` – Remove files or empty directories
- `cd` – Change current directory

## 🛠 Tech Used
- C Programming Language
- Windows API (`windows.h`)
- Directory & file handling (`direct.h`, `io.h`)
- Standard libraries (`stdio.h`, `stdlib.h`, `string.h`)

## ⚙️ How It Works
The program provides a menu-driven interface where users can select commands. Internally, it maps these commands to Windows system calls such as:
- `_getcwd()` for `pwd`
- `FindFirstFile()` for `ls`
- `_mkdir()` for `mkdir`
- `_unlink()` / `_rmdir()` for `rm`
- `_chdir()` for `cd`

## ⚠️ Limitations
- Menu-based (not a real shell parser)
- `rm` only works on files and empty directories
- No advanced features like piping, flags, or recursion

## 📚 Learning Purpose
This project is intended for beginners to understand:
- How operating systems handle file systems
- How shell commands interact with system-level APIs
- Basics of Windows system programming in C

## ▶️ Compilation
Use a Windows compiler like GCC (MinGW):

```bash
gcc simulator.c -o simulator
./simulator
