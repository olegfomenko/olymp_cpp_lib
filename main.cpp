#include <iostream>
#include "core/data_structure/segment_tree.h"


using namespace std;

int main() {
    int a[] = {10, 2, 14, 5, 5, 19};

    segment_tree<int> tree(6, a, 0, [](int a, int b) -> int {
        return a + b;
    });

    cout << tree.get(0, 5) << endl;
    cout << tree.get(0, 3) << endl;
    tree.update(4, 0);
    cout << tree.get(3, 5) << endl;
}