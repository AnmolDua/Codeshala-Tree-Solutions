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

void printNodesInRange(struct node * root, int k1, int k2) {
if(root==NULL){return ;}
if(k1<root->data){printNodesInRange(root->left,k1,k2);}
if(k1<=root->data && k2>=root->data){cout<<root->data<<" ";}
if(k2>root->data){printNodesInRange(root->right,k1,k2);}

}

int main() {
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int A, B;
	cin >> A >> B;
	buildTree(arr, N);
	if(A > B) {
		B = A + B - (A = B);
	}
	printNodesInRange(root, A, B);
	cout << endl;
}
