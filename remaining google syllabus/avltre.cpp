avl tree :- a bst whose balance factor(dif of lenfth of nodes in left and right subtree is -1,0,1}
balance=height of left-height of right
same code as red black except we take care of height too
red black 
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
 
 Avl

 Right rotation
 Node* rotateright(Node* root){
   Node *x=root->left;
   root->left=x->right;
   x->right=root;
   root->height=max(height(root->left),height(root->right))+1;
   x->height=max(heigh(root->left),height(root->right))+1
   return root;
 }
 
 same for left rottion update heights
 
 here make one more function balance to check for >1 ,<-1
 if >1 that means left tree is very long , so we right rotate etc 
 this balancing is taken care of during insertion
 complexity O(log n)