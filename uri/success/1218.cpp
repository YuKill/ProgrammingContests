#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define M 0
#define F 1

int main() {
  for (int t = 1, tam; cin >> tam; t++) {
    int sexo[2], match = 0;
    sexo[M] = 0;
    sexo[F] = 0;

    cin.ignore(100, '\n');

    string shoes;
    getline(cin, shoes);

    for (int i = 0; i < shoes.length(); i += 5) {
      string i_shoe = shoes.substr(i, 4);
      int i_shoe_tam = ((i_shoe[0]-'0')*10) + i_shoe[1]-'0';
      if (i_shoe_tam == tam) {
        if (i_shoe[3] == 'M')
          sexo[M]++;
        else
          sexo[F]++;
        match++;
      }
    }

    if (t != 1) cout << endl;
    cout << "Caso " << t << ":" << endl;
    cout << "Pares Iguais: " << match << endl;
    cout << "F: " << sexo[F] << endl;
    cout << "M: " << sexo[M] << endl;
  }
}
