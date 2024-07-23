# 📄 **get_next_line**

## 📝 **Summary**

The `get_next_line` project simplifies the process of reading input from file descriptors in C. It provides a function that reads a line from a file descriptor, making file parsing and text processing tasks more manageable.

---

## 🏷️ **Version**

**Version:** 12

---

## 🎯 **Goals**

This project introduces a convenient function while also exploring the concept of static variables in C programming.

---

## ⚙️ **Common Instructions**

- The project must adhere to the Norm and be written in C.
- Functions should handle errors gracefully and free allocated memory appropriately.
- A Makefile must be provided for compilation with specific flags.
- Bonuses should be implemented separately.
- Submissions are made to the assigned Git repository.

---

## 📚 **Mandatory Part**

- **Function Name:** `get_next_line`
- **Prototype:** `char *get_next_line(int fd);`
- **Turn-in Files:** `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`
- **Parameters:** `fd` - The file descriptor to read from
- **Return Value:** The line read from the file descriptor, or `NULL` if there's nothing else to read or an error occurred
- **External Functions:** `read`, `malloc`, `free`

---

## 🔄 **Bonus Part**

- Develop `get_next_line()` using only one static variable.
- Manage multiple file descriptors simultaneously.

---

## 📌 **Important Information**

-   The project should compile with the flag '-D BUFFER_SIZE=n', defining the buffer size for read().
-   'get_next_line()' has undefined behavior if the file descriptor changes between calls without reaching the end of the file.
-   Reading binary files may require additional logic to handle.
-   It's recommended to read as little as possible with each call to 'get_next_line()' and handle newlines appropriately.

---

## 📋 **Additional Explanations**

# *📄 File Descriptors (fds)*
A file descriptor is an integer that uniquely identifies an open file in a running process. When you open a file, the operating system returns a file descriptor that you can use to read from or write to the file.

# *🗂️ open Function*
The 'open' function is used to open a file. It returns a file descriptor that can be used with other I/O functions. The 'O_RDONLY' flag specifies that the file is opened in read-only mode.

- *Prototype:*

```c
int open(const char *pathname, int flags);
```

- *Example:*

```c
int fd = open("example.txt", O_RDONLY);
```
# 📖 *read Function*
The read function reads data from a file descriptor into a buffer.

- *Prototype:*

```c
ssize_t read(int fd, void *buf, size_t count);
```

- *Example:*

```c
char buffer[1024];
ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
```
 ---

## 💻 **Usage Example**

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main () {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd))) {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```
 ---

## 🧪 **Testing**
To test the get_next_line function, you can use the *TEST_IT* repository. This repository contains test cases and a main function to ensure your implementation works correctly under different scenarios.

---

# 🙏 **Credits**
This project was completed as part of the curriculum at 42 School.
