#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<int>> graph,vector<int> colors,int vertex,int color){
	for(int i=0;i<graph.size();i++){
		if(graph[vertex][i]==1 and color==colors[i]){
			return false;
		}
	}
	return true;
}
bool colorGraph(vector<vector<int>> graph,int m,vector<int> &colors,int vertex ){
	if(vertex==graph.size()){
		return true;
	}
	for(int c=1;c<=m;c++){
		if(isSafe(graph,colors,vertex,c)==true){
			colors[vertex]=c;
			if(colorGraph(graph,m,colors,vertex+1)==true){
				return true;
			}
			colors[vertex]=0;
		}
	}
	return false;
}
bool mColorProb(vector<vector<int>> graph,int m){
	vector<int> colors(graph.size(),0);
	
	if(colorGraph(graph,m,colors,0)==false){
		cout<<"sol dne"<<endl;
		return false;
	}
	
	for(auto e:colors){
		cout<<e;
	}
	cout<<endl;
	return true;
}

int main(){
	vector<vector<int>> graph={
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
	mColorProb(graph,3);
	return 0;
}