#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int part1(vector<string> &banks) {
        int ans = 0;

        for (auto &bank : banks) {
            int m1 = -1, m2 = -1, num = 0;
            int n = bank.size();

            for (int i = 0; i < n; i++) {
                if (bank[i] - '0' > m1 && i != n - 1) {
                    m1 = bank[i] - '0';
                    m2 = -1;
                } else if (bank[i] - '0' > m2) {
                    m2 = bank[i] - '0';
                    num = 10 * m1 + m2;
                }
            }

            ans += num;
        }

        return ans;
    }

    long long part2(vector<string> &banks) {
        long long ans = 0;

        for (auto &bank : banks) {
            long long num = 0;

            int n = bank.size(), s = 0;
            for (int i = 11; i >= 0; i--) {
                int max = -1, pos = -1;
                for (int j = s; j < n - i; j++) {
                    if (bank[j] - '0' > max)
                        max = bank[j] - '0', pos = j;
                }
                s = pos + 1;
                num = num * 10 + max;
            }

            ans += num;
        }

        return ans;
    }
};

int main() {
    vector<string> banks;

    string line;
    while (cin >> line)
        banks.push_back(line);

    Solution obj;
    cout << "Part 1: " << obj.part1(banks) << endl;
    cout << "Part 2: " << obj.part2(banks) << endl;

    return 0;
}
