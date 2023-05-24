#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;

bool isSafe(vector<vector<bool>> grid,int row,int col){
	for(int i=0;i<grid.size();i++){
		if(grid[i][col]==true){
			return false;
		}
	}
	int i=row,j=col;
	while(i>=0 and j>=0){
		if(grid[i--][j--]==1){
			return false;
		}
	}
	i=row,j=col;
	while(i>=0 and j<grid.size()){
		if(grid[i--][j++]==1){
			return false;
		}
	}
	return true;
}
void boardFiller(vector<vector<bool>> grid,int queen,vector<int> combination){
	if(queen==grid.size()){
		for(auto e:combination){
			cout<<e+1;
		}
		cout<<endl;
		return ;
	}
	for(int i=0;i<grid.size();i++){
		if(isSafe(grid,queen,i)){
			combination.push_back(i);
			grid[queen][i]=true;
			boardFiller(grid,queen+1,combination);
			grid[queen][i]=false;
			combination.pop_back();
		}
	}
}
void nQueen(int n){
	
	vector<bool> temp(n,false);
	vector<vector<bool>> grid(n,temp);
	vector<int> combination;
	boardFiller(grid,0,combination);
	
}
int main(){

nQueen(4);
}