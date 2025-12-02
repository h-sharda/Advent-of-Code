#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int part1(vector<string> &queries) {
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

    int part2(vector<string> &queries) {
        int ans = 0, curr = 50;

        for (auto &q : queries) {
            int sign = q[0] == 'L' ? -1 : 1;
            int mov = stoi(q.substr(1));

            ans += mov / 100;
            mov %= 100;

            int next = curr + sign * mov;

            if (curr != 0 && (next <= 0 || next >= 100))
                ans++;
            curr = (next % 100 + 100) % 100;
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
    cout << "Part 1: " << obj.part1(queries) << endl;
    cout << "Part 2: " << obj.part2(queries) << endl;

    return 0;
}
