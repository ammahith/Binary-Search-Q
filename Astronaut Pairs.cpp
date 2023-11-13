#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class UnionFind {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

public:
    void makeSet(int astronaut) {
        parent[astronaut] = astronaut;
        rank[astronaut] = 0;
    }

    int findSet(int astronaut) {
        if (parent[astronaut] != astronaut) {
            parent[astronaut] = findSet(parent[astronaut]);
        }
        return parent[astronaut];
    }

    void unionSets(int astronaut1, int astronaut2) {
        int parent1 = findSet(astronaut1);
        int parent2 = findSet(astronaut2);

        if (parent1 != parent2) {
            if (rank[parent1] < rank[parent2]) {
                parent[parent1] = parent2;
            }
            else if (rank[parent1] > rank[parent2]) {
                parent[parent2] = parent1;
            }
            else {
                parent[parent2] = parent1;
                rank[parent1]++;
            }
        }
    }
};
int astronautPairs(int N, vector<pair<int, int>>& astronauts) {
    UnionFind uf;
    // Create disjoint sets for each astronaut
    for (int i = 0; i < N; i++) {
        uf.makeSet(i);
    }
    // Union sets for astronauts from the same country
    for (auto& pair : astronauts) {
        int astronaut1 = pair.first;
        int astronaut2 = pair.second;
        uf.unionSets(astronaut1, astronaut2);
    }
    // Count the number of pairs from different countries
    unordered_map<int, int> countrySizes;
    int totalPairs = 0;

    for (int i = 0; i < N; i++) {
        int parent = uf.findSet(i);
        countrySizes[parent]++;
    }
    for (auto& pair : countrySizes) {
        int countrySize = pair.second;
        totalPairs += (N - countrySize) * countrySize;
    }
    return totalPairs;
}
int main() {
    int N = 5;
    vector<pair<int, int>> astronauts = { {0, 1}, {2, 3}, {0, 4} };

    int numPairs = astronautPairs(N, astronauts);

    cout << numPairs << endl;

    return 0;
}
