//if there are multiple overlapping intervals delete the one found (logn)then do overlap search again
#include <iostream>
using namespace std;
struct  interval{
 int low,high;	
};
struct Node{
	interval *iptr;
	int max;
	Node *left,*right;
};
Node *newnode(interval key){
	Node* temp=new Node;
	temp->iptr=new interval(key);
	temp->max=key.high;
	temp->left=temp->right=NULL;
	return temp;
}
//insertion is normal except the max value needs an update for ancestors when needed
Node* insert(Node* root,interval key){
	if(root==NULL)return newnode(key);
	if(key.low<root->iptr->low)
	root->left=insert(root->left,key);
	else
	root->right=insert(root->right,key);
	if(root->max<key.high)
	root->max=key.high;
	return root;
}
bool dooverlap(interval key1,interval key2){
	if(key1.high<key2.low||key1.low>key2.high) return false;
	return true;
}
interval* overlapsearch(Node*root,interval key){
	if(root==NULL)return NULL;
	if(dooverlap(key,*(root->iptr)))return root->iptr;
	//ifroot left is not null and root left maxis greater thant interval key then go left
	if(root->left!=NULL && root->left->max>=key.low)
	return overlapsearch(root->left,key);
	return overlapsearch(root->right,key);
}
void inorder(Node *root) 
{ 
    if (root == NULL) return; 
  
    inorder(root->left); 
  
    cout << "[" << root->iptr->low << ", " << root->iptr->high << "]"
         << " max = " << root->max << endl; 
  
    inorder(root->right); 
} 
int main() {
	interval ints[] = {{15, 20}, {10, 30}, {17, 19}, 
        {5, 20}, {12, 15}, {30, 40} 
    }; 
    int n = sizeof(ints)/sizeof(ints[0]); 
    Node *root = NULL; 
    for (int i = 0; i < n; i++) 
        root = insert(root, ints[i]); 
  
    cout << "Inorder traversal of constructed Interval Tree is\n"; 
    inorder(root); 
  
    interval x = {6, 7}; 
  
    cout << "\nSearching for interval [" << x.low << "," << x.high << "]"; 
    interval *res = overlapsearch(root, x); 
    if (res == NULL) 
        cout << "\nNo Overlapping Interval"; 
    else
        cout << "\nOverlaps with [" << res->low << ", " << res->high << "]"; 
    return 0; 

}