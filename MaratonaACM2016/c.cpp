#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

struct Node {
  vector< vector<int> > mat;
  int w, total;

  Node() {
    mat.assign(2, vector<int>(4, 0));
    total = INT_MAX;
    w = 0;
  }

  string toString() {
    string s = "";
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 4; ++j) {
        s += to_string(mat[i][j]) + "|";
      }
    return s;
  }

  bool equal(Node &n) {
    return this->toString() == n.toString();
  }
};

struct HeapCmp {
  vector<Node> *nodes;
  HeapCmp(vector<Node> *nodes) : nodes(nodes) {}
  bool operator()(const int one, const int two) {
    return (*nodes)[one].total > (*nodes)[two].total;
  }
};

void generateNodes(Node &n, vector<Node> &child) {
  for (int i = 0; i < 3; ++i) {
    Node node;
    node.mat = n.mat;
    swap(node.mat[0][i], node.mat[0][i+1]);
    node.w = node.mat[0][i] + node.mat[0][i+1];
    child.push_back(node);
  }

  for (int i = 0; i < 3; ++i) {
    Node node;
    node.mat = n.mat;
    swap(node.mat[1][i], node.mat[1][i+1]);
    node.w = node.mat[1][i] + node.mat[1][i+1];
    child.push_back(node);
  }

  for (int i = 0; i < 4; ++i) {
    Node node;
    node.mat = n.mat;
    swap(node.mat[0][i], node.mat[1][i]);
    node.w = node.mat[0][i] + node.mat[1][i];
    child.push_back(node);
  }
}

int main() {
  long long beginT, endT;

  Node start, end;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 4; ++j)
      cin >> start.mat[i][j];
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 4; ++j)
      cin >> end.mat[i][j];

  start.total = 0;

  if (start.equal(end)) {
    cout << "0" << endl;
    return 0;
  }


  vector<Node> nodes(40330, Node());
  nodes[0] = start;
  nodes[1] = end;

  unordered_map<string, int> nodeIdxMap;
  unordered_map<int, bool> visited;

  nodeIdxMap[start.toString()] = 0;
  nodeIdxMap[end.toString()] = 1;

  int nodeCount = 2;

  vector<int> q;
  q.push_back(0);
  HeapCmp compare(&nodes);
  while (!q.empty()) {
    int idx = q.front();
    pop_heap(q.begin(), q.end(), compare);
    q.pop_back();

    if (visited[idx]) continue;
    visited[idx] = true;

    if (idx == 1) break;

    vector<Node> childrem;
    generateNodes(nodes[idx], childrem);

    for (int i = 0, e = childrem.size(); i < e; ++i) {
      string key = childrem[i].toString();
      // cout << "from:" << nodes[idx].toString() << " to:" << key << endl;
      // cout << "w: " << nodes[idx].total << " total: " << nodes[idx].total + childrem[i].w << endl;
      if (!nodeIdxMap.count(key)) {
        childrem[i].total = nodes[idx].total + childrem[i].w;

        visited[nodeCount] = false;
        nodeIdxMap[key] = nodeCount;
        nodes[nodeCount] = childrem[i];

        q.push_back(nodeCount);
        push_heap(q.begin(), q.end(), compare);

        ++nodeCount;
      } else {
        int childIdx = nodeIdxMap[key];
        int total = nodes[idx].total + childrem[i].w;
        if (total < nodes[childIdx].total) {
          nodes[childIdx].total = total;
          q.push_back(childIdx);
          push_heap(q.begin(), q.end(), compare);
        }
      }
    }
  }

  cout << nodes[1].total << endl;

  return 0;
}
