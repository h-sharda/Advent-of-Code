#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    int remove(vector<string> &paper, int i, int j) {
        if (paper[i][j] != '@')
            return 0;

        int n = paper.size(), m = paper[0].size(), ans = 0, c = 0;

        for (int x = max(0, i - 1); x <= min(n - 1, i + 1); x++)
            for (int y = max(0, j - 1); y <= min(m - 1, j + 1); y++)
                if (paper[x][y] == '@')
                    c++;

        if (c <= 4) {
            paper[i][j] = '.';
            ans++;

            for (int x = max(0, i - 1); x <= min(n - 1, i + 1); x++)
                for (int y = max(0, j - 1); y <= min(m - 1, j + 1); y++)
                    ans += remove(paper, x, y);
        }

        return ans;
    }

  public:
    int part1(vector<string> &paper) {
        int n = paper.size(), m = paper[0].size(), ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (paper[i][j] != '@')
                    continue;

                int c = 0;
                for (int x = max(0, i - 1); x <= min(n - 1, i + 1); x++)
                    for (int y = max(0, j - 1); y <= min(m - 1, j + 1); y++)
                        if (paper[x][y] == '@')
                            c++;

                if (c <= 4)
                    ans++;
            }

        return ans;
    }

    int part2(vector<string> paper) {
        int n = paper.size(), m = paper[0].size(), ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans += remove(paper, i, j);

        return ans;
    }
};

int main() {
    vector<string> paper;

    string line;
    while (cin >> line)
        paper.push_back(line);

    Solution obj;
    cout << "Part 1: " << obj.part1(paper) << endl;
    cout << "Part 2: " << obj.part2(paper) << endl;

    return 0;
}
