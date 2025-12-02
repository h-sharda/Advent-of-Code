#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
    bool invalidP1(string num) {
        int n = num.size();
        if (n % 2)
            return false;

        int i = 0, j = n / 2;
        while (j < n) {
            if (num[i] != num[j])
                return false;
            i++, j++;
        }

        return true;
    }

    bool invalidP2(string num) {
        int n = num.size();

        for (int i = 1; i <= n / 2; i++) {
            if (n % i)
                continue;
            bool flag = true;

            for (int j = 0; j < i; j++) {
                char ch = num[j];

                for (int k = j; k < n; k += i) {
                    if (num[k] != ch) {
                        flag = false;
                        break;
                    }
                }

                if (!flag)
                    break;
            }

            if (flag)
                return true;
        }

        return false;
    }

  public:
    long long part1(vector<pair<long long, long long>> &ids) {
        long long ans = 0;
        for (auto [l, r] : ids) {
            while (l <= r) {
                if (invalidP1(to_string(l)))
                    ans += l;
                l++;
            }
        }

        return ans;
    }

    long long part2(vector<pair<long long, long long>> &ids) {
        long long ans = 0;
        for (auto [l, r] : ids) {
            while (l <= r) {
                if (invalidP2(to_string(l))) 
                    ans += l;
                l++;
            }
        }

        return ans;
    }
};

int main() {
    string line, l, r;
    bool flag = false;
    cin >> line;

    vector<pair<long long, long long>> ids;

    for (char &ch : line) {
        if (ch == ',') {
            ids.emplace_back(stoll(l), stoll(r));
            l.clear();
            r.clear();
            flag = false;
        } else if (ch == '-') {
            flag = true;
        } else if (flag) {
            r.push_back(ch);
        } else {
            l.push_back(ch);
        }
    }
    ids.emplace_back(stoll(l), stoll(r));

    Solution obj;
    cout << "Part 1: " << obj.part1(ids) << endl;
    cout << "Part 2: " << obj.part2(ids) << endl;

    return 0;
}
