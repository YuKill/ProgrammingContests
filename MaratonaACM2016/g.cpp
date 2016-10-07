#include <iostream>
#include <vector>

using namespace std;

#define ll long long

struct Tile {
  ll b, w;
};

int main() {
  int n, p;
  cin >> n >> p;

  vector< vector< vector<Tile> > > mat(2, vector< vector<Tile> >(n, vector<Tile>(n, {0, 0})));

  for (int i = 0; i < p; ++i) {
    int l, c;
    cin >> l >> c;
    mat[0][l-1][c-1].b = 1;
  }

  for (int i = 0; i < p; ++i) {
    int l, c;
    cin >> l >> c;
    mat[0][l-1][c-1].w = 1;
  }


  ll blkV = p, whtV = p;
  int cur = 1, aux = 0;
  for (int k = 2; k <= n; ++k) {
    int begin = k-1;
    for (int i = begin; i < n; ++i) {
      for (int j = begin; j < n; ++j) {
        mat[cur][i][j].b = mat[aux][i][j].b + mat[aux][i-1][j].b +
          mat[aux][i][j-1].b + mat[aux][i-1][j-1].b;
        mat[cur][i][j].w = mat[aux][i][j].w + mat[aux][i-1][j].w +
          mat[aux][i][j-1].w + mat[aux][i-1][j-1].w;
        if (!mat[cur][i][j].w && mat[cur][i][j].b) ++blkV;
        if (!mat[cur][i][j].b && mat[cur][i][j].w) ++whtV;
      }
    }
    aux = !aux;
    cur = !cur;
  }

  cout << blkV << " " << whtV << endl;

  return 0;
}
