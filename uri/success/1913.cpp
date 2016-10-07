#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define VERM 0
#define LA 1
#define VERD 2
#define AZ 3

using namespace std;

typedef long long ll;

struct Block {
  int H, R, C; 
};

int N;
vector<Block> Blocks;

bool canPlace(int I, int Last) {
  if (Last == -1) return true;
  if (Blocks[I].R == Blocks[Last].R) return false;
  switch (Blocks[I].C) {
    case VERM: 
      return Blocks[Last].C != LA;
    case VERD: 
      return Blocks[Last].C != VERM;
    case LA: 
      return Blocks[Last].C != AZ;
    case AZ: 
      return Blocks[Last].C != VERD;
  }
}

bool byRadius(Block I, Block J) {
  return I.R < J.R;
}

int main() {
  while (cin >> N && N) {
    vector<ll> HMap(N, 0);
    Blocks.assign(N, {0, 0, 0});
    for (int I = 0; I < N; ++I) {
      string ColorStr;
      cin >> Blocks[I].H >> Blocks[I].R >> ColorStr;
      if (ColorStr == "VERMELHO") Blocks[I].C = VERM;
      else if (ColorStr == "LARANJA") Blocks[I].C = LA;
      else if (ColorStr == "VERDE") Blocks[I].C = VERD;
      else Blocks[I].C = AZ;
    }

    sort(Blocks.begin(), Blocks.end(), byRadius);

    ll MaxHeight = 0;
    for (int I = 0; I < N; ++I) {
      ll Max = Blocks[I].H;
      for (int J = 0; J < I; ++J) {
        if (canPlace(J, I)) {
          Max = max(Max, HMap[J] + Blocks[I].H);
        }
      }
      HMap[I] = Max;
      if (Max > MaxHeight)
        MaxHeight = Max;
    }

    cout << MaxHeight << " centimetro(s)" << endl;
  }

  return 0;
}
