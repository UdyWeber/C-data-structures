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
- Static variables will always use the same address on the memory so, it will not recreate the variable by recursively 
  recreating the variable, same thing for global variables in our code.
- The fibonacci function is a recursive function labeled as excessive recursive because it calculates the same value 
  multiple times so, we can make a process called memoization to store values already calculated and use them later on 
  to avoid excessive calls 

## Types of Recursion
- **Tail Recursion**: Defines a function that calls itself in the last statement of the function. In cases of tail 
  recursion you can efficiently convert them into loops because the space complexity of the recursion would be O(n) and 
  the loop will be O(1) because it adds just one activation record to the stack
- **Head Recursion**: Defines a function that calls itself in the first statement of the function. It still can be 
  converted in a loop, but it'll end up looking a bit different that it is.
- **Tree Recursion**: Defines a function that calls itself more than one time. It's time complexity is of O(2^n) and 
  the space complexity is O(n)
- **Indirect Recursion**: Defines recursive functions that call each other circularly.
- **Nested Recursion**: Defines a function that calls itself using itself as a parameter.