#include <iostream>
#include <algorithm>
#include <queue>
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


bool isbalance=true;
int HeightBalanced(struct node * root){
    if(root==NULL){return 0;}
    int l=HeightBalanced(root->left);
    int r=HeightBalanced(root->right);
    if(abs(l-r)>1){isbalance=false;}
    return (1+max(l,r));
}
bool isBalancedTree(struct node * root) {
HeightBalanced(root);
return isbalance;
}
int main() {
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	buildTree(arr, N);
	if(isBalancedTree(root))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
