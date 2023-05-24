#include<iostream>
#include<vector>
using namespace std;
    int cSum(vector<int> &nums, int low, int mid, int high){
        int lSum=INT_MIN;
        int runsum=0;
        for(int i=mid;i>=0;i--){
            runsum+=nums[i];
            lSum=max(lSum, runsum) ;
        }
        int rSum=INT_MIN;
        runsum=0;
        for(int i=mid+1;i<=high;i++){
            runsum+=nums[i];
            rSum=max(rSum,runsum) ;
        }
        return max(lSum, max(lSum+rSum, rSum)) ;
    }
    int maxSub(vector<int> &nums,int low, int high) {
        if(low==high) 
            return nums[low];
        int mid=(low+high)/2;
        int leftSum=maxSub(nums,low,mid);
        int rightSum=maxSub(nums,mid+1, high);
        int crossSum=cSum(nums,low,mid,high);
        
        return max(leftSum,max(rightSum,crossSum));
    }

int main(){
	vector<int> arr={2,-1,5,-3,6,-7};
	cout<<maxSub(arr,0,arr.size()-1);
	
}