#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> Pair;
typedef vector<Pair> PairVector;

ull mergeCount(int start, int mid, int end, PairVector& v) {
    int i = start;
    int j = mid;
    int k = 0;
    ull inv = 0;

    PairVector tmp((end - start), Pair(0, 0));

    while ((i < mid) && (j < end)) {
        if (v[i].second < v[j].second) {
            tmp[k++] = v[i++];
        } else {
            tmp[k++] = v[j++];
            inv += mid - i;
        }
    }

    while (i < mid) tmp[k++] = v[i++];
    while (j < end) tmp[k++] = v[j++];

    for (int e = start; e < end; ++e)
        v[e] = tmp[e - start];

    return inv;
}

ull mergeInv(int start, int end, PairVector& v) {
    int diff = end - start;
    if (diff <= 1) return 0;

    ull invCount = 0;
    int mid = (end + start) / 2;

    if (diff > 2) {
        invCount += mergeInv(start, mid, v);
        invCount += mergeInv(mid, end, v);
    }

    invCount += mergeCount(start, mid, end, v);
    return invCount;
}

int main() {
    int x, y;
    cin >> x >> y;

    ull h, v;
    cin >> h >> v;

    PairVector hLines(h, Pair(0, 0));
    for (int i = 0; i < h; ++i) {
        cin >> hLines[i].first >> hLines[i].second;
    }

    PairVector vLines(v, Pair(0, 0));
    for (int i = 0; i < v; ++i) {
        cin >> vLines[i].first >> vLines[i].second;
    }

    sort(hLines.begin(), hLines.end());
    sort(vLines.begin(), vLines.end());
    
    ull hIntersection = mergeInv(0, hLines.size(), hLines);
    ull vIntersection = mergeInv(0, vLines.size(), vLines);
    ull intersections = (h * v) + hIntersection + vIntersection;
    ull pieces = h + v + intersections + 1;

    cout << pieces << endl;
    return 0;
}
