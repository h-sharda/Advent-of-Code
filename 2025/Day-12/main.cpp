#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Query {
    int n, m;
    vector<int> freq;

    Query(int n, int m, vector<int> freq) : n(n), m(m), freq(freq) {}
};

struct Shape {
    int occupied = 0;
    vector<vector<bool>> shape;

    Shape(vector<vector<bool>> &shape) : shape(shape) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                occupied += shape[i][j];
    }
};

class Solution {
    bool valid(Query &query, vector<Shape> &shapes) {
        int lim = query.m * query.n;
        int total = 0;
        for (int i = 0; i < 6; i++)
            total += query.freq[i] * shapes[i].occupied;

        return total <= lim;
    }

  public:
    int part1(vector<Shape> &shapes, vector<Query> &queries) {
        int ans = 0;
        int total = 0;
        for (auto &query : queries)
            ans += valid(query, shapes);

        return ans;
    }
};

int main() {
    string line;

    vector<Shape> shapes;
    for (int i = 0; i < 6; i++) {
        getline(cin, line);
        vector<vector<bool>> shape;

        for (int j = 0; j < 3; j++) {
            getline(cin, line);
            vector<bool> v(3);
            for (int i = 0; i < 3; i++)
                v[i] = line[i] == '#';
            shape.push_back(v);
        }

        shapes.push_back(Shape(shape));
        getline(cin, line);
    }

    vector<Query> queries;
    while (getline(cin, line)) {
        int sz = line.size(), i = 0;

        int n = stoi(line.substr(0, 2)), m = stoi(line.substr(3, 2));
        vector<int> freq;
        for (int i = 7; i < line.size(); i += 3)
            freq.push_back(stoi(line.substr(i, 2)));

        queries.push_back(Query(n, m, freq));
    }

    Solution obj;
    cout << "Part 1: " << obj.part1(shapes, queries) << endl;

    return 0;
}