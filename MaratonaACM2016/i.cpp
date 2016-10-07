#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n, 0);
  for (int i = 0; i < n; ++i) 
    cin >> v[i];

  vector<int> rise(n, 0), fall(n, 0);

  rise[0] = 1;
  for (int i = 1; i < n; ++i)
    rise[i] = min(rise[i-1] + 1, v[i]);

  fall[n-1] = 1;
  for (int i = n-2; i >= 0; --i)
    fall[i] = min(fall[i+1] + 1, v[i]);

  int maxH = 0;
  for (int i = 0; i < n; ++i)
    maxH = max(maxH, min(rise[i], fall[i]));

  cout << maxH << endl;

  return 0;
}
