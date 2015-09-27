#include <stdlib.h>
#include <stdio.h>


class Node {
    public:
        int n;
        Node *l, *r;
        Node();
};

Node::Node() {
    l = NULL;
    r = NULL;
}

using namespace std;

int index, a, b, c, *av, *bv, *cv;
Node *nds;

Node *get_node() {
    return &nds[index++];
}

void add_node(Node **n, int x) {
    if (n[0] == NULL) {
        n[0] = get_node();
        n[0]->n = x;
    } else {
        if (x > n[0]->n)
            add_node(&n[0]->r, x);
        else
            add_node(&n[0]->l, x);
    }
}

void search(Node *n) {
    
    if (n == NULL)
        return;
    av[a++] = n->n;
    search(n->l);
    bv[b++] = n->n;
    search(n->r);
    cv[c++] = n->n;

}

void print_abc(int v[], int x) {

    for (int i = 0; i < x; i++)
        printf(" %d", v[i]);
}

int main() {

    int tests;
    scanf("%d", &tests);
    
    Node *head;

    for (int i = 0; i < tests; i++) {
        index = 0;
        head = NULL;

        int num;
        scanf("%d", &num);
    
        Node nodes[num];
        nds = nodes;
        int number;
        int pre[num], in[num], pos[num];
        a = 0;
        b = 0;
        c = 0;
        av = pre;
        bv = in;
        cv = pos;
        for (int j = 0; j < num; j++) {
            scanf("%d", &number);
            add_node(&head, number);
        }

        search(head);
        printf("Case %d:\n", i+1);
        printf("Pre.:");
        print_abc(pre, num);
        printf("\n");
        printf("In..:");
        print_abc(in, num);
        printf("\n");
        printf("Post:");
        print_abc(pos, num);
        printf("\n\n");

    }

}
