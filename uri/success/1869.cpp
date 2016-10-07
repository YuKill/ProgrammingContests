#include <iostream>

using namespace std;

#define M1 0b11111
#define M2 0b1111100000
#define M3 0b111110000000000
#define M4 0b11111000000000000000
#define M5 0b1111100000000000000000000
#define M6 0b111110000000000000000000000000
#define M7 0b11111000000000000000000000000000000
#define M8 0b1111100000000000000000000000000000000000
#define M9 0b111110000000000000000000000000000000000000000
#define M10 0b11111000000000000000000000000000000000000000000000
#define M11 0b1111100000000000000000000000000000000000000000000000000
#define M12 0b111110000000000000000000000000000000000000000000000000000000
#define M13 0b1111000000000000000000000000000000000000000000000000000000000000

typedef unsigned long long ull;

int main() {
  ull N;
  char Lut[32] = { 
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
    'U', 'V' };

  while (cin >> N) {
    bool First = false;
    string S;
    S = S + Lut[(M13 & N) >> 60]; 
    S = S + Lut[(M12 & N) >> 55]; 
    S = S + Lut[(M11 & N) >> 50]; 
    S = S + Lut[(M10 & N) >> 45]; 
    S = S + Lut[(M9 & N) >> 40]; 
    S = S + Lut[(M8 & N) >> 35]; 
    S = S + Lut[(M7 & N) >> 30]; 
    S = S + Lut[(M6 & N) >> 25]; 
    S = S + Lut[(M5 & N) >> 20]; 
    S = S + Lut[(M4 & N) >> 15]; 
    S = S + Lut[(M3 & N) >> 10]; 
    S = S + Lut[(M2 & N) >> 5]; 
    S = S + Lut[(M1 & N) >> 0]; 

    int Count = 0;
    while (S[Count++] == '0');
    if (Count-1 == S.length()) cout << "0" << endl;
    else cout << S.substr(Count-1) << endl;
    if (!N) break;
  } 
}
