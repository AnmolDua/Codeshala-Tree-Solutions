#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
#define ll long long int
#define f_in(st) freopen(st,"r",stdin);
#define f_out(st) freopen(st,"w",stdout);
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
void zigZagTraversal(struct node * root) {
stack<node*> s1; stack<node*> s2;
s1.push(root);
while(!s1.empty() || !s2.empty()){
    while(!s1.empty()){
        node *t1=s1.top();s1.pop();
        cout<<t1->data<<" ";
        if(t1->right!=NULL){s2.push(t1->right);}
        if(t1->left!=NULL){s2.push(t1->left);}
    }
    while(!s2.empty()){
        node *t2=s2.top();s2.pop();
        cout<<t2->data<<" ";
        if(t2->left!=NULL){s1.push(t2->left);}
        if(t2->right!=NULL){s1.push(t2->right);}
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
    zigZagTraversal(root);
    cout << endl;
}
