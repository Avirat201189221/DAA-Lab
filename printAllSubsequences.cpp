#include<iostream>
using namespace std;
void printAll(string s,string o,int index){
	if(index<s.size()){
	printAll(s,o,index+1);
	printAll(s,o+s[index],index+1);
	}
	cout<<o<<endl;
	return ;
}
int main(){
	string s="abc";
	string o="";
	printAll(s,o,0);
	return 0;
}