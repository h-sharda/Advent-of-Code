#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    void merge(vector<pair<long long, long long>> &ranges) {
        sort(ranges.begin(), ranges.end());
        int n = ranges.size(), i = 0, j = 0;

        while (j < n) {
            if (ranges[j].first > ranges[i].second) {
                i++;
                ranges[i] = ranges[j];
            } else {
                ranges[i].second = max(ranges[i].second, ranges[j].second);
            }

            j++;
        }

        ranges.resize(i + 1);
    }

    int part1(vector<pair<long long, long long>> &freshRanges,
              vector<long long> &ids) {

        auto contains = [&](long long id) {
            int low = 0, high = freshRanges.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (freshRanges[mid].first <= id)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            return high == -1 ? false : (freshRanges[high].second >= id);
        };

        int ans = 0;
        for (auto &id : ids)
            if (contains(id))
                ans++;

        return ans;
    }

    long long part2(vector<pair<long long, long long>> &freshRanges) {
        long long ans = 0;
        for (auto &[l, r] : freshRanges)
            ans += r - l + 1;

        return ans;
    }
};

int main() {
    vector<pair<long long, long long>> freshRanges;
    vector<long long> ids;

    string line;
    while (getline(cin, line)) {
        if (line == "")
            break;

        int dash = 0;
        while (line[dash] != '-')
            dash++;

        freshRanges.emplace_back(stoll(line.substr(0, dash)),
                                 stoll(line.substr(dash + 1)));
    }

    while (getline(cin, line))
        ids.push_back(stoll(line));

    Solution obj;
    obj.merge(freshRanges);
    cout << "Part 1: " << obj.part1(freshRanges, ids) << endl;
    cout << "Part 1: " << obj.part2(freshRanges) << endl;

    return 0;
}
