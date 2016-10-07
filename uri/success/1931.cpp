#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;

struct Edge {
  int U, V, W;
};

struct Vertex {
  int Parent;
  ll Cost;
};

struct CCompare {
  vector<Vertex> *V;
  CCompare(vector<Vertex> *V) : V(V) {}
  bool operator()(const int &One, const int &Two) {
    return (*V)[One].Cost > (*V)[Two].Cost;
  }
};

int main() {
  int C, V;
  cin >> C >> V;

  vector< vector<Edge> > AdjListOrig(C, vector<Edge>());
  for (int Vi = 0; Vi < V; ++Vi) {
    int u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    AdjListOrig[u].push_back({ u, v, w });
    AdjListOrig[v].push_back({ v, u, w });
  }

  vector< vector<Edge> > AdjList(C, vector<Edge>());
  for (int I = 0; I < C; ++I) {
    int U = I;
    vector<int> Cost(C, INT_MAX);
    for (int J = 0, Je = AdjListOrig[U].size(); J < Je; ++J) {
      int V = AdjListOrig[I][J].V;
      int UVCost = AdjListOrig[I][J].W;
      for (int K = 0, Ke = AdjListOrig[V].size(); K < Ke; ++K) {
        int Z = AdjListOrig[V][K].V;
        int VZCost = AdjListOrig[V][K].W;
        int PathCost = UVCost + VZCost;

        if (PathCost < Cost[Z])
          Cost[Z] = PathCost;
      }
    } 

    for (int J = 0; J < C; ++J)
      if (Cost[J] != INT_MAX)
        AdjList[U].push_back({ U, J, Cost[J] });
  }

  /*
  for (int I = 0; I < C; ++I) {
    cout << I << ": [ ";
    for (int J = 0; J < AdjListOrig[I].size(); ++J) 
      cout << AdjListOrig[I][J].V << " ";
    cout << "]" << endl;
  }

  cout << "----------------------" << endl;

  for (int I = 0; I < C; ++I) {
    cout << I << ": [ ";
    for (int J = 0; J < AdjList[I].size(); ++J) 
      cout << AdjList[I][J].V << " ";
    cout << "]" << endl;
  }
  */

  vector<int> Queue;
  for (int I = 0; I < C; ++I) 
    Queue.push_back(I);

  vector<Vertex> Vertices(C, { -1, LLONG_MAX });
  CCompare Compare(&Vertices);

  Vertices[0].Cost = 0;
  while (!Queue.empty()) {
    int U = Queue.front();
    pop_heap(Queue.begin(), Queue.end(), Compare);
    Queue.pop_back();
    if (Vertices[U].Cost == LLONG_MAX) break;

    bool Changed = false;
    for (int I = 0, E = AdjList[U].size(); I < E; ++I) {
      int V = AdjList[U][I].V;
      int W = AdjList[U][I].W;
      ll Cost = Vertices[U].Cost + W;
      if (Vertices[V].Cost > Cost) {
        Vertices[V].Cost = Cost; 
        Vertices[V].Parent = U; 
        Changed = true;
      }
    }

    if (Changed) make_heap(Queue.begin(), Queue.end(), Compare);
  }

  if (Vertices[C-1].Cost == LLONG_MAX) cout << "-1" << endl;
  else cout << Vertices[C-1].Cost << endl;

  return 0;
}
