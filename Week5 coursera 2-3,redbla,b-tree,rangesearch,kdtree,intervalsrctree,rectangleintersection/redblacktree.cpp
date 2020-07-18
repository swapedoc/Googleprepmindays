//left linear red black tree
static bool RED=true;
static bool BLACK=false;
classs Node {
int data;
Node* left, right;
bool color;
}

bool isred(Node* root){
if(root==NULL) return false;
return (root->color==RED);
}

Left rotation
 Node * rotateleft(Node* root){
   Node *x=root->right;
   root->right=x->left;
   x->left=root;
   x->color=root->color;
   root->color=RED;
   return root;
 }
 Right rotation
 Node* rotateright(Node* root){
   Node *x=root->left;
   root->left=x->right;
   x->right=root;
   x->color=root->color;
   root->color=RED;
   return root;
 }
 void flipcolors(Node* root){
  assert !isred(root);
  assert isred(root->left);
  assert isred(root->right);
  root->color=RED;
  root->left->color=BLACK;
  root->right->color=BLACK;
 }
 
 Node * insert(Node* root, int val){
 
    if(!root) 
    {  
        return new BST(value); 
    } 
  
    // Insert data. 
    if(value > root->data) 
    { 
        
        root->right = Insert(root->right, value); 
    } 
    else
    { 
        
        root->left = Insert(root->left, value); 
    } 
 if(isred(root->right) && !isred(root->left))root=rotateleft(root);
  if(isred(root->left) && isred(root->left->left))root=rotateright(root);
  if(isred(root->left) && isred(root->right)) flipcolors(root);
 }
 
 Generalized queue. Design a generalized queue data type that supports all of the following operations in logarithmic time (or better) in the worst case.

Create an empty data structure.
Append an item to the end of the queue.
Remove an item from the front of the queue.
Return the ith item in the queue.
Remove the ith item from the queue.

create a red–black BST where the keys are integers and the values are the items such that the i^{th}i 
th
  largest integer key in the red–black BST corresponds to the i^{th}i 
th
  item in the queue.