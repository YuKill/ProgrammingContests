#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>

#define MAX 99999999

using namespace std;

class Node {
    public:
        int cur;
        int oil;
        int w;
        Node();
};

Node::Node() {
    cur = 0;
    oil = 0;
    w = MAX;
}

class Comp {
    public:
        bool operator() (const Node &l, const Node &r) {
            return l.w > r.w;
        }
};

int len(int a[]) {
    return sizeof(a)/sizeof(int);
}

int dynamic_crazy(int cities, int price[], vector<int> edge[], vector<int> w[], int capacity) {
    int length = cities;

    priority_queue<Node, vector<Node>, Comp> queue;
    Node nodes[length][capacity+1];
    Node start;

    start.cur = 0;
    start.oil = capacity;
    start.w = 0;

    queue.push(start);

    while (!queue.empty()) {
        Node v = queue.top();
        queue.pop();

        int adj_count = 0;
        for (vector<int>::iterator it = edge[v.cur].begin(); it != edge[v.cur].end(); it++) {
            int adj = *it;
            for (int i = 0; i < (capacity - v.oil + 1); i++) {

                int cur_oil = v.oil + i - w[v.cur].at(adj_count);
                int cur_w = v.w + (i * price[v.cur]);
                if ((cur_oil >= 0) && ((nodes[adj][i].cur == 0) || (cur_w < nodes[adj][i].w))) {
                    
                    Node u;

                    u.cur = adj;
                    u.oil = cur_oil;
                    u.w = cur_w;

                    queue.push(u);
                    nodes[adj][i]= u;
                }
            }
            adj_count++;
        }
    }

    int min = MAX;
    for (int i = 0; i < capacity; i++) {
        if (nodes[length-1][i].w < min) 
            min = nodes[length-1][i].w;
        printf("----- %d\n", nodes[length-1][i].w);
    }
    
    if (min == MAX) return -1;
    return min;
}


int main() {


    int n_city, n_roads, capacity;

    scanf("%d %d %d", &n_city, &n_roads, &capacity);
    
    while ((n_city != 0) && (n_roads != 0) && (capacity != 0)) {

        int price[n_city];
        vector<int> edge[n_city];
        vector<int> w[n_city];

        int city_a, city_b, weight;
        for (int i = 0; i < n_roads; i++) {
            
            scanf("%d %d %d", &city_a, &city_b, &weight);

            edge[city_a-1].push_back(city_b-1);
            w[city_a-1].push_back(weight);
        }

        for (int i = 0; i < n_city; i++)
            scanf("%d", &price[i]);

        printf("%d\n", dynamic_crazy(n_city, price, edge, w, capacity));

        scanf("%d %d %d", &n_city, &n_roads, &capacity);
    }

}
