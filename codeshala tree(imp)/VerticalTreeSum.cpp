#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include<bits/stdc++.h>
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

vector<long long int> verticalSum(struct node * root) {
queue<pair<node*,long long int> >q;
vector<long long int> v;
map<long long int,long long int> m;
q.push(make_pair(root,0));

while(!q.empty()){
    pair<node*,int>p;
    p=q.front();q.pop();
    node *t=p.first; int val=p.second;
    if(m.find(val)==m.end()){m[val]=t->data;}
    else {m[val]+=t->data;}
    if(t->left!=NULL){q.push(make_pair(t->left,val-1));}
    if(t->right!=NULL){q.push(make_pair(t->right,val+1));}
}
for(auto it=m.begin();it!=m.end();it++){
    v.push_back(it->second);
}
return v;
}

int main() {
	int N;
	cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	buildTree(arr, N);
	vector<long long int> P = verticalSum(root);
	for(int i = 0; i < P.size(); i++) {
		if(i)
			cout << " ";
		cout << P[i];
	}
	cout << endl;
}
