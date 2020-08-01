1)Run length encoding
000011111110000001111111
3767
11111110111
uses in jpeg etc
#include <bits/stdc++.h> 
using namespace std; 
  
void printRLE(string str) 
{ 
    int n = str.length(); 
    for (int i = 0; i < n; i++) { 
  
        // Count occurrences of current character 
        int count = 1; 
        while (i < n - 1 && str[i] == str[i + 1]) { 
            count++; 
            i++; 
        } 
  
        // Print character and its count 
        cout << str[i] << count; 
    } 
} 
  
int main() 
{ 
    string str = "wwwwaaadexxxxxxywww"; 
    printRLE(str); 
    return 0; 
} 

//huffman compresssion
//uses variable length encoding(take care that no code is prefix of another)
//maybe use a stop character
//idea of huffman is to have prefix free codes and also using fewest bits
//trick is to arrange character based on frequency count from smallest to largest
//then put 0.1 accordingly
//lossless, can be implemented using leaf based trie or max heap
//nlogn where n is no of characters , extract min takes log n so n logn

//LZW compression
//best dictionary algorithm, doesnt encode single characters , minimum 2 character encoding
//lzw encoding https://www.youtube.com/watch?v=9gkiphD-VIY&t=2s
//lzw decoding https://www.youtube.com/watch?v=XSYSVEqFnes