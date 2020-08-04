negative numbers msb is 1
positive numbers msb is 0

they can also be represented in two's complement
so if 43 is 000101011
to get opposite of nuber ie -43 invert all digits then add 1
111010100 +1 =111010101

Overflow:
in signed representation next nuber after 2^(n-1)-1 is -2^(n-1)
in unsigned representatino next number after 2^n -1 is 0

to convert signed number x to unsigned=> do 2^n-x
eg -43 is 2^32-43 

xor operation output is 1 only when one number is 0 and other 1
not operation ~x=-x-1 eg ~29 = -30

number of form 1<<k has 1 bit in position k set and other bits are zero

to show  number in bit representation
for(int i=31;i>=0;i--){
	if(x&(1<<i) cout<<"1";
	else cout<<"0";
}
using this idea we can set single bits to one 
eg x|(1<<k)  sets kth bit to 1
   x&~(1<<k) sets kth bit to 0
   x^(1<<k)  inverts k th bit
  right shifting a number by x means dividing number by 2^x&
  eg 49>>3 means 49/2^3 =8
  to set last set bit to 0
  x&(x-1)
  if number is power of 2 then x&(x-1)=0
  
  x&-x sets all bits to 0 except last bit 
  eg 43&-43= 000101011&111010101=000000001
  
  bit representation of set {1,3,4,8} =
  00000000000100011010  
  
  code 
  int x = 0;
x |= (1<<1);
x |= (1<<3);
x |= (1<<4);
x |= (1<<8);

to print elements
for(int i=0;i<32;i++){
	if(x&(1<<i))cout<<1<<" ";
}

x Æ {1,3,4,8} and
y Æ {3,6,8,9}, and then constructs the set x union y {1,3,4,6,8,9}:
int x = (1<<1)|(1<<3)|(1<<4)|(1<<8);
int y = (1<<3)|(1<<6)|(1<<8)|(1<<9);
int z = x|y;
