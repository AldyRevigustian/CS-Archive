#include <stdio.h>
#include <stdlib.h>

struct Node{
	int key;
	int height;
	struct Node *left;
	struct Node *right;
}*root;

int height(struct Node *N){
	if(N == NULL) return 0;
	return N->height;
}

int max(int a, int b){
	return (a > b) ? a : b;
}

struct Node *leftRotate(struct Node *x){
	struct Node *y = x->right;
	struct Node *T2 = y->left;
	
	y->left = x;
	x->right = T2;
	
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	
	return y;
}

struct Node *rightRotate(struct Node *y){
	struct Node *x = y->left;
	struct Node *T2 = x->right;
	
	x->right = y;
	y->left = T2;
	
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	
	return x;
}


int getBalance(struct Node *N){
	if(N==NULL) return 0;
	return height(N->left) - height(N->right);
}


struct Node *insert(struct Node *node, int key){
	if(node == NULL){
		node = (struct Node*) malloc (sizeof(struct Node));
		node->key = key;
		node->height = 1;
		node->left = node->right = NULL;
	}
	else if(key < node->key){
		node->left = insert(node->left,key);
	}
	else{
		node->right = insert(node->right,key);
	}
	
	node->height = 1 + max(height(node->left), height(node->right));
	int balance = getBalance(node);
	
	if(balance > 1 && key < node->left->key) return rightRotate(node);
	if(balance < -1 && key > node->right->key) return leftRotate(node);
	
	if(balance > 1 && key > node->left->key){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	
	if(balance < -1 && key < node->right->key){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}

struct Node *maxNode(struct Node* node){
	while(node->right != NULL){
		node = node->right;
	}
	return node;
}

struct Node *remove(struct Node *node, int key){
	if (node == NULL){
		printf("%d is not found", key);
		return NULL;
	}
	else{
		if (key < node->key) node->left = remove(node->left,key);
		else if (key > node -> key) node->right = remove(node->right,key);
		else{
			if (node->left == NULL && node->right == NULL){ //leaf
				free(node);
				node = NULL;
			}
			else if(node->left == NULL){
				struct Node *temp = node;
				node = node->right;
				free(temp);
			}
			else if(node->right == NULL){
				struct Node *temp = node;
				node = node->left;
				free(temp);
			}
			else{
				struct Node *temp = maxNode(node->left);
				node->key = temp->key;
				node->left = remove(node->left, temp->key);
			}
		}
	}
	
	//	AVL
	if(node == NULL) return node;
	
	node->height = 1 + max(height(node->left), height(node->right));
	
	int balance = getBalance(node);
	if(balance > 1 && getBalance(node->left) >= 0) return rightRotate(node);
	if(balance < -1 && getBalance(node->right) <= 0) return leftRotate(node);
	
	if(balance > 1 && getBalance(node->left) < 0){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	
	if(balance < -1 && getBalance(node->right) > 0){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}


	return node;
}

void inOrder(struct Node *node){
	if(node != NULL){
		inOrder(node->left);
		printf("%d %d\n",node->key, node->height);
		inOrder(node->right);
	}
}

void preOrder(struct Node *node){
	if(node != NULL){
		printf("%d %d\n",node->key, node->height);
		preOrder(node->left);
		preOrder(node->right);
	}
}

void postOrder(struct Node *node){
	if(node != NULL){
		postOrder(node->left);
		postOrder(node->right);
		printf("%d %d\n",node->key, node->height);
	}
}

int main(){
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 7);
	root = insert(root, 15);
	root = insert(root, 20);
	root = insert(root, 17);
	inOrder(root);
	puts("");
	root = remove(root,17);
	inOrder(root);
	puts("");
	root = remove(root,20);
	inOrder(root);
	puts("");
	
//	root = insert(root,10);
//	root = insert(root,15);
//	root = insert(root,20);
//	root = insert(root,5);
//	root = insert(root,1);
//	root = insert(root,12);
//	root = insert(root,13);
//	root = insert(root,11);
//	root = insert(root,21);
//	root = insert(root,14);
//	inOrder(root);
	
	return 0;
}
