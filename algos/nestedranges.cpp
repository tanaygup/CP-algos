#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    if (a.first.first == b.first.first)
        return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}

vector<vector<int>> checkrange(vector<vector<int>>& r, int n) {
    vector<pair<pair<int, int>, int>> range(n);

    vector<int> contains(n), contained(n);

    for (int i = 0; i < n; i++) {
        range[i].first.first = r[i][0]; 
        range[i].first.second = r[i][1]; 
        range[i].second = i;             
    }

    sort(range.begin(), range.end(), compare);

    // Checks if a range contains another
    int minEnd = 2e9;
    for (int i = n - 1; i >= 0; i--) {
        if (range[i].first.second >= minEnd)
            contains[range[i].second] = 1;

        minEnd = min(minEnd, range[i].first.second);
    }

    // Checks if a range is contained by another
    int maxEnd = 0;
    for (int i = 0; i < n; i++) {
        if (range[i].first.second <= maxEnd)
            contained[range[i].second] = 1;

        maxEnd = max(maxEnd, range[i].first.second);
    }

    return {contains, contained};
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> r(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> r[i][0] >> r[i][1];
    }
    vector<vector<int>> res = checkrange(r, n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
