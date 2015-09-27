#include <string>
#include <iostream>

using namespace std;

int main() {
  int days;
  cin >> days;

  double ammount = 0;
  int qtt = 0;
  for (int i = 1; i <= days; i++) {
    double spent;
    int dayly = 1;
    string what;

    cin >> spent;

    cin.ignore(100, '\n');
    getline(cin, what);

    ammount += spent;

    for (int j = 0; j < what.length(); j++)
      if (what[j] == ' ') dayly++;
    
    qtt += dayly;
    cout << "day " << i << ": " << dayly << " kg" << endl;
  }

  cout.precision(2);
  cout << fixed;
  cout << (double)qtt/(double)days << " kg by day" << endl;
  cout << "R$ " << ammount/days << " by day" << endl;
}
