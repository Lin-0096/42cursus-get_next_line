<div align="center">
<picture>
  <img alt="Get Next Line with bonus" src="https://github.com/ayogun/42-project-badges/blob/main/badges/get_next_linem.png" />
</picture>

  <p><a href="https://www.hive.fi/en/curriculum">Hive (42 School Network)</a> core curriculum project</p>
  <h1>get_next_line</h1>
</div>

`get_next_line` is a 42 project that implements a function to read a line from a file descriptor, handling any input size and buffering between calls.

---

##  Features

- Reads from any file descriptor (including STDIN)
- Handles input of arbitrary size using a buffer
- Preserves unread data between calls using static variables
- Returns one line at a time, ending in `\n` or EOF
- Bonus: Supports **multiple file descriptors simultaneously**

---

## Learning Objectives

- File I/O with `read()` and buffer management
- Persistent state via **static variables**
- Memory handling: `malloc`, `free`, `NULL` safety
- Building robust utility functions: `ft_strlen`, `ft_strjoin`, `ft_strchr`, etc.
- Understanding newline-based reading logic
- Handling multiple FDs using separate buffers (bonus)

---

##  How to Compile

###  For the basic version:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

###  For the bonus version (supports multiple files at once):
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

You can choose any `BUFFER_SIZE` value that suits your testing needs.

---

##  Bonus

- Support for reading from multiple file descriptors at the same time
- Uses an array of static buffers indexed by FD
