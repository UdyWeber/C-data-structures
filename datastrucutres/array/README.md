# Introduction to Arrays


## What is an Array
- Array represent a set of elements of the same type, grouped under one name.
- Arrays are vector variables because they have magnitude and direction in the memory.
- All the locations of the array are allocated contiguously, meaning that each location is next to the other in the 
  memory.
- Using the name of the array followed by an index e.g: `A[0]` we can directly access any element present in the array.

## Declaration of an Array
- We can declare an integer array in C and C++ using `int A[5];`, so five integer spaces will be allocated in the memory 
  contiguously, and it's values will be garbage values.
- We can also declare an array with initialized values by typing `int A[2] = {2, 3};`, if we don't specify values for 
  all array elements those will be initialized with 0, example: `int A[3] = {2, 3};`, the array's last index will be 0.
- And finally we can declare an array with all values being 0 by typing `int A[10] = {0}` so we'll have an array with 
  size ten with ten elements being 0.

## Static vs Dynamic Array
- Static arrays are those with a given size that is immutable, created at compile time and created in the stack.
- Dynamic arrays are those which size can be dynamically mutated by manually managing the memory during runtime, and 
  it's created on the heap.

## How to Resize an Array
- To dynamically resize an array, we will need to allocate a new array with the new size, and transfer the items of the 
  old array to the new one. After copying the values, we have to free the old array memory and make the pointer point to
  the new array, that's needed because array memory is contiguous, so you cannot assume that it will be a free space 
  next to the last element of the array, that's why we have to create a new one, to ensure that there will be space enough.
- You can also relly on the `realloc` method, for basic memory reallocation.
- When using the manual version of resizing an array we can have more clearness of what's happen and make more complex 
  and custom control flows to that memory.

## 2D Arrays
- There are three methods for creating 2D arrays
- We can declare a 2D array by typing its name, num of rows, and the num of columns `int A[ROWS;5][COLUMNS;5]` and just 
  like that we have a 5X5 2D array, actually in memory the 2D array is being created as a one dimensional array with 
  size 10, but the compiler allow us to access data like a table.
- We can declare a 2D array by creating an array of array pointers by typing `int *A[3]`, where we will have an array in
  the program stack pointing to 3 arrays being on the heap or the stack.
- We can declare a 2D array using the double pointer approach, where we will create it fully on the heap. First we 
  have to allocate a pointer to an array of int array pointers `int **A = (int**) malloc(3 * sizeof(int*))`, and then
  we have to fill those spots with pointers to dynamically allocated arrays on the heap.

## Arrays in Compilers
- For the compiler to allocate an Array, it needs to find the base location in memory for doing that, then it calculates
  the formula for storing the array contiguously in memory. Is a simple formula `base_mem_addr + array_size * data_type_size`
  so if our base memory address is 200, the size of the array 3 and the size of the data type 2 we know that our array 
  goes from the 200 memory location to 206.
- 2D Arrays are handled by compilers is declared as a single dimension array, and to handle performing operations in 
  rows and columns we can do row-major mapping or column-major mapping

  ### Row-major Mapping
  - In row-major mapping the 2D array is stored in the single dimensioned array row by row.
  - The formula that the compiler uses to access the 2D array memory locations is `base_mem_addr + (row * max_columns + column) * data_type_size`
  
  ### Column-major Mapping
  - In column-major mapping the 2D array is stored in the single dimensioned array column by column.
  - The formula that the compiler uses to access the 2D array memory locations is `base_mem_addr + (column * max_rows + row) * data_type_size`

## Array ADT
- Programming languages such C and C++ give us primitive data structures like arrays built-in, and we are supposed to 
  implement some methods to help us do specific operations in those data structures.
- We have some data that we should have in an Array
  - Pointer: Pointer that points to the first element of an Array
  - Size: How many items an array can handle
  - Length: How many items were added to an array
- Here are some of the helper methods that we are going to create
  - Display: Display all elements that are filled in an array.
  - Insert