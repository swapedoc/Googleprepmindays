iterative inorder traversal without any space
(think threaded bst)
void morrisInorderTreeTraversal(Node *node){
	while(node){
		if(!node->left){
			printf("%d ", node->data);
			node = node->right;
		}else{
			
			Node *predecessor = findPredecessor(node);

			if(predecessor->right){
				predecessor->right = NULL;
				printf("%d ", node->data);
				node = node->right;
			}else{
				predecessor->right = node;
				node = node->left;
			}
		}
	}
	return;
}

Node *findPredecessor(Node *node){
	Node *temp;
	for(temp = node->left; temp->right && temp->right != node; temp = temp->right);
	return temp;
}
