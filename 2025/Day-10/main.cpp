#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Machine {
    vector<bool> lights;
    vector<vector<int>> swithces;
    vector<int> joltages;

    int initialize(int i, vector<bool> &state) {
        if (state == lights)
            return 0;

        if (i >= swithces.size())
            return 1e9;

        int ans = initialize(i + 1, state);

        vector<bool> cpy = press(i, state);
        ans = min(ans, 1 + initialize(i + 1, cpy));

        return ans;
    }

    int joltageFix(int i, int maxx, vector<int> &state) {
        if (state == joltages)
            return 0;

        if (i >= swithces.size())
            return 1e9;

        for (int j = 0; j < joltages.size(); j++)
            if (state[j] > joltages[j])
                return 1e9;

        int ans = 1e9;
        for (int j = 0; j <= maxx; j++) {
            vector<int> cpy = press(i, j, state);
            ans = min(ans, j + joltageFix(i + 1, maxx, cpy));
        }

        return ans;
    }

    vector<int> press(int i, int times, vector<int> state) {
        for (auto &s : swithces[i])
            state[s] += times;

        return state;
    }

    vector<bool> press(int i, vector<bool> state) {
        for (auto &s : swithces[i])
            state[s] = !state[s];

        return state;
    }

  public:
    Machine() {}
    Machine(vector<bool> &lights, vector<vector<int>> &swithces,
            vector<int> &joltages)
        : lights(lights), swithces(swithces), joltages(joltages) {}

    int initialize() {
        vector<bool> state(lights.size());
        return initialize(0, state);
    }

    int joltageFix() {
        int maxx = *max_element(joltages.begin(), joltages.end());
        vector<int> state(joltages.size());

        return joltageFix(0, maxx, state);
    }
};

class Solution {
  public:
    int part1(vector<Machine> &machines) {
        long long ans = 0;

        for (auto &m : machines)
            ans += m.initialize();

        return ans;
    }

    long long part2(vector<Machine> &machines) {
        long long ans = 0;

        for (auto m : machines)
            ans += m.joltageFix();

        return ans;
    }
};

int main() {
    vector<Machine> machines;

    string line;
    while (getline(cin, line)) {
        int i = 1;

        vector<bool> lights;
        while (line[i] != ']')
            lights.push_back(line[i++] == '#');

        i += 2;

        vector<vector<int>> swithces;
        while (line[i] != '{') {
            i++;

            vector<int> v;
            while (line[i] != ')') {
                if (isdigit(line[i]))
                    v.push_back(line[i] - '0');
                i++;
            }
            swithces.push_back(v);

            i += 2;
        }

        i++;

        vector<int> joltages;
        while (i < line.size()) {
            int num = 0;

            while (isdigit(line[i]))
                num = num * 10 + line[i++] - '0';

            joltages.push_back(num);
            i++;
        }

        machines.push_back(Machine(lights, swithces, joltages));
    }

    Solution obj;
    cout << "Part 1: " << obj.part1(machines) << endl;
    cout << "Part 2: " << obj.part2(machines) << endl;

    return 0;
}