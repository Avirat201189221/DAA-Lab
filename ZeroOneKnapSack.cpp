#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int ZeroOneKnapsack(vector<int> weights,vector<int> profits,int W){
	int dp[weights.size()+1][W+1];
	for(int i=0;i<=weights.size();i++){
		dp[i][0]=0;
	}
	for(int i=0;i<=W;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=weights.size();i++){
		for(int j=1;j<=W;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i-1]]+profits[i-1]);
		}
	}
	return dp[weights.size()][W];
	
}

int main(){
	cout<<ZeroOneKnapsack({1,1,1,1,1},{1,1,1,1,1},4);
	return 0;
}
