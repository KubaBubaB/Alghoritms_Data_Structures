Graded 100/100

Task:
Implement a linked list. Every element of the list should contain a key of type int (signed integer), and some pointers that are required by your linked list implementation.
Your program should support the following operations:
i - insert a new element to the end of your list,
d - delete an element from the end of your list and print its key on the screen,
g - get an element of the list from given position and print its key on the screen,
q - deallocate memory and quit the program.
The first element (head) of your list should be interpreted as an element on position 0, the second element is on position 1, etc.

Input:
Any number of lines, and each line contains one of the commands:
i <key>
d
g <index>
q
Where:
i, d, g, q are identifiers of the operation,
<index> is the position of an element in the list,
<key> is the key of an element (value of type int to be stored in the element).
You can assume that q will be always the last operation. You can assume that <index> will be always from range <0, size-1>.

Output:
For every g and d operation the key of a found (or deleted) element is printed. Values should be separated by the new line character (std::endl or \n).


Example:
Input
i 5
i 1
i 2
i 3
i 4
d
g 3
g 0
q
Output
4
3
5