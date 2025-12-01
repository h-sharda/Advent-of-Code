#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int solve(vector<string> &queries) {
        int ans = 0, curr = 50;

        for (auto &q : queries) {
            int sign = q[0] == 'L' ? -1 : 1;
            int mov = stoi(q.substr(1));

            curr = (curr + sign * mov) % 100;
            if (curr == 0)
                ans++;
        }

        return ans;
    }
};

int main() {
    vector<string> queries;

    string line;
    while (cin >> line)
        queries.push_back(line);

    Solution obj;
    cout << obj.solve(queries);

    return 0;
}
