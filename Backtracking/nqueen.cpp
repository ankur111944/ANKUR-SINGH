#include<bits/stdc++.h>
#define ll long long 
using namespace std;

bool issafe(ll int ** board, ll int i, ll int j, ll int n){
	ll int x = i;
	ll int y = j;
	for(ll int it = 0;it<i;it++){
		if(board[it][j]==1)
			return false;
	}
	//for right diagonal
	while(x>=0 && y<n){
		if(board[x][y]==1)
			return false;
		x--;
		y++;
	}
	x = i;
	y = j;
	//for left diagonal 
	while(x>=0 && y>=0){
		if(board[x][y]==1)
			return false;
		x--;
		y--;
	}
	return true;
}

bool solveNQueen(ll int ** board, ll int ind,ll int n){
	if(ind==n){
		for(ll int i=0;i<n;i++){
			for(ll int j=0;j<n;j++){
				if(board[i][j]==1){
					cout<<"Q ";
				}
				else{
					cout<<"- ";
				}
			}
			cout<<endl;
		}
		return true;
	}
	//Here I am checking for each column
	for(ll int i=0;i<n;i++){
		if(issafe(board,ind,i,n)){
			board[ind][i] = 1;
			bool isrightind = solveNQueen(board,ind+1,n);
			if(isrightind)
				return true;
			board[ind][i] = 0;
		}
	}
	return false;
}


int main(){
	ll int n;
	cin>>n;
	ll int **board = new ll int *[n];
	for(ll int i=0;i<n;i++){
		board[i] = new ll int[n];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			board[i][j] = 0;
	//memset(board,0,sizeof(board));
	solveNQueen(board,0,n);


}