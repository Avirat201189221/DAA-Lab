#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<int> nums;

void subsetSoln(vector<int> subset,int index,int currentSum,int remainSum,int target){
	if(index<nums.size()){
		cout<<nums[index]<<endl;
		if(currentSum==target){
			for(auto e:subset){
				cout<<e;
			}
			cout<<endl;
			return ;
		}
//		if(currentSum+remainSum<target){
//			return ;
//		}
//		if(currentSum>target){
//			return;
//		}
		subsetSoln(subset,index+1,currentSum,remainSum-nums[index],target);
		subset.push_back(nums[index]);
		subsetSoln(subset,index+1,currentSum+nums[index],remainSum-nums[index],target);
	}
}

int main(){
	nums={3,2,5,4};
	int remainSum=14;
	sort(nums.begin(),nums.end());
	vector<int> subset;
	int target=7;
	subsetSoln(subset,0,0,remainSum,target);
}