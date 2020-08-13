//
// Created by Oleg on 11.08.2020.
//

#ifndef CORE_GRAPH_H
#define CORE_GRAPH_H

#include <vector>
#include <set>
#include <map>
using namespace std;

namespace alg {

    /**
     * Graph dynamic data structure.
     * Adding edge by O ( logN )
     * Removing edge by O ( logN )
     * Removing vertex by O ( K log N), where K - outcomig edges
     */

    template<typename T>
    class DynamicGraph {
    private:
        int m;

        bool directed;

        /**
         * Graph and inverse graph maps
         */
        map<T, multiset<T> > g, _g;

        /**
         * Adding directed edge function
         * @param start - start vertex
         * @param finish - finish vertex
         */
        void addDirectedEdge(T start, T finish);

        /**
         * Deep first search for calculating components of graph by O ( N + M ) complexity
         * @param v - current vertex (unused before)
         */
        void countComponents(T v, map<T, bool> & used);

    public:
        /**
         * Creating empty graph
         * @param directed - orientation sign
         */
        DynamicGraph(bool directed);


        /**
         * Creating empty undirected graph
         */
        DynamicGraph();

        /**
         * Adding edge function
         * @param x - vertex
         * @param y - vertex
         */
        void add(T x, T y);

        /**
         * @return Uninsulated vertex count
         */
        int size();

        /**
         * @return Edges count
         */
        int edges();

        /**
         * Removing edge
         * @param x - vertex
         * @param y - vertex
         * @return true if edge was removed
         */
        bool removeEdge(T x, T y);

        /**
         * Removing vertex with all edges
         * @param v - vertex
         */
        void removeVertex(T v);

        /**
         * Get graph map
         * @return graph map
         */
        map<T, multiset<T> > getGraph();

        /**
         * Get inverse graph map
         * @return inverse graph map
         */
        map<T, multiset<T> > getInverseGraph();

        /**
         * Calculate components of graph by O ( N + M ) complexity
         * @param v - current vertex (unused before)
         */
        int countComponents();

        /**
         * Adding isolated vertex
         * @param v - vertex
         */
        void addVertex(T v);
    };

    template<typename T>
    DynamicGraph<T>::DynamicGraph(bool directed) : m(0), directed(directed) {}

    template<typename T>
    DynamicGraph<T>::DynamicGraph() : m(0), directed(false) {}

    template<typename T>
    void DynamicGraph<T>::addDirectedEdge(T start, T finish) {
        g[start].insert(finish);
        _g[finish].insert(start);
    }

    template<typename T>
    void DynamicGraph<T>::add(T x, T y) {
        ++m;
        addDirectedEdge(x, y);
        if(!directed) {
            addDirectedEdge(y, x);
        }
    }

    template<typename T>
    bool DynamicGraph<T>::removeEdge(T x, T y) {
        --m;
        if(g[x].count(y)) {
            g[x].erase(g[x].find(y));
            if(!directed) g[y].erase(x);
            return true;
        } else {
            return false;
        }
    }

    template<typename T>
    void DynamicGraph<T>::removeVertex(T v) {
        for(int to : g[v]) {
            _g[to].erase(v);
        }

        m -= g[v].size();
        g[v].clear();
        g.erase(v);

        for(int to : _g[v]) {
            if(directed) m -= g[to].count(v);
            g[to].erase(v);
        }

        _g[v].clear();
        _g.erase(v);
    }

    template<typename T>
    int DynamicGraph<T>::size() {
        return g.size();
    }

    template<typename T>
    int DynamicGraph<T>::edges() {
        return m;
    }

    template<typename T>
    map<T, multiset<T> > DynamicGraph<T>::getGraph() {
        return g;
    }

    template<typename T>
    map<T, multiset<T> > DynamicGraph<T>::getInverseGraph() {
        return _g;
    }

    template<typename T>
    void DynamicGraph<T>::countComponents(T v, map<T, bool> & used) {
        used[v] = true;

        set<T> neighbors;
        neighbors.insert(g[v].begin(), g[v].end());
        neighbors.insert(_g[v].begin(), _g[v].end());

        for(T to : neighbors) {
            if(!used[to]) {
                countComponents(to, used);
            }
        }
    }

    template<typename T>
    int DynamicGraph<T>::countComponents() {
        int componentsCnt = 0;
        map<T, bool> used;

        for(auto p : g) {
            if(!used[p.first]) {
                countComponents(p.first, used);
                ++componentsCnt;
            }
        }

        for(auto p : _g) {
            if(!used[p.first]) {
                countComponents(p.first, used);
                ++componentsCnt;
            }
        }

        return componentsCnt;
    }

    template<typename T>
    void DynamicGraph<T>::addVertex(T v) {
        if(g.count(v) == 0) {
            g[v] = multiset<T>();
            _g[v] = multiset<T>();
        }
    }
}

#endif //CORE_GRAPH_H