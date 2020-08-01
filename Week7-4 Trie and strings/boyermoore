#include <iostream>
#include <vector>
using namespace std;
vector<char> preprocess(string pattern){   //bad char heuristic worst case o(mn) best O(n/m)
	vector<char>right(256,-1);
	for(int i=0;i<pattern.size();i++)
	right[(int)pattern[i]]=i;
	return right;
}
int search(string str,string pattern){
	vector<char>badh=preprocess(pattern);
	int skip;
	int n=str.size();
	int m=pattern.size();
	for(int i=0;i<=n-m;i+=skip){
		skip=0;
		for(int j=m-1;j>=0;j--){             //preprocess pattern from right to left
			if(pattern[j]!=str[i+j]){
				skip=max(1,j-badh[str[i+j]]);  //for negative term, usually -1 so it will jump
				break;
			}
		}
		if(skip==0)return i;
	}
	return n;
}
int main() {
    string str,pattern;
    cin>>str>>pattern;
   
    int index=search(str,pattern);
    cout<<"index is " << index;
	// your code goes here
	return 0;
}