#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>

using namespace std;

vector<int> potato;
vector< vector<int> > prob;
vector<bool> processed;

int dfs(int i, int j) {
  if (i >= j) return 1;
  if (prob[i][j] != -1) return prob[i][j];
  if (processed[j]) return 0;

  processed[j] = true;
  prob[i][j] = dfs(i, potato[j]);
  return prob[i][j];
}

int main() {
  int n, q;
  cin >> n >> q;

  potato.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> potato[i];
    --potato[i];
  }

  prob.assign(n, vector<int>(n, -1));
  for (int i = 0; i < n; ++i) {
    processed.assign(n, false);
    for (int j = 0; j <= i; ++j)
      prob[i][j] = 1;
    
    for (int j = i+1; j < n; ++j) {
      if (!processed[j] && prob[i][j] == -1)
        dfs(i, j);
    }
  }
  
  for (int i = 0; i < q; ++i) {
    int begin, end;
    cin >> begin >> end;
    --begin; --end;

    int minIdx = 0;
    double minProb = DBL_MAX;
    double eachProb = 1.0 / (end - begin + 1);

    int qtt = 0;
    for (int j = 0; j < n; ++j) {
      for (int k = begin; k <= end; ++k)
        qtt += prob[j][k];

      double p = abs(0.5 - (qtt * eachProb));
      double q = abs(0.5 - (1 - (qtt * eachProb)));
      if (p < minProb || q < minProb) {
        minProb = min(p, q);
        minIdx = j+1;
      }
    }

    cout << minIdx << endl;
  }

  return 0;
}
