#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int data;
	struct node * left;
	struct node * right;
} * root = NULL;

struct node * insertNode(struct node * tNode, int value) {
	if(tNode == NULL) {
		struct node * newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	if(tNode->data > value)
		tNode->left = insertNode(tNode->left, value);
	else
		tNode->right = insertNode(tNode->right, value);
	return tNode;
}

void buildTree(int a[], int N) {
	for(int i = 0; i < N; i++) {
		if(i) {
			insertNode(root, a[i]);
		} else {
			root = insertNode(NULL, a[i]);
		}
	}
}

void inOrderTraversal(struct node * tNode) {
	if(tNode == NULL)
		return;
	inOrderTraversal(tNode->left);
	cout << tNode->data << endl;
	inOrderTraversal(tNode->right);
}

/*
Return True, if value is present in BST
else return False.
*/
bool isValuePresentInBST(struct node * tRoot, int value) {
if(tRoot==NULL){return false;}
else if(tRoot->data==value){return true;}
else if(value<=tRoot->data){return isValuePresentInBST(tRoot->left,value);}
else{return isValuePresentInBST(tRoot->right,value);}
}

int main() {
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	buildTree(arr, N);
	for(int i = 1; i<= 1000; i++) {
		if(isValuePresentInBST(root, i))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
