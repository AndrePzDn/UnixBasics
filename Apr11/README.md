# Desarrollo Unix

## Trainer Notes

* Email:
  * [cesar.flores@fundacion-jala.org](cesar.flores@fundacion-jala.org)

## Introducción

## History

* Started with MULTICS at 1960's
* OS write at Assembly
* Unix write at C
  * Portable

## POSIX (Portable Operating System Interface)

* Define standards
* OS Level interfaces
* User Level interfaces
* Base Utilities
* Common tools to interact with the OS
* Defined on C
* IEEE 1003
* ISO/IEC 9945

## GNU/Linux

* Linux Torvalds, September 1991
* Richard Stallman, GNU Project, 1983
* Distributions
  * Red Hat Linux Enterprice
  * Novell, SUSE Linux Enterprice
  * Debian
  * Canonical, Ubuntu
  * Slockware

  ```mermaid
    graph TD;
        A[GNU] --> B[Linux];
        B --> C[Debian];
        B --> D[Red Hat];
        B --> E[Novell];
        B --> F[Canonical];
        B --> G[Slockware];
  ```

## File System

* FAT32
* NTFS
* EXT3/4
* ZFS
* HFS+
* BTRFS

## Linux File System

* /boot #Boot Images
* /
  * /bin # Main Binaries
  * /dev # Physical Device file pointers
  * /etc # Configuration
  * /proc # Running Process Information
  * /sys # System
  * /var # Variable
  * /tmp # Temporary
  * /usr # General Binary files, libraries, documentation
  * /home # Home

## Themes

* Standard Librart STD
* Program termination status
* Control Structures
  * If
  * Switch
  * For
  * While
* Methods
* Pointers and memory
* Arguments by value, Arguments by reference
* Static Library
* Dynamic Library

### Pointes and Memory

C is a low level language, so it is necessary to manage
the memory manually.

It could be done with & and * operators.

* & is the address of a variable
* * is the value of a pointer

Everytime a pointer is created, it is necessary to free it.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p = malloc(sizeof(int));
  *p = 10;
  printf("Value: %d\n", *p);
  free(p);
  return 0;
}
```

### Static and Dinamic libraries

There are different types of libraries in C.

It could be different between static and dynamic libraries.

* Static libraries are linked at compile time
* Dynamic libraries are linked at runtime

They could be:

* .jar
* .dll
* .so
* .a

Like in [this code]($HOME/Projects/repo/UnixDevelopment/Apr15/basics.c)

## Possible Tasks

* Threads
* Processes
  * Fork
* Sockets
* Kernel Modules
