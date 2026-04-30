# UNIX Command Simulator (Windows)

This project is a basic command-line simulator written in C that mimics a subset of UNIX commands on a Windows system.

## 🚀 Features

* `pwd` – Display current working directory
* `ls` – List files and directories
* `mkdir` – Create a new directory
* `rm` – Remove files or empty directories
* `cd` – Change current directory

## 🛠 Tech Used

* C Programming Language
* Windows API (`windows.h`)
* Directory & file handling (`direct.h`, `io.h`)
* Standard libraries (`stdio.h`, `stdlib.h`, `string.h`)

## ⚙️ How It Works

The program provides a menu-driven interface where users can select commands. Internally, it maps these commands to Windows system calls such as:

* `_getcwd()` for `pwd`
* `FindFirstFile()` for `ls`
* `_mkdir()` for `mkdir`
* `_unlink()` / `_rmdir()` for `rm`
* `_chdir()` for `cd`

## 📸 Sample Output

### 🔹 pwd

```bash
================================
 UNIX Command Simulator (Windows)
 Current Dir: C:\Users\anmol\CLionProjects\untitled\cmake-build-debug
================================
1. pwd
2. ls
3. mkdir
4. rm
5. cd
6. exit
--------------------------------
Enter your choice: 1

C:\Users\anmol\CLionProjects\untitled\cmake-build-debug
```

### 🔹 ls

```bash
================================
 UNIX Command Simulator (Windows)
 Current Dir: C:\Users\anmol\CLionProjects\untitled\cmake-build-debug
================================
1. pwd
2. ls
3. mkdir
4. rm
5. cd
6. exit
--------------------------------
Enter your choice: 2

Enter path (press enter for current dir):

[DIR] .cmake
      .gitignore
      .ninja_deps
      .ninja_log
      build.ninja
      CMakeCache.txt
[DIR] CMakeFiles
      cmake_install.cmake
      compile_commands.json
[DIR] testdir
[DIR] Testing
      untitled.exe
```

### 🔹 mkdir

```bash
================================
 UNIX Command Simulator (Windows)
 Current Dir: C:\Users\anmol\CLionProjects\untitled\cmake-build-debug
================================
1. pwd
2. ls
3. mkdir
4. rm
5. cd
6. exit
--------------------------------
Enter your choice: 3

Enter directory name: test

Directory created: test
```

### 🔹 rm

```bash
================================
 UNIX Command Simulator (Windows)
 Current Dir: C:\Users\anmol\CLionProjects\untitled\cmake-build-debug
================================
1. pwd
2. ls
3. mkdir
4. rm
5. cd
6. exit
--------------------------------
Enter your choice: 4

Enter file/directory to remove: test

Removed directory: test
```

### 🔹 cd (invalid path)

```bash
================================
 UNIX Command Simulator (Windows)
 Current Dir: C:\Users\anmol\CLionProjects\untitled\cmake-build-debug
================================
1. pwd
2. ls
3. mkdir
4. rm
5. cd
6. exit
--------------------------------
Enter your choice: 5

Enter directory path: \\testdir

cd: No such file or directory
```

### 🔹 cd (valid path)

```bash
================================
 UNIX Command Simulator (Windows)
 Current Dir: C:\Users\anmol\CLionProjects\untitled\cmake-build-debug
================================
1. pwd
2. ls
3. mkdir
4. rm
5. cd
6. exit
--------------------------------
Enter your choice: 5

Enter directory path: testdir

Changed directory to: testdir

================================
 UNIX Command Simulator (Windows)
 Current Dir: C:\Users\anmol\CLionProjects\untitled\cmake-build-debug\testdir
================================
1. pwd
2. ls
3. mkdir
4. rm
5. cd
6. exit
--------------------------------
Enter your choice:
```

### 🔹 invalid input

```bash
Invalid choice. Please enter 1-6.
```

### 🔹 exit

```bash
Enter your choice: 6

Exiting...
```

## ⚠️ Limitations

* Menu-based (not a real shell parser)
* `rm` only works on files and empty directories
* No advanced features like piping, flags, or recursion

## 📚 Learning Purpose

This project is intended for beginners to understand:

* How operating systems handle file systems
* How shell commands interact with system-level APIs
* Basics of Windows system programming in C

## ▶️ Compilation

Use a Windows compiler like GCC (MinGW):

```bash
gcc simulator.c -o simulator
```
