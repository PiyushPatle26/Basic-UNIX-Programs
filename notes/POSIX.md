# POSIX (Portable Operating System Interface)

most important aspects defined by POSIX.1-2008:

## 🔧 1. POSIX C API

POSIX significantly extends ANSI C by introducing standardized system and library calls for OS-level functionality. These APIs also define the system concepts needed to implement them.

### 🔹 File Operations

- `mkdir()`, `rmdir()` – Create/remove directories
- `dirname()` – Extract directory portion of a path
- `symlink()`, `readlink()` – Create and read symbolic links
- `link()` – Create hard links
- `unlink()` – Remove file
- `poll()` – Monitor file descriptors for I/O readiness
- `stat()` – File metadata
- `sync()` – Flush file buffers to disk
- `nftw()` – Traverse directory trees

📄 Reference: [`<unistd.h>`, `<fcntl.h>`, `<sys/stat.h>`](https://pubs.opengroup.org/onlinepubs/9699919799/)

---

### 🔹 Process and Threads

- `fork()` – Create a new process
- `exec*()` – Replace process image
- `wait()`, `waitpid()` – Wait for process termination
- `pipe()` – IPC using unnamed pipes
- `sem_*()` – POSIX named and unnamed semaphores
- `shm_*()` – POSIX shared memory
- `kill()` – Send signals
- `nice()`, `sched_*()` – Scheduling and priorities
- `sleep()` – Suspend execution
- `mkfifo()` – Named pipes (FIFOs)
- `setpgid()` – Set process group ID

📄 Reference: [`<unistd.h>`, `<sys/wait.h>`, `<sched.h>`, `<signal.h>`](https://pubs.opengroup.org/onlinepubs/9699919799/)

---

### 🔹 Networking

- `socket()`, `bind()`, `listen()`, `accept()`, `connect()` – Basic socket APIs
  📄 Reference: [`<sys/socket.h>`](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_socket.h.html)

---

### 🔹 Memory Management

- `mmap()`, `munmap()` – Map files or devices into memory
- `mlock()`, `munlock()` – Lock pages into RAM
- `mprotect()` – Set memory protection
- `madvise()` – Give advice about memory usage
- `brk()`, `sbrk()` – Change data segment size

📄 Reference: [`<sys/mman.h>`](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_mman.h.html)

---

### 🔹 Regular Expressions

- `regcomp()`, `regexec()`, `regfree()` – Compile and execute regex
- Two types:

  - **BRE** – Basic Regular Expressions (default in `grep`)
  - **ERE** – Extended Regular Expressions (`grep -E`)

📄 Reference: [`<regex.h>`](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/regex.h.html)

---

### 🔹 GNU/Linux Implementation

- Major C library: **[glibc](https://www.gnu.org/software/libc/)**, providing wrappers to syscalls
- Syscalls like `sys_write`, `sys_read`, etc., implement these APIs under the hood
- Linux-specific extensions exist beyond POSIX (e.g., `epoll`, `eventfd`)

---

## 🖥️ 2. POSIX Command-Line Utilities

POSIX standardizes a suite of shell utilities.

Examples:

- File: `ls`, `cp`, `mv`, `rm`, `mkdir`, `rmdir`
- Text: `cat`, `cut`, `paste`, `grep`, `sed`, `awk`, `sort`
- Shell operations: `cd`, `pwd`, `echo`, `env`, `kill`

🔹 Most CLI utilities are thin wrappers over the C API (e.g., `mkdir` CLI calls `mkdir()` syscall).

### 🔹 GNU/Linux Implementations

- **[GNU Coreutils](https://www.gnu.org/software/coreutils/)** – Basic file/text/utility tools
- **[GNU Sed](https://www.gnu.org/software/sed/)**, **[GNU Awk](https://www.gnu.org/software/gawk/)**, **[GNU Grep](https://www.gnu.org/software/grep/)**
- Some are shell built-ins (e.g., `cd`, `echo` in Bash)

📄 Reference: [POSIX Utility Specification](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/contents.html)

---

## 🐚 3. POSIX Shell Language

POSIX defines a standard shell syntax and behavior.

### Examples:

```sh
a=b
echo "$a"
```

Features:

- Command substitution: `$(...)` or backticks
- Quoting rules: `"..."`, `'...'`
- Redirection: `>`, `<`, `>>`, `2>&1`
- Control flow: `if`, `for`, `while`, `case`

🔹 Major Linux implementation: **[GNU Bash](https://www.gnu.org/software/bash/)**

📄 Reference: [Shell Command Language](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)

---

## 🌍 4. Environment Variables

POSIX defines the behavior of environment variables, such as:

- `HOME`, `PATH`, `USER`, `SHELL`

**PATH resolution rules:**

- If command contains `/`, it is executed directly (no PATH search)
- Otherwise, directories in `$PATH` are searched in order

📄 Reference: [POSIX Environment Variables](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap08.html)

---

## 🧾 5. Program Exit Status

### ANSI C:

- `EXIT_SUCCESS` = 0
- `EXIT_FAILURE` = implementation-defined

### POSIX adds:

- `126` – Command found but not executable
- `127` – Command not found
- `>128` – Terminated by a signal

⚠️ Bash follows the `128 + SIGNAL` rule, but POSIX itself does **not** define it.

📄 More info: [What is `$?` in shell](https://unix.stackexchange.com/questions/99112/what-is-the-meaning-of-in-shell-scripts)

---

## 🔤 6. Filename and Directory Structure

### File and path rules:

- `/` is path separator
- NUL (`\0`) not allowed in filenames
- `.` = current dir, `..` = parent
- **Portable names**: a-zA-Z0-9.\_-
- **Max path length**: 256 (POSIX), but use `PATH_MAX`
- **Max filename length**: 14 (historical), modern systems allow 255+

📄 See: [POSIX Filesystem Compliance](https://stackoverflow.com/questions/18550253/what-is-posix-compliance-for-filesystem)

---

## 🧰 7. Command-Line Option Conventions

POSIX **suggests** conventions, but they are not enforced.

### Common conventions:

- `-a`, `-l`: single-letter options
- `--`: stop option parsing

  ```sh
  ls -- -l  # Lists a file literally named "-l"
  ```

- `-` as stdin or stdout (e.g., `cat -`)

⚠️ GNU tools extend options with long flags like `--all`, which POSIX doesn't define.

📄 See: [Linux CLI standards](https://stackoverflow.com/questions/8957222/are-there-standards-for-linux-command-line-switches-and-arguments)

---

## 🔐 8. POSIX ACLs (Access Control Lists)

- Extended permission model, beyond `rwx`
- Supported by tools like `setfacl`, `getfacl`
- Backed by `setxattr()` on Linux
- POSIX ACLs were **withdrawn** from later standards but still implemented in many systems

📄 More info: [POSIX ACLs on Linux](https://man7.org/linux/man-pages/man5/acl.5.html)

---

Let me know if you'd like this in Markdown format for your notes or export.
