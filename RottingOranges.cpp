#include<queue>
#include<utility>
#include<iostream>
#include<vector>
using namespace std;
    bool isValid(int row,int column,int rows,int columns,vector<vector<int>> grid){
//	cout<<row<<column<<rows<<columns;
	if(row<rows && column<columns && row>=0 && column>=0){
		if(grid[row][column]==1){
//		cout<<row<<column<<"is valid working";
		return true;
	}
		else{
			return false;
		}
	}
	return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()==0){
            return -1;
        }
    queue<pair<int,int>> q;
	int days=0;
    int ones=0;
	int zeroes=0;
	//queue mein daal diya bro
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[0].size();j++){
			if(grid[i][j]==2){
				q.push({i,j});
				// cout<<"conditional working";
			}
            else if(grid[i][j]==1){
                ones++;
            }
            else{
                zeroes++;
            }
		}
	}
	if(q.size()==0){
        if(ones!=0)
            return -1;
        else{
            return 0;
        }
    }
	//bfs kar rahe bro
	while(q.size()!=0){
//		cout<<"starting bfs";
		int size=q.size();
		for(int i=0;i<size;i++){
			pair<int,int> temp=q.front();
//			cout<<temp.first<<temp.second;
			//i-1,j->left
			if(isValid(temp.first-1,temp.second,grid.size(),grid[0].size(),grid)){
				q.push({temp.first-1,temp.second});
				grid[temp.first-1][temp.second]=2;
//				cout<<"left conditional triggered";
			}
			//i+1,j->right
			if(isValid(temp.first+1,temp.second,grid.size(),grid[0].size(),grid)){
				q.push({temp.first+1,temp.second});
				grid[temp.first+1][temp.second]=2;
//				cout<<"right conditional triggered";
			}
			//i,j+1->up
			if(isValid(temp.first,temp.second+1,grid.size(),grid[0].size(),grid)){
				q.push({temp.first,temp.second+1});
				grid[temp.first][temp.second+1]=2;
//				cout<<"up conditional triggered";
			}
			//i,j-1->down
			if(isValid(temp.first,temp.second-1,grid.size(),grid[0].size(),grid)){
				q.push({temp.first,temp.second-1});
				grid[temp.first][temp.second-1]=2;
//				cout<<"down conditional triggered";
			}
			
			//popping from q
			q.pop();
		}
		days++;
		
	}
	//verify kar rahe yaar
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[0].size();j++){
			if(grid[i][j]==1){
				return -1;
			}
		}
	}
	return days-1;
	
    }
int main(){
	int rows;
	int columns;
	cin>>rows>>columns;
	vector<vector<int>> myvec;

	for(int i=0;i<rows;i++){
		vector<int> temp;
		for(int j=0;j<columns;j++){
			int element;
			cin>>element;
			temp.push_back(element);
		}
		myvec.push_back(temp);
	}
	int ans=orangesRotting(myvec);
	cout<<"\n";
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			cout<<myvec[i][j];
		}
		cout<<"\n";
	}
	cout<<ans;
	
	
}