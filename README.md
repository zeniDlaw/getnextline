get_next_line

Summary

The get_next_line project simplifies the process of reading input from file descriptors in C. It provides a function that reads a line from a file descriptor, making file parsing and text processing tasks more manageable.

Version

Version: 12

Goals

This project introduces a convenient function while also exploring the concept of static variables in C programming.

Common Instructions

The project must adhere to the Norm and be written in C.

Functions should handle errors gracefully and free allocated memory appropriately.

A Makefile must be provided for compilation with specific flags.

Bonuses should be implemented separately.

Submissions are made to the assigned Git repository.

Mandatory Part

Function Name: get_next_line

Prototype: char *get_next_line(int fd);

Turn-in Files: get_next_line.c, get_next_line_utils.c, get_next_line.h

Parameters: fd - The file descriptor to read from

Return Value: The line read from the file descriptor, or NULL if there's nothing else to read or an error occurred

External Functions: read, malloc, free

Bonus Part

Develop get_next_line() using only one static variable

Manage multiple file descriptors simultaneously

Usage Example

Copy code

#include "get_next_line.h"

int main () 
{
    int fd = open("example.txt", O_RDONLY);
    
    char *line;
    
    while ((line = get_next_line(fd)))
    
    {
    
        printf("%s\n", line);
        
        free(line);
    }
    
    close(fd);
    
    return 0;
    
}

Important Information

The project should compile with the flag -D BUFFER_SIZE=n, defining the buffer size for read().

get_next_line() has undefined behavior if the file descriptor changes between calls without reaching the end of the file.

Reading binary files may require additional logic to handle.

It's recommended to read as little as possible with each call to get_next_line() and handle newlines appropriately.

Submission and Peer-Evaluation

Submit the assignment to the Git repository for evaluation. Ensure correct filenames and prepare diverse tests for defense.

Feel free to adjust any part of the description or examples to better fit your preferences or add any additional information you deem necessary! Let me know if there's anything else you'd like to include.





