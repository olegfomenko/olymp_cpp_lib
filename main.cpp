#include <iostream>
#include "core/other/algebra.h"


using namespace std;
using namespace alg;

int main() {
    cout << ternarySearch<double, double>(-100.0, 100.0, 1e-5, true, [](double x) -> double {
        x += 5;
        return - x * x;
    });
}