//same code for gen all subset or subsequence(but not substring)
#include <iostream>
using namespace std;
void gensubset(string output,string input){
	if(input.length()==0){cout<<output<<",";return;}
    string output1=output;
    string output2=output;
    output2.push_back(input[0]);
    input.erase(input.begin()+0);
	gensubset(output1,input);
	gensubset(output2,input);
}
int main() {
	// your code goes here
	string s;
	cin>>s;
	string output="";
	gensubset(output,s);
	return 0;
}