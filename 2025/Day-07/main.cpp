#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    long long part1(vector<string> manifold) {
        long long ans = 0;

        int m = manifold.size(), n = manifold[0].size();

        for (int col = 0; col < n; col++)
            if (manifold[0][col] == 'S')
                manifold[0][col] = '|';

        for (int row = 0; row < m - 1; row++) {
            for (int col = 0; col < n; col++) {
                if (manifold[row][col] == '|') {
                    if (manifold[row + 1][col] == '^') {
                        if (col > 0)
                            manifold[row + 1][col - 1] = '|';
                        if (col < n - 1)
                            manifold[row + 1][col + 1] = '|';
                        ans++;
                    } else
                        manifold[row + 1][col] = '|';
                }
            }
        }

        return ans;
    }

    long long part2(vector<string> manifold) {
        long long ans = 0;

        int m = manifold.size(), n = manifold[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        for (int col = 0; col < n; col++)
            if (manifold[0][col] == 'S') {
                manifold[0][col] = '|';
                dp[0][col] = 1;
            }

        for (int row = 0; row < m - 1; row++) {
            for (int col = 0; col < n; col++) {
                if (manifold[row][col] == '|') {
                    if (manifold[row + 1][col] == '^') {
                        if (col > 0) {
                            manifold[row + 1][col - 1] = '|';
                            dp[row + 1][col - 1] += dp[row][col];
                        }
                        if (col < n - 1) {
                            manifold[row + 1][col + 1] = '|';
                            dp[row + 1][col + 1] += dp[row][col];
                        }
                    } else {
                        manifold[row + 1][col] = '|';
                        dp[row + 1][col] += dp[row][col];
                    }
                }
            }
        }

        for (int col = 0; col < n; col++)
            ans += dp[m - 1][col];

        return ans;
    }
};

int main() {
    vector<string> rows;

    string line;
    while (getline(cin, line))
        rows.push_back(line);

    Solution obj;
    cout << "Part 1: " << obj.part1(rows) << endl;
    cout << "Part 2: " << obj.part2(rows) << endl;

    return 0;
}
