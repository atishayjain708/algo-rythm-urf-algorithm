/**
This code solves the problem of the Tower Of Hanoi.
Here is the problem:
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
1) Only one disk can be moved at a time.
2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3) No disk may be placed on top of a smaller disk.

Example problem:
n = 2 disks.
Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.

Step 1 : Shift first disk from 'A' to 'B'.
Step 2 : Shift second disk from 'A' to 'C'.
Step 3 : Shift first disk from 'B' to 'C'.

The pattern here is :
Shift 'n-1' disks from 'A' to 'B'.
Shift last disk from 'A' to 'C'.
Shift 'n-1' disks from 'B' to 'C'.
*/

#include <iostream>
using namespace std;

void toh(int n,char source,char helper,char dest){
	if(n==0){
		return;
	}

	// Recursive solution
	toh(n-1,source,dest,helper);
	cout<<"Take disk "<<n<<" from "<<source<<" to "<<dest<<endl;
	toh(n-1,helper,source,dest);

}

// Driver function
int main(){
	int n;
	// cin>>n;
	// For a test case, assume n = 2.
	n = 2;
	toh(n,'A','B','C');

	return 0;
}