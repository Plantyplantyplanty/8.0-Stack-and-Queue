#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// Normal Run:
//---------------------------------------------------------------------
_____________________________________
_____________LIST___________________
_____________________________________
testing insert_head: inserting 0..9 at head and printing:
H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||
testing copy list
H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||
Printing backwards
H->[0]->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||

Deleting All
Printing List
H->|||
Is List Empty?
1
testing node: printing three nodes:
[0]->[5]->[6]->


testing insert_head: inserting 0..9 at head and printing:
H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||
Deleting head
Deleting 9 Deleting 8 Deleting 7 Deleting 6 Deleting 5 Deleting 4 Deleting 3 Deleting 2 Deleting 1 Deleting 0

testing insert_after:
H->[1]->[3]->[2]->|||
_____________________________________
_____________STACK___________________
_____________________________________
Stack: pushing 0..9 into stack here:
S:H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||
Copy of S:H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||
/S.top: 9 /Popping 9 /S:H->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||
/S.top: 8 /Popping 8 /S:H->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||
/S.top: 7 /Popping 7 /S:H->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||
/S.top: 6 /Popping 6 /S:H->[5]->[4]->[3]->[2]->[1]->[0]->|||
/S.top: 5 /Popping 5 /S:H->[4]->[3]->[2]->[1]->[0]->|||
/S.top: 4 /Popping 4 /S:H->[3]->[2]->[1]->[0]->|||
/S.top: 3 /Popping 3 /S:H->[2]->[1]->[0]->|||
/S.top: 2 /Popping 2 /S:H->[1]->[0]->|||
/S.top: 1 /Popping 1 /S:H->[0]->|||
/S.top: 0 /Popping 0 /S:H->|||
Copy of S:H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||
S:H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||

Testing Iterators. WILL BE ONE OFF IN THE FORWARD DIRECTION.
987654321
0123456789
_____________________________________
_____________QUEUE___________________
_____________________________________
Queue: pushing 0..9 into Queue here:
S:H->[0]->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||
Copy of S:H->[0]->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||
/S.top: 0 /Popping 0 /S:H->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||
/S.top: 1 /Popping 1 /S:H->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||
/S.top: 2 /Popping 2 /S:H->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||
/S.top: 3 /Popping 3 /S:H->[4]->[5]->[6]->[7]->[8]->[9]->|||
/S.top: 4 /Popping 4 /S:H->[5]->[6]->[7]->[8]->[9]->|||
/S.top: 5 /Popping 5 /S:H->[6]->[7]->[8]->[9]->|||
/S.top: 6 /Popping 6 /S:H->[7]->[8]->[9]->|||
/S.top: 7 /Popping 7 /S:H->[8]->[9]->|||
/S.top: 8 /Popping 8 /S:H->[9]->|||
/S.top: 9 /Popping 9 /S:H->|||
S:H->|||
Copy of S:H->[0]->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||
S after Copy of S:H->[0]->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->|||
Testing iterators:
0123456789
9876543210
END
C:\Users\Manth\source\repos\8.0 Stack and Queue\Debug\8.0 Stack and Queue.exe (process 13848) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

//---------------------------------------------------------------------
// Popping Empty Queue
//---------------------------------------------------------------------
Queue: popping empty Queue
Assertion failed: !empty() && "queue: empty object cannot be popped.", 
file C:\Users\Manth\source\repos\8.0 Stack and Queue\8.0 Stack and Queue\Queue.h, line 144

//---------------------------------------------------------------------
// Top Empty Queue
//---------------------------------------------------------------------
Queue: top of an empty Queue.
Assertion failed: !empty() && "queue: top of empty object does not exist.", 
file C:\Users\Manth\source\repos\8.0 Stack and Queue\8.0 Stack and Queue\Queue.h, line 155

//---------------------------------------------------------------------
// Popping Empty Stack
//---------------------------------------------------------------------
Stack: popping empty Stack
Assertion failed: !empty() && "Stack: empty object cannot be popped.", 
file C:\Users\Manth\source\repos\8.0 Stack and Queue\8.0 Stack and Queue\Stack.h, line 138

//---------------------------------------------------------------------
// Top Empty Stack
//---------------------------------------------------------------------
Stack: top of an empty Stack.
Assertion failed: !empty() && "Stack: top of empty object does not exist.", 
file C:\Users\Manth\source\repos\8.0 Stack and Queue\8.0 Stack and Queue\Stack.h, line 148

*/

#endif