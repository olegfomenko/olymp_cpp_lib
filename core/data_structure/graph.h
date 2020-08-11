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

    class DynamicGraph {
    private:

        int m;

        bool directed;

        /**
         * Graph and inverse graph maps
         */
        map<int, multiset<int> > g, _g;

        /**
         * Adding directed edge function
         * @param start - start vertex
         * @param finish - finish vertex
         */
        void addDirectedEdge(int start, int finish);
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
        void add(int x, int y);

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
        bool removeEdge(int x, int y);

        /**
         * Removing vertex with all edges
         * @param v - vertex
         */
        void removeVertex(int v);

        /**
         * Get graph map
         * @return graph map
         */
        map<int, multiset<int> > & getGraph();

        /**
         * Get inverse graph map
         * @return inverse graph map
         */
        map<int, multiset<int> > & getInverseGraph();
    };

    DynamicGraph::DynamicGraph(bool directed) : m(0), directed(directed) {}

    DynamicGraph::DynamicGraph() : m(0), directed(false) {}

    void DynamicGraph::addDirectedEdge(int start, int finish) {
        g[start].insert(finish);
        _g[finish].insert(start);
    }

    void DynamicGraph::add(int x, int y) {
        ++m;
        addDirectedEdge(x, y);
        if(!directed) {
            addDirectedEdge(y, x);
        }
    }

    bool DynamicGraph::removeEdge(int x, int y) {
        --m;
        if(g[x].count(y)) {
            g[x].erase(g[x].find(y));
            if(!directed) g[y].erase(x);
            return true;
        } else {
            return false;
        }
    }

    void DynamicGraph::removeVertex(int v) {
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

    int DynamicGraph::size() {
        return g.size();
    }

    int DynamicGraph::edges() {
        return m;
    }

    map<int, multiset<int> > &DynamicGraph::getGraph() {
        return g;
    }

    map<int, multiset<int> > &DynamicGraph::getInverseGraph() {
        return _g;
    }
}

#endif //CORE_GRAPH_H