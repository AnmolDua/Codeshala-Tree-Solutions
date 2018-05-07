#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
#define ll long long int
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

/* Implement this method. */
void reverseLevelOrderTraversal(struct node * root) {
if(root==NULL){return ;}
queue<node *> q;
stack<node *> s;
q.push(root);s.push(root);
while(!q.empty()){
    node *t=q.front();q.pop();
    if(t->right!=NULL){q.push(t->right);s.push(t->right);}
    if(t->left!=NULL){q.push(t->left);s.push(t->left);}

}
while(!s.empty()){
    node *tp=s.top();s.pop();
    cout<<tp->data<<" ";
}
}

int main() {
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	buildTree(arr, N);
	reverseLevelOrderTraversal(root);
	cout << endl;
}
