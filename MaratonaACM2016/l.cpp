#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
  int h, l;
  cin >> h >> l;

  vector< vector<int> > mat(h, vector<int>(l, 0));
  vector< vector<bool> > visited(h, vector<bool>(l, false));

  for (int i = 0; i < h; ++i)
    for (int j = 0; j < l; ++j)
      cin >> mat[i][j];

  int minArea = INT_MAX;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < l; ++j) {
      if (!visited[i][j]) {
        int color = mat[i][j];
        int area = 0;
        vector< pair<int, int> > stack;
        stack.push_back(make_pair(i, j));
        visited[i][j] = true;
        while (!stack.empty()) {
          pair<int, int> coord = stack.back();
          stack.pop_back();
          ++area;

          int i = coord.first, j = coord.second;
          if (i > 0 && mat[i-1][j] == color && !visited[i-1][j]) {
            visited[i-1][j] = true;
            stack.push_back(make_pair(i-1, j));
          }

          if (i < h-1 && mat[i+1][j] == color && !visited[i+1][j]) {
            visited[i+1][j] = true;
            stack.push_back(make_pair(i+1, j));
          }

          if (j > 0 && mat[i][j-1] == color && !visited[i][j-1]) {
            visited[i][j-1] = true;
            stack.push_back(make_pair(i, j-1));
          }

          if (j < l-1 && mat[i][j+1] == color && !visited[i][j+1]) {
            visited[i][j+1] = true;
            stack.push_back(make_pair(i, j+1));
          }
        }

        if (area < minArea)
          minArea = area;
      }
    }

  cout << minArea << endl;

  return 0;
}
