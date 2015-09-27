#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int p, pr, d;

class Node {
    public:
        int n;
        Node *left, *right;
        Node();
};

Node::Node() {
    n = 0;
    left = NULL;
    right = NULL;
}

class BinaryTree {
    public:
        Node *head;
        int *pre, *in, *pos;

        BinaryTree();
        void add_node(Node**,int);
        void search(Node*);
        void set_up(int[], int[], int[]);
};

BinaryTree::BinaryTree() {
    head = NULL;
    pre = NULL;
    in = NULL;
    pos = NULL;
}

void BinaryTree::set_up(int a[], int b[], int c[]) {
    pre = a;
    in = b;
    pos = c;
}

void BinaryTree::add_node(Node **h, int x) {
    if (h[0] == NULL) {
        h[0] = new Node();
        h[0]->n = x;
    } else {
        if (x > h[0]->n)
            add_node(&h[0]->right, x);
        else
            add_node(&h[0]->left, x);
    }
}

void BinaryTree::search(Node *h) {
    
    if (h == NULL) 
        return;
    pre[pr++] = h->n;
    search(h->left);
    in[d++] = h->n;
    search(h->right);
    pos[p++] = h->n;
}

void print_search(int v[], int x) {
    for (int i  = 0; i < x; i++)
        printf(" %d", v[i]);
}

int main() {
    
    int tests;
    scanf("%d", &tests);


    for (int i = 0; i < tests; i++) {
        BinaryTree bt;
        
        int n_numbers;
        scanf("%d", &n_numbers);
        

        int a[n_numbers], b[n_numbers], c[n_numbers];
        bt.set_up(a, b, c);
        int num[n_numbers];
        for (int j = 0; j < n_numbers; j++) {
            scanf("%d", &num[j]);
        }
        
        for (int j = 0; j < n_numbers; j++) 
            bt.add_node(&bt.head, num[j]);
        
        p = 0;
        pr = 0;
        d = 0;
        bt.search(bt.head);

        printf("Case %d:\n", i+1);
        printf("Pre.:");
        print_search(bt.pre, n_numbers);
        
        printf("\n");
        printf("In..:");
        print_search(bt.in, n_numbers);
        
        printf("\n");
        printf("Post:");
        print_search(bt.pos, n_numbers);
        
        printf("\n");
        printf("\n");
    }
}
