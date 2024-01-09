# Static vs Dynamic Memory Allocation
- Memory overall is divided into bytes and each of these have its own address on memory
- The bytes are organized linearly on the memory
- Ram separates memory into manageable pieces of memory called segments and each one will have its size

# How Our Program Uses Main Memory
- When uses by a program, our main memory is split into 3 sections
  - Code Section 
  - Stack
  - Heap
  
  ## Code Section
    - Code Section is where our raw code lives, and other programs can be loaded.
    - Code stored in this sections will be always the machine code of our programs
  
  ## Stack
    - The memory allocated into the stack is static allocated memory because at compile time the compiler knows how many
      bytes it has to allocate.
    - The stack section has the program stack and the scopes or functions stacks, the stack stores variables and memory 
      addresses that will be cleaned by the garbage collector when the program finishes executing.
    - Memory on the stack is automatically allocated and deallocated as functions are called and return. It follows a 
      last-in, first-out (LIFO) structure.
    - Following the LIFO structure the stacks executes the instructions that are in the top of the stack then pops it 
      from the stack, repeating this till the stack is empty, it means that our program finished executing.
    - An illustration of how the stack interpret our program:
    ```c
    // sum_two stack
    // Have val = 12
    // Have b = 14
    // Have a call to printf() 
    void sum_two(int val) {
        int b = val + 2;
        printf("Val plus 2: %d", b);
    }
    
    // program stack
    // have a = 12;
    // have a call to sum_two(a)
    void main() {
        int a = 12;
        sum_two(a);
    }
    ```
    - As the illustration shows the stack creates fragments of itself to aggregate different scopes.
  ## Heap
    - Heap is used in programing as a term for unorganized memory.
    - Heap memory should be treated like a resource where when the resource is required you call and consume the memory, 
      and when it's not required anymore you release the resource.
    - Program cannot directly access heap memory, so we use pointers to the heap to access data stored in it and these
      pointers are created in the stack.
    - To allocate dynamic memory on the heap in C we use `malloc()` and in C++ we use `new <Object>`.
    - To free the memory allocated we use the `free(memory)` method, and for good practices we set the pointer for the 
      memory on the heap to NULL to avoid dangling pointer issues. 