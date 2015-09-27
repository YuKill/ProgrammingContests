#include <stdio.h>

#define ll long long

ll longest_inc_seq(int *a, int n) {
  ll ans, m[n];

  for(int i = n-1; i >= 0; i--) {
    m[i] = 1;
    for(int j = i+1; j < n; j++) 
      if(a[j] > a[i] && m[i] < m[j] + 1)
          m[i] = m[j] + 1;
  }

  for(int i = 0; i < n; i++) 
    if (ans < m[i])
      ans = m[i];

  return ans;
}

