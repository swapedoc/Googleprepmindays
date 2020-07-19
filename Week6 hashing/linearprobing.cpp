//Linear probing

//We dont maintain any extra data structure in case of collision fill on n+1, n+2 entry etc
//array size must be greater than number of keys


#include<bits/stdc++.h>


#define MAX 10

class Hash

{

 private:

  int a[MAX];

 public:

 Hash();

 int create(int);

 void linear_prob(int,int),display();

};
Hash::Hash()

{

 int i;

 for(i=0;i<MAX;i++)

  a[i]=-1;

}
int Hash::create(int num)

{

 int key;

 key=num%10;

 return key;

}

void Hash::linear_prob(int key,int num)

{

 int flag,i,count=0;

 flag=0;

 if(a[key]==-1)//if the location indicated by hash key is empty

  a[key]=num;//place the number in the hash table

 else

 {

  i=0;

  while(i<MAX)

  {

 if(a[i]!=-1)

  count++;

 i++;

  }

 if(count==MAX)        //checking for the hash full

 {

 cout<<"\nHash Table Is Full Hence "<<num<<" Can not Be Inserted";

 display();

 getch();

 exit(1);

 }

 for(i=key+1;i<MAX;i++)//moving linearly down

 if(a[i]==-1)    // searching for empty location

 {

  a[i]=num;  //placing the number at empty location

  flag=1;

  break;

 }

 for(i=0;i<key&&flag==0;i++)//array from 0th to keyth loaction will be scanned

 if(a[i]==-1)

 {

  a[i]=num;

  flag=1;

  break;

 }

 } //outer else

}//end


void Hash::display()

{

 int i;

 cout<<"\n The Hash Table is..."<<endl;

 for(i=0;i<MAX;i++)

  cout<<"\n  "<<i<<"  "<<a[i];

}
int main()

{

 int num,key;

 char ans;

 Hash h;

 clrscr();

 cout<<"\nCollision Handling By Linear Probing";

 do

 {

  cout<<"\n Enter The Number";

  cin>>num;

  key=h.create(num);//returns hash key

  h.linear_prob(key,num);//collision handled by linear probing

  cout<<"\n Do U Wish To Continue?(y/n)";

  ans=getche();

 }while(ans=='y');

 h.display();//displays hash table

 getch();

}