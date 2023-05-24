#include<iostream>
#include<vector>
using namespace std;
	void merge(vector<int> &nums,int low,int mid,int high){
		vector<int> left;
		vector<int> right;
		for(int i=0;i<mid-low+1;i++){
			left.push_back(nums[low+i]);
		}
		for(int i=0;i<high-mid;i++){
			right.push_back(nums[mid+i+1]);
		}
		int i=0,j=0,k=low;
		while(i!=left.size() && j!=right.size()){ 
			if(left[i]<= right[j]){
				nums[k]=left[i];
				i++;
				k++;
			}
			else{
				nums[k]=right[j];
				k++;
				j++;
			}
		}
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
		
	}
	
	
int main(){
	vector<int> arr={6,5,4,3,2,1};
	int vecsize=arr.size();
	for(int asize=1;asize<vecsize;asize=asize*2){
		for(int low=0;low<vecsize;low+=2*asize){
			int mid=min(low+asize-1,vecsize-1);
			int high=min(low+2*asize-1,vecsize-1);
			merge(arr,low,mid,high);
		}
	}
	for(auto e:arr){
		cout<<e<<" ";
	}
		
	return 0;	
	}