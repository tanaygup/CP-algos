#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findMaxOverlappingIntervals() {
    int n;
    cin >> n;

    vector<pair<int, int>> events;

    // Read input intervals
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;

        // Mark the start and end of the intervals
        events.push_back({start, 1});
        events.push_back({end, -1});
    }

    // Sort events based on the time
    sort(events.begin(), events.end());

    int currentOverlap = 0;
    int maxOverlap = 0;

    // Calculate the maximum number of overlapping intervals
    for (auto event : events) {
        currentOverlap += event.second;
        maxOverlap = max(maxOverlap, currentOverlap);
    }

    cout << maxOverlap;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; // Number of test cases
    while (t--) {
        findMaxOverlappingIntervals();
    }

    return 0;
}
