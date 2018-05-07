#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
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

struct node * buildTree(int arr[], int start, int end)
{
    if (start > end)
      return NULL;

    int mid = (start + end)/2;
    struct node * rnode = (struct node *)malloc(sizeof(struct node));
    rnode -> data = arr[mid];
    rnode->left =  buildTree(arr, start, mid-1);
    rnode->right = buildTree(arr, mid+1, end);

    return rnode;
}
bool isBSTcheck(struct node *node,int min,int max){
    if(node==NULL){return true;}
    if(node->data<=min || node->data>=max){return false;}
    return isBSTcheck(node->left,min,node->data) && isBSTcheck(node->right,node->data,max);
}

bool isBST(struct node* node)
{
 return isBSTcheck(node,INT_MIN,INT_MAX);
}
int main() {
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    if(N%2==0)
        buildTree(arr, N);
    else
        root = buildTree(arr, 0, N-1);
    if(isBST(root))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
