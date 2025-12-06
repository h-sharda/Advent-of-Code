#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    long long part1(vector<string> &rows) {
        vector<vector<string>> grid;

        for (auto &line : rows) {
            vector<string> row;
            string curr;

            for (char &ch : line) {
                if (ch == ' ') {
                    if (curr.size() > 0)
                        row.push_back(curr);
                    curr.clear();
                } else {
                    curr.push_back(ch);
                }
            }

            if (curr.size() > 0)
                row.push_back(curr);

            grid.push_back(row);
        }

        long long ans = 0;
        int m = grid.size(), n = grid[0].size();

        for (int col = 0; col < n; col++) {
            char symbol = grid[m - 1][col][0];
            long long curr = symbol == '+' ? 0 : 1;

            for (int row = 0; row < m - 1; row++)
                curr = symbol == '+' ? curr + stoll(grid[row][col])
                                     : curr * stoll(grid[row][col]);

            ans += curr;
        }

        return ans;
    }

    long long part2(vector<string> &rows) {
        long long ans = 0;
        int m = rows.size(), n = rows[0].size(), col = 0;

        while (col < n) {
            char symbol = rows[m - 1][col];

            long long curr = symbol == '+' ? 0 : 1;
            int temp = col + 1;

            while (temp < n && rows[m - 1][temp] == ' ')
                temp++;

            if (temp == n)
                temp++;

            while (col < temp - 1) {
                long long num = 0;
                for (int row = 0; row < m - 1; row++)
                    if (rows[row][col] != ' ')
                        num = num * 10 + rows[row][col] - '0';

                curr = symbol == '+' ? curr + num : curr * num;
                col++;
            }

            col++;
            ans += curr;
        }

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
