kmp doesnt backup, depends on deterministic finite state automaton
prefix of pattern =suffix of string
complexity +n
#include <iostream>
#include <vector>
using namespace std;
vector<int>pit;
vector<int> pitable(string pattern){
	vector<int>pit(pattern.size(),0);
	for(int i=1;i<pattern.size();i++){
		int j=pit[i-1];
		while(j>0 && pattern[i]!=pattern[j])
		j=pit[j-1];
		if(pattern[i]==pattern[j] )
		j++;		
		pit[i]=j;	
		}
	
	return pit;
}
int main() {
    string str,pattern;
    cin>>str>>pattern;
    vector<int>pita=pitable(pattern);
    int k=0;
    //bool flag=false;
    int index=-1;
   // cout<<"hi"<<endl;
    //cout<<pita.size();
    
    //for(int i=0;i<pita.size();i++)
   // cout<<pita[i]<<" ";
    int i=0,j=0;
    while(i<str.size()){
    	if(str[i]==pattern[j]){
    		j++;
    		i++;
    	}
    	if(j==pattern.size()){
    		index=i-j;
    		j=pita[j-1];
    	}
    	else if(i<str.size() && pattern[j]!=str[i]){
    		if(j!=0)j=pita[j-1];
    		else i++;
    	}
    }
    
    cout<<"index is" << index;
	// your code goes here
	return 0;
}