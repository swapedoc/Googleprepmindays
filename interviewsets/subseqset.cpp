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


//using bit
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	char ar[]={'a','b','c'};
	int n;
		cin>>n;
	    int tot=1<<n;
		for(int i=0;i<tot;i++){
			for(int j=0;j<n;j++){
				if(i&(1<<j)){cout<<ar[j];}    ///  (0,10,11,100,101,110,111)get matched to(01,10,100),based on what is set we take values
			}
			cout<<endl;
		}
	
	return 0;
}