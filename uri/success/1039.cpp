#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

int main() {
  ll Rc, Xc, Yc, Rf, Xf, Yf;
  while (cin >> Rc >> Xc >> Yc >> Rf >> Xf >> Yf) {
    double Dist = sqrt(pow(fabs(Xc - Xf), 2) + pow(fabs(Yc - Yf), 2));
    if (Rc - Dist >= Rf) cout << "RICO";
    else cout << "MORTO";
    cout << endl;
  }
}
