#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
  double H;
  double G = 9.80665, Pi = 3.14159;

  while (cin >> H) {
    int Begin, End, N;
    cin >> Begin >> End >> N;

    for (int I = 0; I < N; ++I) {
      double Alpha, V, Vy, Vx;
      cin >> Alpha >> V;

      Alpha = Pi * Alpha / 180.0;
      Vy = V * sin(Alpha);
      Vx = V * cos(Alpha);

      double Time = (Vy + sqrt((Vy*Vy) + (2 * G * H))) / G;
      double Hit = Vx * Time;

      cout.precision(5);
      cout.setf(ios::fixed, ios::floatfield);

      cout << Hit << " -> ";
      if (Begin <= Hit && Hit <= End) cout << "DUCK";
      else cout << "NUCK";
      cout << endl;
    }
  }

  return 0;
}
