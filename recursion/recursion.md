# Recursion
- Has two phases: Calling and Returning.
- A lot of different functions that perform a loop can be transformed into a recursive function.
- Recursive function is a function that calls itself.
- That must be a base condition that will terminate recursion.
- Example of recursive function:
  ```c
  #include <stdio.h>
  
  void add_till(int value, int target) {
    printf("Value: %d, Target: %d\n", value, target);

    if (value != target) {
        add_till(++value, target);
    }
  }

  int main() {
    add_till(1, 5);
    return 0;
  }
  ```
- We can trace the values of a recursive function by placing print statements that will be called each time a recursion
  occurs
- A function calls itself, when it terminates it comes back to where it was called
- In the calling phase we can perform operations, then call itself, and when it returns to where it was called we can 
  still do some operations, and that will happen in every step of the recursive method.
- As recursion uses the stack, each time a recursion happen a new process will be added to the top of the stack then 
  finished and popped, so if we have a function that will execute 4 recursions the size of the stack will be 5 items 
  including the main process.
- The time complexity of a recursive function can be represented using Recurrence Relation where each operation adds 1 
  unit to the formula and the call of a function that repeats n times is n-1 because it already has called the function
  once. [More content on Wikipedia](https://en.wikipedia.org/wiki/Recurrence_relation) 