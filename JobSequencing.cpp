#include<iostream>
#include<vector>
using namespace std;
class item{
	public:
	int id;
	int profit;
	int deadline;
	
};
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
int maxProfit(vector<item> &items){
	int p=0;
	vector<int> sequence(items.size(),-1);
	for(int i=0;i<items.size();i++){
		if(sequence[items[i].deadline-1]==-1){
			sequence[items[i].deadline-1]=items[i].id;
			p+=items[i].profit;
		}
		else{
			int j=items[i].deadline-1;
			while(j>=0 && sequence[j]!=-1){
				j--;
			}
			if(j>=0){
			sequence[j]=items[i].id;
			p+=items[i].profit;
			}
		}
	}
//	for(int i=0;i<sequence.size();i++){
//		cout<<"ids are:"<<sequence[i];
//	}
	
	return p;
	
}
int main(){
	cout<<"enter no of jobs"<<endl;
	int size;
	cin>>size;
	vector<item> jobs; 
	for(int i=0;i<size;i++){
		item temp;
		cout<<"enter job profit"<<endl;
		cin>>temp.profit;
		cout<<"enter job deadline"<<endl;
		cin>>temp.deadline;
		temp.id=i+1;
		jobs.push_back(temp);
		
	}
	mergeSort(jobs,0,jobs.size()-1);
	
}