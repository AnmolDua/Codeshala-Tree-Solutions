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

/* Implement this method */
void topView(struct node * root) {
if(root==NULL){return;}
queue<pair<node*,int> >q;
q.push(make_pair(root,0));
map<int ,int > m;
while(!q.empty()){
    pair<node*,int> p;p=q.front();q.pop();
    node * t=p.first; int val=p.second;
    if(m.find(val)==m.end()){m[val]=t->data;}
    if(t->left!=NULL){q.push(make_pair(t->left,val-1));}
    if(t->right!=NULL){q.push(make_pair(t->right,val+1));}
}
for(auto it=m.begin();it!=m.end();it++){cout<<it->second<<" ";}
}

int main() {
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    buildTree(arr, N);
    topView(root);
    cout << endl;
}
