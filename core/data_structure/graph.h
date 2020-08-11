//
// Created by Oleg on 11.08.2020.
//

#ifndef CORE_GRAPH_H
#define CORE_GRAPH_H

#include <vector>
using namespace std;

namespace alg {

    template<typename T>
    class Graph {
    private:
        int n;
        int m;

        vector<int> *g;
    public:
        const int MAX_SIZE = 1000000;

        Graph();
    };

    template<typename T>
    Graph<T>::Graph() : n(0), m(0) {
        g = new vector<int>[MAX_SIZE];
    }

}

#endif //CORE_GRAPH_H