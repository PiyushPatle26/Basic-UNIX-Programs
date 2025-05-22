# Basic UNIX Programs

This project is an ongoing exploration of POSIX system calls through the reimplementation of basic UNIX commands. By building these fundamental tools from scratch, we gain hands-on experience with system programming concepts and a deeper understanding of how these everyday commands work under the hood.

## Project Focus

- **POSIX System Calls Exploration**: Each command implementation serves as a practical study of different POSIX system calls and their usage
- **Learning Through Implementation**: Understanding the internals of basic UNIX commands by building them ourselves
- **System Programming Practice**: Hands-on experience with file operations, process management, and system interfaces

## Current Status

This is an active project with ongoing development. We're continuously:
- Implementing new commands
- Improving existing implementations
- Adding new features
- Enhancing error handling
- Documenting our learnings

## Implemented Commands

Currently implemented commands with their key POSIX syscalls:

- `ls` - List directory contents
  - Uses: `opendir()`, `readdir()`, `closedir()`
  - Explores directory entry structures and file metadata

- `echo` - Display text
  - Uses: Standard I/O operations
  - Demonstrates basic output handling

- `find` - Search for files
  - Uses: Directory traversal and file system operations
  - Implements recursive search functionality

- `pwd` - Print working directory
  - Uses: `getcwd()`
  - Shows current working directory management

## In Progress

Commands currently being implemented:

- `cd` - Change directory
  - Will use: `chdir()`
  - Planned features: Path resolution, error handling

- `cp` - Copy files
  - Will use: `open()`, `read()`, `write()`, `close()`
  - Planned features: File copying, permission preservation

## Building and Running

To compile any of the programs:

```bash
gcc -o program_name program_name.c
```

To run a program:

```bash
./program_name [arguments]
```

## Implementation Approach

1. **Start Simple**: Begin with basic functionality
2. **Learn Syscalls**: Understand the POSIX system calls needed
3. **Add Features**: Gradually implement more complex features
4. **Handle Errors**: Proper error checking and reporting
5. **Follow Standards**: Adhere to POSIX specifications

## Learning Resources

- [POSIX Utilities](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/contents.html)
- [POSIX Functions](https://pubs.opengroup.org/onlinepubs/9699919799/functions/contents.html)
- [POSIX Shell & Utilities](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18)
- [POSIX System Interfaces](https://pubs.opengroup.org/onlinepubs/9799919799/)
- [Directory Operations](https://pubs.opengroup.org/onlinepubs/9799919799/functions/telldir.html)
- [Directory Positioning](https://pubs.opengroup.org/onlinepubs/9799919799/functions/seekdir.html)


