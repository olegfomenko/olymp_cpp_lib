#include <iostream>
#include "core/data_structure/graph.h"

using namespace std;
using namespace alg;

int main() {
    int n, m;
    cin >> n >> m;

    DynamicGraph graph(false);

    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph.add(x, y);
    }

    cout << graph.size() << " " << graph.edges() << "\n";

    graph.removeVertex(1);

    cout << graph.size() << " " << graph.edges() << "\n";
}