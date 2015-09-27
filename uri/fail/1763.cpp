#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {
  map<string, string> translate;
  translate["brasil"] = "Feliz Natal!";
  translate["alemanha"] = "Frohliche Weihnachten!";
  translate["austria"] = "Frohe Weihnacht!";
  translate["coreia"] = "Chuk Sung Tan!";
  translate["espanha"] = "Feliz Navidad!";
  translate["grecia"] = "Kala Christougena!";
  translate["estados-unidos"] = "Merry Christmas!";
  translate["inglaterra"] = "Merry Christmas!";
  translate["australia"] = "Merry Christmas!";
  translate["portugal"] = "Feliz Natal!";
  translate["suecia"] = "God Jul!";
  translate["turquia"] = "Mutlu Noeller";
  translate["argentina"] = "Feliz Navidad!";
  translate["chile"] = "Feliz Navidad!";
  translate["mexico"] = "Feliz Navidad!";
  translate["antartida"] = "Merry Christmas!";
  translate["canada"] = "Merry Christmas!";
  translate["irlanda"] = "Nollaig Shona Dhuit!";
  translate["belgica"] = "Zalig Kerstfeest!";
  translate["italia"] = "Buon Natale!";
  translate["libia"] = "Buon Natale!";
  translate["siria"] = "Milad Mubarak!";
  translate["marrocos"] = "Milad Mubarak!";
  translate["japao"] = "Merii Kurisumasu!";
  for (string s; getline(cin, s); ) {
    if (translate.find(s) == translate.end()) {
      printf("--- NOT FOUND ---\n");
    } else {
      printf("%s\n", translate[s].c_str());
    }
  }
}
