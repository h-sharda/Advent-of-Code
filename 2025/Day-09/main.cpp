#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
    long long area(pair<int, int> &a, pair<int, int> &b) {

        return abs(1ll * (a.first - b.first + 1) * (a.second - b.second + 1));
    };

  public:
    long long part1(vector<pair<int, int>> &points) {
        long long ans = 0, n = points.size();

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = max(ans, area(points[i], points[j]));

        return ans;
    }

    long long part2(vector<pair<int, int>> &points) {
        long long ans = 0, n = points.size();

        return ans;
    }
};

int main() {
    vector<pair<int, int>> points;

    string line;
    while (getline(cin, line)) {
        int i = line.find(',');
        points.emplace_back(stoi(line.substr(0, i)), stoi(line.substr(i + 1)));
    }

    Solution obj;
    cout << "Part 1: " << obj.part1(points) << endl;
    cout << "Part 2: " << obj.part2(points) << endl;

    return 0;
}
