#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int partition(vector<int> &arr,int low,int high){
	int part=arr[high];
	int lswap=low-1;
	for(int j=0;j<=high-1;j++){
		if(arr[j]<=part){
			lswap++;
			swap(arr[lswap],arr[j]);
		}
	}
	swap(arr[lswap+1],arr[high]);
	return lswap+1;
}
//void Qs(vector<int> &arr,int low,int high){
//	if(low<high){
//		int p=partition(arr,low,high);
//		Qs(arr,low,p-1);
//		Qs(arr,p+1,high);
//	}
//}
void iterQs(vector<int> arr,int low,int high){
	stack<int> aux;
	aux.push(low);
	aux.push(high);
	while(!aux.empty()){
		high=aux.top();
		aux.pop();
		low=aux.top();
		aux.pop();
		
		int p=partition(arr,low,high);
//		cout<<p;
		
		if(p-1>low){
			aux.push(low);
			aux.push(p-1);
		}
		if(p+1<high){
			aux.push(p+1);
			aux.push(high);
		}
	}
}
int main(){
	vector<int> arr={6,5,4,3,2,1};
	iterQs(arr,0,arr.size()-1);
	for(auto e:arr){
		cout<<e<<"\t";
	}
	
}