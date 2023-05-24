#include<iostream>
#include<vector>
#include<bits/stdc++.h>
class item{
	public:
	int id;
	float profit;
	int weight;
};
using namespace std;
void merge(vector<item> &items,int low,int mid,int high){
	vector<item> left;
	vector<item> right;
	for(int i=low;i<=mid;i++){
		left.push_back(items[i]);
	}
	for(int i=mid+1;i<=high;i++){
		right.push_back(items[i]);
	}
	int i=0,j=0,k=low;
	while(i<left.size() and j<right.size()){
		if(left[i].profit>=right[j].profit){
			items[k]=left[i];
			i++;
			k++;
		}
		else{
			items[k]=right[j];
			j++;
			k++;
		}
	}
	
	while(i<left.size()){
		items[k]=left[i];
		i++;
		k++;
	}
	while(j<right.size()){
		items[k]=right[j];
		j++;
		k++;
	}
	
}
void mergeSort(vector<item> &items,int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		mergeSort(items,low,mid);
		mergeSort(items,mid+1,high);
		merge(items,low,mid,high);
	}
}
int maxProfit(vector<item> &items,int W){
	mergeSort(items,0,items.size()-1);
	int p=0;
	for(int i=0;i<items.size();i++){
		if(W<=0){
			break;
		}
		else if(items[i].weight>W){
			p+=W*items[i].profit;
			W=0;
		}
		else{
			p+=items[i].weight*items[i].profit;
			W-=items[i].weight;
		}
	}
	return p;
}
int main(){
	int size;
	int W;
	cout<<"enter no of items"<<endl;
	cin>>size;
	cout<<"enter weight of knapsack"<<endl;
	cin>>W;
	vector<item> items;
	for(int i=0;i<size;i++){
		cout<<"enter profit and weight"<<endl;
		item temp;
		temp.id=i+1;
		cin>>temp.profit>>temp.weight;
		temp.profit=temp.profit/temp.weight;//replacing profit by profit/weight ratio
		items.push_back(temp);
	}
	cout<<"Maximum Profit with given data is "<<maxProfit(items,W)<<endl;
	return -1;
}