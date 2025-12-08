#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using T = pair<double, pair<int, int>>;

class Solution {
    struct DSU {
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n), rank.resize(n);
            for (int i = 0; i < n; i++)
                parent[i] = i, rank[i] = 1;
        }

        int find(int node) {
            if (parent[node] == node)
                return node;

            return parent[node] = find(parent[node]);
        }

        bool unite(int a, int b) {
            int pa = find(a), pb = find(b);
            if (pa == pb)
                return false;

            if (rank[pa] > rank[pb]) {
                rank[pa] += rank[pb];
                parent[pb] = pa;

                return rank[pa] == rank.size();
            } else {
                parent[pa] = pb;
                rank[pb] += rank[pa];

                return rank[pb] == rank.size();
            }
        }
    };

    double dist(vector<int> &a, vector<int> &b) {
        long long x = a[0] - b[0], y = a[1] - b[1], z = a[2] - b[2];
        return sqrt(x * x + y * y + z * z);
    }

  public:
    long long part1(vector<vector<int>> &points, int pairs = 1000) {
        int n = points.size();
        priority_queue<T, vector<T>, greater<>> pq;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                pq.push({dist(points[i], points[j]), {i, j}});

        DSU dsu(n);

        while (pairs-- && !pq.empty()) {
            auto [a, b] = pq.top().second;
            pq.pop();

            dsu.unite(a, b);
        }

        vector<int> freq(n);
        for (int i = 0; i < n; i++)
            freq[dsu.find(i)]++;

        sort(freq.begin(), freq.end(), greater<int>());

        return 1ll * freq[0] * freq[1] * freq[2];
    }

    long long part2(vector<vector<int>> &points) {
        int n = points.size();
        priority_queue<T, vector<T>, greater<>> pq;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                pq.push({dist(points[i], points[j]), {i, j}});

        DSU dsu(n);

        while (!pq.empty()) {
            auto [a, b] = pq.top().second;
            pq.pop();

            if (dsu.unite(a, b))
                return 1ll * points[a][0] * points[b][0];
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> points;

    string line;
    while (getline(cin, line)) {
        vector<int> point;
        int num = 0;
        for (char &ch : line) {
            if (ch == ',')
                point.push_back(num), num = 0;
            else
                num = num * 10 + ch - '0';
        }

        point.push_back(num);
        points.push_back(point);
    }

    Solution obj;
    cout << "Part 1: " << obj.part1(points) << endl;
    cout << "Part 2: " << obj.part2(points) << endl;

    return 0;
}
