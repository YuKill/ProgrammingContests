#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define ll long long

#include <set>

ll getStartOf(ll N, ll I) {
  return (4 * ((I*N) - (I*I))) + 1;
}

ll getEndOf(ll N, ll I) {
  ++I;
  return 4 * ((I*N) - (I*I));
}

ll binarySearch(ll G, ll N, ll I, ll E) {
  ll Pivot = I + floor((E-I)/2.0);
  ll Start = getStartOf(N, Pivot);
  ll End = getEndOf(N, Pivot);
  if (G > End)
    return binarySearch(G, N, Pivot+1, E);
  else if (G < Start)
    return binarySearch(G, N, I, Pivot-1);
  else
    return Pivot;
}

int main() {
  ll N; 
  ll Graos;
  scanf("%lld %lld", &N, &Graos);

  if (Graos == N*N && N % 2 == 1) {
    printf("%lld %lld\n", (ll)ceil(N/2.0), (ll)ceil(N/2.0));
    exit(0);
  }

  ll Square = binarySearch(Graos, N, 0, floor(N/2.0));
  ll Start = getStartOf(N, Square);
  ll _N = N - 2*Square;

  ll X, Y;
  if (Start + _N > Graos) {
    // Up 
    X = Square + 1;
    Y = Square + 1 + Graos - Start;
  } else if (Start + 2*_N - 1 > Graos) {
    // Right 
    X = Square + 1 + Graos - (Start + _N - 1);
    Y = N - Square;
  } else if (Start + 3*_N - 2 > Graos) {
    // Down 
    X = N - Square;
    Y = (N - Square) - (Graos - (Start + 2*_N - 2));
  } else if (Start + 4*_N - 4 > Graos) {
    // Left 
    X = (N - Square) - (Graos - (Start + 3*_N - 3));
    Y = Square + 1;
  }

  printf("%lld %lld\n", X, Y);
  
}
