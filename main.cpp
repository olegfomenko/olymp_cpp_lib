#include <iostream>
#include "core/data_structure/graph.h"
#include "core/data_structure/segment_tree.h"

using namespace std;
using namespace alg;

int main() {
    int n, m;
    cin >> n >> m;

    DynamicGraph<int> graph(false);

    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph.add(x, y);
    }

    cout << graph.size() << " " << graph.edges() << " " << graph.countComponents() << "\n";

    graph.removeVertex(1);

    cout << graph.size() << " " << graph.edges() << "\n";
}