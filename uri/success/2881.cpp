#include <iostream>
#include <limits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iomanip>

using namespace std;

typedef unsigned long long ull;

static const ull inf = numeric_limits<ull>::max();

struct Show {
    int init;
    int fin;
    int musics;
    int stage;
    int last;
};

struct ShowIdxCompare {
    const vector<Show>& shows;

    ShowIdxCompare(const vector<Show>& shows) : shows(shows) {}

    bool operator()(const int& lhs, const int& rhs) {
        return shows[lhs].fin < shows[rhs].fin;
    }
};

ull infMax(const ull& lhs, const ull& rhs) {
    if (lhs == inf) return rhs;
    if (rhs == inf) return lhs;
    return max(lhs, rhs);
}

int binSearch(int init,
              int fin,
              int val,
              const vector<int>& idx,
              const vector<Show>& shows) {
    if (init == fin) return init - 1;

    int mid = (init + fin) / 2;
    int midId = idx[mid];
    
    if (shows[midId].fin < val) {
        return binSearch(mid + 1, fin, val, idx, shows);
    } else if (shows[midId].fin > val) {
        return binSearch(init, mid, val, idx, shows);
    }

    return mid;
}


int main() {
    int stageNum;
    cin >> stageNum;

    vector<Show> shows;
    vector<vector<int>> stages;

    for (int i = 0; i < stageNum; ++i) {
        int showNum;
        cin >> showNum;

        vector<int> showIds(showNum, 0);

        for (int j = 0; j < showNum; ++j) {
            showIds[j] = shows.size();

            Show show;
            cin >> show.init >> show.fin >> show.musics;
            show.stage = i;
            shows.push_back(show);
        }

        stages.push_back(showIds);
    }

    int maxMask = 1 << stageNum;
    vector<vector<ull>> dp(shows.size(), vector<ull>(maxMask, inf));
    vector<int> order(shows.size(), 0);

    ShowIdxCompare comp(shows);

    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), comp);

    for (int i = 0; i < shows.size(); ++i) {
        shows[i].last = binSearch(0, shows.size(), shows[i].init, order, shows);
    }

    // for (int i = 0; i < shows.size(); ++i) {
    //     int ii = order[i];

    //     cout << "lastShow[" << shows[ii].init << ", " << shows[ii].fin
    //          << ", " << shows[ii].musics << ", " << shows[ii].stage
    //          << "]: " << shows[ii].last << endl;
    //     
    //     if (shows[ii].last >= 0) {
    //         int iii = order[shows[ii].last];

    //         cout << "\t" << shows[iii].init << ", " << shows[iii].fin
    //              << ", " << shows[iii].musics << ", " << shows[iii].stage << endl;
    //     }
    // }

    for (int i = 0; i < shows.size(); ++i) {
        int ii = order[i];
        dp[i][1 << shows[ii].stage] = shows[ii].musics;
    }

    for (int i = 1; i < shows.size(); ++i) {
        int ii = order[i];
        for (int j = 1; j < maxMask; ++j) {
            int stageMask = 1 << shows[ii].stage;
            dp[i][j] = infMax(dp[i][j], dp[i - 1][j]);

            if (stageMask & j && shows[ii].last >= 0) {
                ull dpMax = infMax(dp[shows[ii].last][j],
                                   dp[shows[ii].last][j - stageMask]);

                ull totalMusics = (dpMax == inf) ? inf : shows[ii].musics + dpMax;
                dp[i][j] = infMax(dp[i][j], totalMusics);
            }
        }
    }

    // for (int j = 0; j < maxMask; ++j) {
    //     cout << setw(10) << j;
    // }

    // cout << endl;

    // for (int i = 0; i < shows.size(); ++i) {
    //     for (int j = 0; j < maxMask; ++j) {
    //         string pretty = (dp[i][j] == inf) ? "inf" : to_string(dp[i][j]);
    //         cout << setw(10) << pretty;
    //     }

    //     cout << endl;
    // }

    int lastShow = shows.size() - 1;
    int lastMask = maxMask - 1;
    if (dp[lastShow][lastMask] == inf) cout << -1 << endl;
    else cout << dp[lastShow][lastMask] << endl;

    return 0;
}
