class Stack{
public:
int a[MAX];
int top;
Stack(){
top=-1;	
}

int peek(){
	cout<<"top is"<<top<<endl;
	if(top<0){cout<<"Empty stack\n";return 0;}
	else
	return a[top];
}
void push(int x){
	if(top+1>=MAX)cout<<"Overflow\n";
	else
	{
		top++;
		a[top]=x;
		cout<<"Pushed "<<x<<"into the stack\n";
	}
}
void pop(){
	if(top==0)cout<<"Underflow\n";
	else{
		top--;
		
	}
}
bool empty(){
	return top<0;
}
};

