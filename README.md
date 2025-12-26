# C-DynamicIntegerArray
This is my attempt at trying to create an efficient dynamic integer array in C.
It is the equivalent of the List data structure in Python.

### Some key features of the project:

1. The array starts with a capacity of 4 integers.

2. During initialisation the program allocates 16 bytes for the empty array and 12 bytes for the struct DynamicData.

3. As the user goes on entering each value, when the total number of values reaches the capacity of the array, a new space in the memory is allocated to the array with 8 additional bytes of storage.

4. The first 4 bytes is used to store the entered values and the additional 4 bytes of storage is kept on standby to use as a data leak buffer if needed.

5. If memory reallocation fails, the program will dislay an appropriate error message.

6. When the user is finished with entering data, they can enter "~" to stop the input process.

7. The array along with the resized capacity of the array gets diplayed.

### How to test for Memory Reallocation failure :- 
1. To run the test, "main.test.c" must be used.

2. While the test script is executing if -999 is entered, a Memory Reallocation failure is simulated. 