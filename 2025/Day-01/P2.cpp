#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int solve(vector<string> &queries) {
        int n = queries.size(), ans = 0, curr = 50;

        for (auto &q: queries) {
            int sign = q[0] == 'L' ? -1 : 1;
            int mov = stoi(q.substr(1));

            ans += mov / 100;
            mov %= 100;

            int next = curr + sign * mov;

            if (curr != 0 && (next <= 0 || next >= 100)) ans++;
            curr = (next % 100 + 100) % 100;
        }

        return ans;
    }
};

int main() {
    vector<string> queries;

    string line;
    while (cin >> line) queries.push_back(line);

    Solution obj;
    cout << obj.solve(queries);

    return 0;
}
