<div align="center">
  <picture>
    <img src="https://github.com/ayogun/42-project-badges/blob/main/badges/getnextlinem.png" alt="42 Get Next Line badge">
  </picture>

  <p><a href="https://www.hive.fi/en/curriculum">Hive (42 School Network)</a> core curriculum project</p>
  <h1>get_next_line</h1>
</div>

`get_next_line` is a 42 project that implements a function to read a line from a file descriptor, handling any input size and buffering between calls.

---

## 🚀 Features

- Reads from any file descriptor (including STDIN)
- Handles input of arbitrary size using a buffer
- Preserves unread data between calls using static variables
- Returns one line at a time, ending in `\n` or EOF
- Bonus: Supports **multiple file descriptors simultaneously**

---

## 🧠 Learning Objectives

- File I/O with `read()` and buffer management
- Persistent state via **static variables**
- Memory handling: `malloc`, `free`, `NULL` safety
- Building robust utility functions: `ft_strlen`, `ft_strjoin`, `ft_strchr`, etc.
- Understanding newline-based reading logic
- Handling multiple FDs using separate buffers (bonus)

---

## 🗂 Project Structure

```
get_next_line/
├── get_next_line.c            # Main logic
├── get_next_line.h            # Function prototype and macros
├── get_next_line_utils.c      # Helper functions
├── get_next_line_bonus.c      # Bonus: multiple FD support
├── get_next_line_bonus.h
├── get_next_line_utils_bonus.c
├── main.c                     # Example usage / test file
├── Makefile
└── README.md
```

---

## 🔄 Simplified Logic Flow

```
1. Initialize a static buffer for the FD
2. While the buffer doesn't contain a newline:
     - Read from FD and append to buffer
     - Stop on EOF or error
3. Extract one line (ending with `\n` if present)
4. Save remaining buffer content for the next call
5. Return the extracted line
```

---

## 🛠 How to Use

### 1. Compile

```bash
make
```

### 2. Include in your code

```c
#include "get_next_line.h"

char *line = get_next_line(fd);
```

### 3. Example

```bash
gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o gnl
./gnl test.txt
```

---

## 📌 Function Prototype

```c
char *get_next_line(int fd);
```

Returns:
- A pointer to the next line (including `\n` if present)
- `NULL` if EOF or error

---

## ✅ Bonus

- Support for reading from multiple file descriptors at the same time
- Uses an array of static buffers indexed by FD

---

## 🧪 Example Test (main.c)

```c
int fd = open("example.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## 👨‍💻 Author

Developed by [Your Name]  
[GitHub](https://github.com/Lin-0096)
