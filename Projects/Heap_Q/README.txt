Graded 57/100 //some silly mistakes

Task:
Implement a min heap for the following data:

date in the following format: dd-mm-yyyy
name one word
The heap should act as a priority queue for the instances of the given structure. Initially, all instances should be stored in the heap with regard to the alphabetical order of names (i.e. the instance with the first name in alphabetical order should be on top). Your program should support the following operations:

+ n v1 ...vn
add n individuals (format: <date> <name>) to the priority queue (heap). Initially, the first name in alphabetical order is on the top;
- m
remove m elements from the top of the heap and print their data on the screen (format: <date> <name> e.g. 19-04-2022 Alan);
p
print all elements of the heap in the order in which they are stored in an array;
r
rearrange the order of the queue such that the earliest date is on top. Repeats of this operation alternate between the two orders;
q
exit the program (and deallocate memory).

Input:
A sequence of instructions in the format presented above. The last instruction is q.

Output:
Result of instructions '-' and 'p'.

Example:
Input
+ 6
19-10-1945 Harris                 
07-03-1988 Glenn
22-04-1946 John                   
17-03-1972 Samuel               
11-04-1997 Pink
14-04-1926 Liz   
- 2	
p
r
+2
04-10-1974  Dawn
27-05-1977  Divine  
p
- 3
r
- 3 
q              
                      
Output
07-03-1988 Glenn
19-10-1945 Harris

22-04-1946 John
14-04-1926 Liz
11-04-1997 Pink
17-03-1972 Samuel

14-04-1926 Liz
22-04-1946 John
27-05-1977 Divine
17-03-1972 Samuel
04-10-1974 Dawn
11-04-1997 Pink

14-04-1926 Liz
22-04-1946 John
17-03-1972 Samuel

04-10-1974 Dawn
27-05-1977 Divine
11-04-1997 Pink