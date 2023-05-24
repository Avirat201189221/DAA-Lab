#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int longestCommonSubsequence(string text1, string text2,vector<vector<pair<int,char>>> &t) {
        for(int i=0;i<=text1.size();i++){
            t[i][0].first=0;
            t[i][0].second='i';
        }
        for(int i=0;i<=text2.size();i++){
            t[0][i].first=0;
            t[0][i].second='i';
        }
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    t[i][j].first=t[i-1][j-1].first+1;
                    t[i][j].second='d';
                }
                else{
                    if(t[i-1][j]>=t[i][j-1]){
                    	t[i][j].first=t[i-1][j].first;
                    	t[i][j].second='t';
					}
					else{
						t[i][j].first=t[i][j-1].first;
						t[i][j].second='l';
					}
                }
            }
        }
        return t[text1.size()][text2.size()].first;
}

int main(){
	string s1,s2;
	cout<<"enter first string"<<endl;
	cin>>s1;
	cout<<"enter second string"<<endl;
	cin>>s2;
	vector<vector<pair<int,char>>> t(s1.size()+1,vector<pair<int,char>>(s2.size()+1));
	int ans=longestCommonSubsequence(s1,s2,t);
	cout<<"Length Of LCS is :"<<ans<<endl;
	string res;
	
	int i=s1.size(),j=s2.size();
	while(i>0 && j>0){
		if(t[i][j].second=='d'){
			res.push_back(s1[i-1]);
			i--;
			j--;
		}
		else if(t[i][j].second=='l'){
			j--;
		}
		else{
			i--;
		}
	}
//	for(int i=0;i<t.size();i++){
//		for(int j=0;j<t[0].size();j++){
//			cout<<t[i][j].first<<t[i][j].second<<" ";
//		}
//		cout<<endl;
//	}
	cout<<"lcs is:";
	for(int k=res.size()-1;k>=0;k--){
		cout<<res[k];
	}
	return 8;
}
