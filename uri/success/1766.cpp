#include <stdio.h>
#include <iostream>
#include <string>
#include <set>

using namespace std;

struct Reindeer {
    string Name;
    string UName;
    int Weight;
    int Age;
    int Height;
};

struct ReindeerCompare {
    bool operator()(const Reindeer &Lhs, const Reindeer &Rhs) {
        if (Lhs.Weight != Rhs.Weight)
            return Lhs.Weight > Rhs.Weight;
        if (Lhs.Age != Rhs.Age)
            return Lhs.Age < Rhs.Age;
        if (Lhs.Height != Rhs.Height)
            return Lhs.Height < Rhs.Height;
        return Lhs.UName < Rhs.UName;
    }
};

int toInt(char *H) {
    int hInt = 0, u = 0;
    for (; *H; ++H)
        if (*H != '.')
            hInt = (hInt * 10) + (*H - 48);

    if (hInt < 100)
        hInt *= 10;

    return hInt;
}

string toUpper(char *Name) {
    string str = "";
    while (*Name) {
        str += toupper(*Name);
        ++Name;
    }
    return str;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int I = 1; I <= T; ++I) {
        int N, M;
        scanf("%d %d", &N, &M);

        set<Reindeer, ReindeerCompare> Reindeers;
        for (int J = 0; J < N; ++J) {
            char Name[128], Height[16];
            Reindeer R;
            scanf("%s %d %d %s", Name, &R.Weight, &R.Age, Height);
            R.Name = Name;
            R.UName = toUpper(Name);
            R.Height = toInt(Height);
            Reindeers.insert(R);
        }


        cout << "CENARIO {" << I << "}" << endl;
        int Count = 1;
        for (auto It = Reindeers.begin(), E = Reindeers.end(); It != E; ++It) {
            if (Count > M) break; 
            cout << Count++ << " - " << (*It).Name << endl;
        }
    }
}
