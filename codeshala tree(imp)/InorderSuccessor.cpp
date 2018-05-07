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

struct node * searchInBST(struct node * rnode, int a) {
	if(root == NULL)
		return NULL;

	while(rnode) {
		if(rnode -> data == a)
			return rnode;
		else if(rnode -> data > a)
			rnode = rnode -> left;
		else
			rnode = rnode ->right;
	}
	return NULL;
}


struct node * inOrderSuccessor(struct node * rnode, struct node * mnode)
{
 if(root==NULL || (root->left==NULL && root->right==NULL)){return NULL;}
 if(mnode->right!=NULL){
     node *temp=mnode->right;
     while(temp->left){
         temp=temp->left;
     }
     return temp;
 }
 else if(mnode->right==NULL){
     node * ans=NULL;
     node * temp=root;
     while(temp->data!=mnode->data){
         if(mnode->data<=temp->data){
             ans=temp;
             temp=temp->left;
         }
         else{temp=temp->right;}
     }
     return ans;
 }
}

int main() {
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int A;
	cin >> A;
	buildTree(arr, N);
	struct node * mnode = searchInBST(root, A);
	struct node * succ = inOrderSuccessor(root, mnode);
	if(succ)
	cout << succ -> data << endl;
	else
		cout << -1 << endl;
}
