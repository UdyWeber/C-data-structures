##  Memory
- Main memory is divided into 3 sections
  - Heap
  - Stack
  - Code Section
- Virtual Memory X Physical Memory
  - Virtual memory is a abstraction layer over random access memory that's on the physical components of the computer
  it operates translating the physical memory addresses on the RAM board to a virtual address inside each process of
  the computer, meaning that if we have for example:
  ```bash
    virtual address 0x7fff123 on process 1 maps to -> physical address 0x123
    virtual address 0x7fff123 on process 2 maps to -> physical address 0x456
  ```
  Those have trade-offs as well because the translation occurs on runtime and can cause performance issues.
- Memory Sections
  - On a running program we have a lot of sections that our memory page allocates that serves different purposes
  - Read-only Code Segment: Where you're code is loaded.
    - .init: entry point of the program
    - .text: Where all the code you've written is located
    - .rodata: Read only data like hardcoded strings.
  - Read / Write Segment
    - .data: Global variables that are initialized.
    - .bss: Zero value global variables location.
  - Run-time heap
    - Its the memory that can be allocated during program execution stored in a Heap
    - The heap grows up towards the library memory section, where it's located all the code from the libraries.
  - User Stack
    - Memory that is allocated created at runtime which will hold local variables and function calls.
    - The stack grows downwards and can collide with the libraries memory causing a Stack overflow
 
## Memory Allocation
- Variables allocated to the stack are those that are declared within the code scope, using normal syntax
- Variables allocated to the heap are those which we have to use the `malloc()` method and dynamically allocate it 
  our-selves with defined size. And also we have to free the memory that we've allocated after the memory is done being 
  used 
- Example of allocation
  ```c
  // Here we are assigning p a memory address allocated on the heap that holds 5 ints an int[5]
  p = (int *) malloc(5 * sizeof(int));

  // Here we are allocating the memory to the stack with defined size
  A[10];
  A[5] = {1, 2, 3, 4, 5};
  ```

## Arrays
- Array is a grouping of a set of items of the same type 
- `int A[5]` Creates an empty array `A` with sizeof 5 integers, and it will be allocated to the stack and be directly 
   accessible by the main function
-  `int B[5] = {1, 2, 3, 4, 5}` Creates an initialized array `B` also with sizeof 5 and allocated to the stack
- All the elements of an array can be accessed by index using `Array[index]`
- If we try to access a value by index in a `int[]` that is not initialized or is out of bound the compiler will return 
  `0`
- If we try to print the values of a not initialized array, it will print garbage from the memory
- To return an  array from a function to scope that calls the function it has to be dynamically allocated into the heap
  so, it can be accessed via pointers
- To get the length to an array we can use the `sizeof` method to catch the total bytes from the array and divide by the
  `sizeof` the first element of the array. E.G.:
  ```c
  int size = sizeof(array) / sizeof(array[0]); 
  ```

## Structures
- Collection of data that is related under one name, normally it groups data of the same or different types as fields of
  one declared name
- If we have as example a struct Rectangle that has two `int` fields it's memory cost would be about 8 bytes since 
  integer types have 4 bytes each
  ```c
  struct Rectangle {
    int length;
    int breatdh;  
  };
  ```
- To define and initialize structs we can follow the 2 steps bellow to do it
  ```c
  struct Rectangle r; // Declaration
  struct Rectangle r2 = {10, 5}; // Declaration + Initialization
  ```
- We can define various kinds of structures, to aggregate data for single use-cases and more complex organization of our
  system.
- If we have a structure that takes 2 integer fields and 1 char is expected of it to use 9 bytes of memory to allocate
  the structure, but the compiler actually takes 12 bytes, but why does that happen? Because it does that to pair the
  size of the structure, making it easier to the compiler access the structure from the memory. So it trades memory 
  efficiency for performance

## Pointers
- The size of a pointer in latest compilers is 8 bytes, but it used to be 4, independent of the data type of the pointer
- Pointers are address variables, it's made to store addresses of data in our memory, and they are made for indirectly 
  accessing the data. So you can say that pointers are just variables that hold addresses.
- Why we need to access data indirectly? 
  - Parameter passing
  - To access memory stored in the heap
  - To access anything that is external from our program, e.g.: Internet, Files, Hardware, etc...
- Pointers point to the start of the memory of a data variable to have its whole content
- Pointers are allocated in the stack
- Examples of pointing to data variables
  ```c
  int *p;
  int a = 10;
  
  // Here we assign p the address to the variable a
  p = &a;
  // Here we are modifying the data in variable a through p
  *p = 15;
  ```
- For referencing pointer to arrays we don't need to pass `p = &arr` because arr is already a reference to the start of
  a chunk of memory that contains type_size * arr_size memory.

## Reference
- Reference is a feature of C++ that is a nickname given to a variable that does not consume any memory

## Functions
- What are functions? Functions are pieces of code that executes a specific task within our system aggregating other 
  pieces of instructions to achieve the end of the task
- Functions have two parts the header and the body of the function, where in the header we make definitions about our 
  function and the body we create our logic for it
- Functions can take parameters to perform some logic over them

## Parameter Passing in C
- Passing by value copies the memory from the variable being passed to the function to the function scope stack and the
  outside variables are not changed at all.
- Passing by pointers does not copy any memory, instead the pointers used in the function scope, point to the values 
  referenced in outer scope. E.G.: 
  ```c
  #include <stdio.h>

  void swap(int* x, int* y) {
     int temp = *x;
     *x = *y;
     *y = temp;
  }
  
  int main() {
    int a = 10, b = 20;
    swap(&a, &b);
  
    printf("a = %d, b = %d", a, b); // a = 20 && b = 10
  }
  ```
- Arrays are always passed by reference using two types of syntax. E.G.:
  ```c
  int *A // Points to an array or an int
  int A[] // Point to an array only
  ```

## Condign Style in C and C++
- The higher abstraction we can make in C is using Structs along with functions related to these structures to perform 
  different types of operations with them.
- In C++ we can use OOP to structure our program to encapsulate business logic inside of Classes, so classes are those
  who carry the logic with them.

## Compilation Process
- The compilation process in C has 4 steps associated to it, those being: Preprocessor, Compilation, Assembling and Linking
  - Preprocessor: Handles all `#` directives in the source file
  - Compilation: Translates all code into the assembly version.
  - Assembly: Converts the assembly into machine code that will be executed by the CPU
  - Linking: Connect all object files and libraries into a final executable

## Preprocessor
- The preprocessor has directives that are always associated with instructions that should be done at the Preprocessor stage of the compilation.
- Some instructions given to the preprocessor include:
  - #include: The include instruction will actually copy paste header/C files to the context it was called.
  - #define: Will define "variables" that will store literals, which will be copied into the source code.
  - #ifdef/endif: Conditionals for checking if something is defined at the preprocessor stage.

## Error Handling
- In C we have `ERRNO` that are integer values associated with the result code of an operation / function
- Those errors are set when the program finishes with unexpected conditions, like when reading from a file,
  if the file does not exists `open()` will return -1 and we can handle it:
  ```c
  int fd = open("/path/to/file/that/don't/exists");
  if (fd = -1) {
    perror("Failed opening file"); // Will print: Failed opening file: No such file or directory
    return 69;
  }
  ```
  It will return the `ERRNO` = `EEXISTS` that can be handled using `perror()` to give a more insightful view on the error to the user.
