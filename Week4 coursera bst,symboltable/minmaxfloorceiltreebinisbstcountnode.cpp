int minValue(struct node* node)  
{  
struct node* current = node;  
  
/* loop down to find the leftmost leaf */
while (current->left != NULL)  
{  
    current = current->left;  
}  
return(current->data);  
}  
  
 int maxValue(struct node* node) 
{    
    /* loop down to find the rightmost leaf */
    struct node* current = node; 
    while (current->right != NULL)  
        current = current->right; 
      
    return (current->data); 
} 

int floor(Node* root, int key) 
{ 
    if (!root) 
        return INT_MAX; 
  
    /* If root->data is equal to key */
    if (root->data == key) 
        return root->data; 
  
    /* If root->data is greater than the key */
    if (root->data > key) 
        return floor(root->left, key); 
  
    /* Else, the floor may lie in right subtree 
      or may be equal to the root*/
    int floorValue = floor(root->right, key); 
    return (floorValue <= key) ? floorValue : root->data; 
} 

int Ceil(node* root, int input) 
{ 
    // Base case 
    if (root == NULL) 
        return -1; 
  
    // We found equal key 
    if (root->key == input) 
        return root->key; 
  
    // If root's key is smaller, ceil must be in right subtree 
    if (root->key < input) 
        return Ceil(root->right, input); 
  
    // Else, either left subtree or root has the ceil value 
    int ceil = Ceil(root->left, input); 
    return (ceil >= input) ? ceil : root->key; 
} 


public int countNode(Node root){

        //base case
        if(root==null)
            return 0;

        //recursive call to left child and right child and
        // add the result of these with 1 ( 1 for counting the root)
        return 1 + countNode(root.left) + countNode(root.right);
    }
	
	count in range
	int getCount(node *root, int low, int high) 
{ 
    // Base case 
    if (!root) return 0; 
  
    // Special Optional case for improving efficiency 
    if (root->data == high && root->data == low) 
        return 1; 
  
    // If current node is in range, then include it in count and 
    // recur for left and right children of it 
    if (root->data <= high && root->data >= low) 
         return 1 + getCount(root->left, low, high) + 
                    getCount(root->right, low, high); 
  
    // If current node is smaller than low, then recur for right 
    // child 
    else if (root->data < low) 
         return getCount(root->right, low, high); 
  
    // Else recur for left child 
    else return getCount(root->left, low, high); 
} 


int dosize(Node* root){

        //base case
        if(root==NULL)
            return 0;

        //recursive call to left child and right child and
        // add the result of these with 1 ( 1 for counting the root)
        return 1 + dosize(root->left) + dosize(root->right);
    }
int rankof(Node * root, int key){
   int rank=0;
   while(root){
   	if(key<root->data)root=root->left;
   	else if(key>root->data){
   		cout<<root->data<<endl;
   		rank+=1+dosize(root->left);
   		root=root->right;
   	}
   	else
   	  return rank+dosize(root->left);
   }
   return 0;
}


bool isBSTUtil(struct Node* root, Node *&prev) 
{ 
    // traverse the tree in inorder fashion and  
    // keep track of prev node 
    if (root) 
    { 
        if (!isBSTUtil(root->left, prev)) 
          return false; 
   
        // Allows only distinct valued nodes  
        if (prev != NULL && root->data <= prev->data) 
          return false; 
   
        prev = root; 
   
        return isBSTUtil(root->right, prev); 
    } 
   
    return true; 
} 
  
bool isBST(Node *root) 
{ 
   Node *prev = NULL; 
   return isBSTUtil(root, prev); 
}