MaxHeap
=======

Only UBHeap.cpp was written by me. Other files were given by my Professor Dr. Hung Ngo.
http://www.cse.buffalo.edu/~hungngo/classes/2014/Fall/250/assignments/a8.html

Implement the vector-based MaxHeap data structure in C++.

What to do:

You are to write a C++ program that does the following:
It keeps reading user's inputs, line by line. Each input line the user types is supposed to be in one of the following forms:

 new heapname = [list of integers separated by space]
 top heapname
 pop heapname
 push heapname [an integer]
 print heapname
 exit

Where:

exit tells your program to quit.

heapname is an identifier (you can just think of it as a valid C++ variable name). For example, a, _a34, counter are all valid 
variable names.

[list of integers separated by space] is ... a list of integers separated by spaces, such as 3 8 -10 2 0.
[an integer] is any integer, such as 531 or -3.

new tells your program to create a new max-heap of integers, implemented using the UBHeap class (whose interface is given below).

The heap contains all members of the given list of integers. If [list of integers separated by space] is empty, then an empty 
heap is created.

top heapname prints the top element of the heap named heapname. If the heap is empty, then Heap is Empty error is printed.

pop heapname removes the maximum element from the heap without printing anything. If the heap is empty, thenHeap is Empty error
is printed.

push heapname [an integer] inserts the integer into the heap.

Here is a sample run of ubheap:

[HQN@mymachine] $ ubheap

UBHeap: build and test a Heap data structure
hqn

Version 0.7, comes with NO WARRANTY

> new a = 9 -1 10 2 -3

> print a

> 10 2 9 -1 -3 

> top a

> 10

> pop a

> push a 20

> print a

> 20 9 -3 -1 2 

> top a

> 20

> pop a

> pop a

> pop a

> pop a

> print a

> -3 

> pop a

> top a

> ** ERROR **

> Heap is Empty

> pop a

> ** ERROR **

> Heap is Empty

> new b = 3 1 5 3 2

> push b 3

> print b

> 5 3 3 1 2 3

> top b

> 5

> exit
