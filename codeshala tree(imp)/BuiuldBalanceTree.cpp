#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node {
	int data;
	struct node * left;
	struct node * right;
} * root = NULL;
node * getnewnode(int value){
node* newnode=new node();
newnode->data=value;
newnode->left=newnode->right=NULL;
return newnode;
}
struct node * buildTree(int a[], int start,int end) {
if(start>end){return NULL;}
int mid=(start+end)/2;
node * root=new node();
root->data=a[mid];
root->left=buildTree(a,start,mid-1);
root->right=buildTree(a,mid+1,end);
return root;
}

bool isBalancedTree(struct node * root, int* height) {
  int lh = 0, rh = 0;
  int l = 0, r = 0;

  if(root == NULL)
  {
    *height = 0;
     return 1;
  }

  l = isBalancedTree(root->left, &lh);
  r = isBalancedTree(root->right,&rh);
  *height = (lh > rh? lh: rh) + 1;
  if((lh - rh >= 2) || (rh - lh >= 2))
    return 0;

  else return l&&r;
}

int main() {
	int N, height = 0;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	buildTree(arr, 0,N-1);
	if(isBalancedTree(root, &height))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
