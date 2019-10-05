/*
An implementation of the Algorithm solving the N-Queens problem.

The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. For example, following is a solution for 4 Queen problem.
The problem can be solved using backtracking.
**/
#include <iostream>
using namespace std;

bool isSafe(int board[][10],int i,int j,int n){
	// check row and columns
	for(int k=0;k<n;k++){
		if(board[k][j] || board[i][k]){
			return false;
		}
	}
	// Check for diagnols 
	int k=i;
	int l=j;

	// Check the right diagonal
	while(k>=0 && l<n){
		if(board[k][l]){
			return false;
		}
		k--;
		l++;
	}
	// Check the left diagonal
	k=i;
	l=j;
	while(k>=0 && l>=0){
		if(board[k][l]){
			return false;
		}
		k--;
		l--;
	}

	// If queen is not here then return that
	// the location is safe to put the queen
	// i.e return true;
	return true;

}


bool NQueen(int board[][10],int i,int n){
	// base case
	if(i==n){
		// Print the board
		for(int k=0;k<n;k++){
			for(int l=0;l<n;l++){
				cout<<board[k][l]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}

	// Recursive case
	for(int j=0;j<n;j++){
		if(isSafe(board,i,j,n)){
			// If it is safe to put then place the Queen
			board[i][j]=1;
			// Store result of recursive solving of teh subproblem in this variable
			bool remainingQueensPlaced = NQueen(board,i+1,n);
			// Checking if the other queens (after the current one could be placed)
			if(remainingQueensPlaced){
				return true;
			}
			// Remove the placed Queen
			board[i][j]=0;
		}		

	}
	return false;
}


int main(){
	int board[10][10];
	int n;
	// Take input for the number of Queens
	// cin>>n;
	// Put n = 4 for testing purposes.
	/*
	For n=4 this will be the one of the possible outputs:
				{ 0,  1,  0,  0}
				{ 0,  0,  0,  1}
				{ 1,  0,  0,  0}
				{ 0,  0,  1,  0}
	It is to be noted that for a given value of n, there can be 
	multiple possible configurations. This implementation prints all
	possible implementations, separating each by a blank line.
	**/
	n = 4;
	NQueen(board,0,n);
	return 0;
}
