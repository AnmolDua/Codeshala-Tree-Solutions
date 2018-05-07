#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
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
int cnt=0;
int secondSmallestInBST(struct node * tNode) {
if(tNode==NULL){return INT_MAX;}
int temp1=secondSmallestInBST(tNode->left);
if(temp1!=INT_MAX){return temp1;}
cnt++;
if(cnt==2){return tNode->data;}
int temp2=secondSmallestInBST(tNode->right);
if(temp2!=INT_MAX){return temp2;} else{return INT_MAX;}
}



int main() {
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	buildTree(arr, N);
	cout << secondSmallestInBST(root) << endl;
}
