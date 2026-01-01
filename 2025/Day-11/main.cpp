#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    long long part1(string curr, unordered_map<string, vector<string>> &adj,
                    unordered_map<string, long long> &memo) {
        if (curr == "out")
            return 1;
        if (memo.count(curr))
            return memo[curr];

        long long ans = 0;

        for (auto &str : adj[curr])
            ans += part1(str, adj, memo);

        return memo[curr] = ans;
    }

    long long part2(string curr, bool dac, bool fft,
                    unordered_map<string, vector<string>> &adj,
                    unordered_map<string, long long> &memo) {

        if (curr == "out")
            return dac && fft;

        if (curr == "fft")
            fft = true;

        if (curr == "dac" && fft)
            dac = true;

        string key = to_string(dac) + "," + to_string(fft) + "," + curr;

        if (memo.count(key))
            return memo[key];

        long long ans = 0;

        for (auto &str : adj[curr])
            ans += part2(str, dac, fft, adj, memo);

        return memo[key] = ans;
    }

  public:
    long long part1(unordered_map<string, vector<string>> &adj) {
        unordered_map<string, long long> memo;
        return part1("you", adj, memo);
    }

    long long part2(unordered_map<string, vector<string>> &adj) {
        unordered_map<string, long long> memo;
        return part2("svr", false, false, adj, memo);
    }
};

int main() {
    unordered_map<string, vector<string>> adj;

    string line;
    while (getline(cin, line)) {
        vector<string> neighbors;
        for (int i = 5; i < line.size(); i += 4)
            neighbors.push_back(line.substr(i, 3));
        adj[line.substr(0, 3)] = neighbors;
    }

    Solution obj;
    cout << "Part 1: " << obj.part1(adj) << endl;
    cout << "Part 2: " << obj.part2(adj) << endl;

    return 0;
}