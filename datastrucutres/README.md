# What is Data Structure
- Arrangement of collections of data items to operate efficiently on the data that is stored in the main memory
- Data structures are used by the main memory on the execution of a program to organize data in a way that it can be 
  used and interpreted by the program
- Without data structure we cannot build any useful application

# What is Database
- Permanent data that is stored in the disc organized in a schema of tables
- Data from a database can be accessed by the main memory, organized into datastructures and used by the program to
  keep persistent data being used by the server or client

# What is Data Warehouse
- Data Warehouses are sets of legacy data in databases that are rearranged into new tables with more meaningful 
  information to be later used in data analysis and reports
- These data are stored in the data warehouse by the ETL process the data is exported, then it is transformed and 
  adjusted to fit into the schema model and finally loaded into the warehouse
- Algorithms to read and analyse that data are data mining algorithms

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

# Types of Data Structures

## Physical Data Structures
- Structures that define how data should be organized for storing the elements.
- Data Structures used for storing values, adding values, searching values, etc...

### Array
- Contiguous allocated in memory, single memory chunk.
- Has fixed size, so its size is static.
- Can be created in the stack or the heap.
- Used when you need to store data of the same memory size and knows how much data you'll store.

### Linked List
- Linked List
- Collection of nodes, that contains the node data and a pointer to the next node.
- Can grow and reduce dynamically.
- Always created in the heap.
- Used when the size of a given list is not known.

## Logical Data Structures
- Uses physical data structures to store the data that the logic of the structure will work in.
- Can be implemented using Array or Linked List or a combination of both to store data

### Linear Data Structures
#### Stack
- Uses LIFO (Last In First Out) principle
#### Queues
- Uses the FIFO (First In First Out) principle

### Non Linear

#### Trees
- Is organized like a hierarchy
#### Graph
- Collections of nodes and the links between them

### Tabular
- Hash Table <3