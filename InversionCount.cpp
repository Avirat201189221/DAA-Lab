#include<iostream>
#include<vector>
#include<climits>
#include<math.h>

using namespace std;
int merge(vector<int> &nums,int low,int mid,int high){
	vector<int> left;
	vector<int> right;
	int ic=0;
	for(int i=0;i<=mid;i++){
		left.push_back(nums[i]);
	}
	for(int i=mid+1;i<=high;i++){
		right.push_back(nums[i]);
	}
	cout<<"init working";
	int i=0,j=0,k=low;
	while(i<left.size() && j<right.size()){
		if(left[i]<=right[j]){
			nums[k]=left[i];
			k++;
			i++;
		}
		else{
			nums[k]=right[j];
			k++;
			j++;
			ic+=mid-i;
		}
	}
	cout<<"main while";
	while(i<left.size()){
		nums[k]=left[i];
		k++;
		i++;
	}
	while(j<right.size()){
		nums[k]=right[j];
		k++;
		j++;
	}
	
	return ic;
}
int invCount(vector<int> nums,int low,int high){
	int ic=0;
	if(low<high){
		int mid=(high+low)/2;
		ic+=invCount(nums,low,mid);
		ic+=invCount(nums,mid+1,high);
		ic+=merge(nums,low,mid,high);
	}
	return ic;
}
int main(){
	vector<int> nums={2,3,1,4,5};
	cout<<"Inversion Count is : "<<invCount(nums,0,nums.size()-1);
	


	
}