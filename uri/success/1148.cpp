#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

typedef long long ll;

struct iEdge {
  int V;
  int Cost;
};

struct vProp {
  ll Dist;
  int Parent;
};

struct HCompare {
  vector<vProp> *vProps;
  HCompare(vector<vProp> *vProps) : vProps(vProps) {}

  bool operator()(const int &One, const int &Two) {
    return (*vProps)[One].Dist > (*vProps)[Two].Dist; 
  }
};

void printProp(vProp &P) {
  cout << "{ " << P.Dist << ", " << P.Parent << " }" << endl;
}

int main() {
  int N, E;

  while (cin >> N >> E && (N || E)) {
    vector< map<int, int> > AdjList(N, map<int, int>());
    for (int Ei = 0; Ei < E; ++Ei) {
      int u, v, w;
      cin >> u >> v >> w;
      AdjList[u-1][v-1] = w;
    }

    int K;
    cin >> K;
    for (int Ki = 0; Ki < K; ++Ki) {
      int Src, Dst;
      cin >> Src >> Dst;

      vector<int> Queue;

      Queue.push_back(Src-1);
      for (int I = 0; I < N; ++I)
        if (I != Src-1 && I != Dst-1)
          Queue.push_back(I);
      Queue.push_back(Dst-1);

      vector<vProp> vProps(N, { LLONG_MAX, -1 });
      HCompare Compare(&vProps);

      vProps[Src-1].Dist = 0;
      while (!Queue.empty()) {
        int V = Queue.front();
        pop_heap(Queue.begin(), Queue.end(), Compare);
        Queue.pop_back();

        if (vProps[V].Dist == LLONG_MAX)
          break;

        bool Changed = false;
        for (auto Uit = AdjList[V].begin(), E = AdjList[V].end(); Uit != E; ++Uit) {
          int U = Uit->first;
          int W = Uit->second;
          if (AdjList[U].count(V) > 0)
            W = 0;

          ll Dist = vProps[V].Dist + W;
          if (vProps[U].Dist > Dist) {
            vProps[U].Dist = Dist;
            vProps[U].Parent = V;
            Changed = true;
          }
        }

        if (Changed)
          make_heap(Queue.begin(), Queue.end(), Compare);
      }

      if (vProps[Dst-1].Dist == LLONG_MAX) cout << "Nao e possivel entregar a carta" << endl;
      else cout << vProps[Dst-1].Dist << endl;
    }
    cout << endl;
  }

  return 0;
}
