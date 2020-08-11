//
// Created by Oleg on 11.08.2020.
//

#ifndef CORE_DSU_H
#define CORE_DSU_H

#include <algorithm>
#include <vector>
using namespace std;

/**
 * Disjoint-set data structure. Adding edge and find with complexity O ( logN )
 * About: https://e-maxx.ru/algo/dsu
 */
class DSU {
private:
    vector<int> nodes;
    vector<int> nodesSize;
public:
    /**
     * Creating set with n vertex
     * @param n
     */
    DSU(int n);

    /**
     * Creating empty set
     */
    DSU() = default;

    /**
     * Find parent with O ( logN ) complexity
     * @param v - vertex index
     * @return parent for vertex v
     */
    int find(int v);

    /**
     * Reset dsu with n vertex
     * @param n - count of vertex
     */
    void reset(int n);

    /**
     * Adding an edge by O( logN ) complexity
     * @param x - edge start
     * @param y - edge finish
     * @return true if edge unions trees
     */
    bool add(int x, int y);

    /**
     * Adding node to set
     * @return new node index
     */
    int addNode();

    /**
     * Get current nodes count
     * @return current set size
     */
    int size();
};

int DSU::find(int v) {
    return v > nodes.size() ? -1 : nodes[v] == v ? v : nodes[v] = find(nodes[v]);
}

DSU::DSU(const int n) {
    reset(n);
}

void DSU::reset(int n) {
    nodes.resize(n + 1);
    nodesSize.resize(n + 1);

    for(int i = 1; i <= n; ++i) {
        addNode();
    }
}

bool DSU::add(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) {
        return false;
    }

    if(nodesSize[x] < nodesSize[y]) swap(x, y);
    nodes[y] = x;
    return true;
}

int DSU::addNode() {
    int index = nodes.size();
    nodes.push_back(index);
    nodesSize.push_back(1);
    return index;
}

int DSU::size() {
    return nodes.size() - 1;
}

#endif //CORE_DSU_H
