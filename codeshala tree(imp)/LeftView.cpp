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

void printLeftView(struct node * tNode) {
if(tNode==NULL){return;}
queue<node*> q;
q.push(tNode);
while(!q.empty())
{
    int s=q.size();int cnt=0;
    while(cnt<s){
        node * t=q.front();q.pop();
        if(cnt==0){cout<<t->data<<endl;}
        if(t->left!=NULL){q.push(t->left);}
        if(t->right!=NULL){q.push(t->right);}
        cnt++;
    }
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
	printLeftView(root);
}
