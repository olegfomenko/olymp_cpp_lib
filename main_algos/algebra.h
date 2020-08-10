#ifndef CODE_ALGEBRA_H
#define CODE_ALGEBRA_H

namespace alg {
    /**
     * GCD Euclid's algorithm function
     * @tparam T - values type
     * @param a - first val
     * @param b - second val
     * @return greatest common divider
     */
    template <typename T> T gcd(T a, T b) {
        return b == 0? a : gcd(b, a % b);
    }

    /**
     * LCM algorithm (using GCD Euclid's algorithm)
     * @tparam T - values type
     * @param a - first val
     * @param b - second val
     * @return least common multiple
     */
    template <typename T> T lcm(T a, T b) {
        return (a / gcd(a, b)) * b;
    }

    template <class T> T phi(T n);
}





#endif //CODE_ALGEBRA_H

