#include <stdlib.h>

using namespace std;

#define ll long long

ll max(ll a, ll b) {
  return (a > b) ? a : b;
}

int bin_search(int i, int start, int end, int *finishTimeIndex, int *finishTime, int *startTime) {
  if (start > end)
    return end;
  int mid = start + ((end-start)/2);
  if (finishTime[finishTimeIndex[mid]] < startTime[finishTimeIndex[i]])
    return bin_search(i, mid+1, end, finishTimeIndex, finishTime, startTime);
  else
    return bin_search(i, start, mid-1, finishTimeIndex, finishTime, startTime);
  return mid;
}

ll WeightedActivitySelection(int n, int *w, int *finishTimeIndex, int *finishTime, int *startTime) {
  ll opt[n];
  opt[0] = w[finishTimeIndex[0]];
  for (int i = 1; i < n; i++) { 
    ll t = bin_search(i, 0, n-1, finishTimeIndex, finishTime, startTime); 
    if (t != -1)
      opt[i] = max(opt[i-1], opt[t] + w[finishTimeIndex[i]]);
    else
      opt[i] = max(opt[i-1], w[finishTimeIndex[i]]);
  }
  return opt[n-1];
}

