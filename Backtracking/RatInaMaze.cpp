#include<bits/stdc++.h>
#define ll long long
using namespace std;

void RatInMaze(ll int **board, ll int x,ll int y, ll int ** sol, ll int n){
	if(x==n-1 && y==n-1){
		sol[x][y] = 1;
		for(ll int i=0;i<n;i++){
		 	for(ll int j=0;j<n;j++){
		 		cout<<sol[i][j]<<" ";
		 	}
		 	cout<<endl;
		}
		cout<<endl<<endl;
		//sol[x][y] = 0;
		return;
	}
	if(x<0 || x>=n || y<0 || y>=n || sol[x][y]==1 || board[x][y]==0)
		return;

	sol[x][y] = 1;
	RatInMaze(board,x+1,y,sol,n);
	RatInMaze(board,x-1,y,sol,n);
	RatInMaze(board,x,y+1,sol,n);
	RatInMaze(board,x,y-1,sol,n);
	sol[x][y] = 0;
}


int main(){
	ll int n;
	cin>>n;
	ll int **board = new ll int* [n];
	for(ll int i=0;i<n;i++){
		board[i] = new ll int[n];
	}
	for(ll int i=0;i<n;i++){
		for(ll int j=0;j<n;j++){
			cin>>board[i][j];
		}
	}
	cout<<"Solutions Are"<<endl;

	ll int **sol = new ll int* [n];
	for(ll int i=0;i<n;i++){
		sol[i] = new ll int[n];
	}
	for(ll int i=0;i<n;i++){
		for(ll int j=0;j<n;j++){
			sol[i][j] = 0;
		}
	}
	RatInMaze(board,0,0,sol,n);

	return 0;
}