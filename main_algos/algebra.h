#ifndef CODE_ALGEBRA_H
#define CODE_ALGEBRA_H

#include "iostream"
using namespace std;

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

    /**
     * Sieve of Eratosthenes algorithm with complexity O( N * logN)
     * Sets array with 0 - value on prime index and least prime divider value on non-prime indexes
     * @tparam T - value type
     * @param start - address of array start's
     * @param end - address of array end's
     */
    template <typename T> void fill_prime(T * start, T * end) {
        int N = end - start;
        fill(start, end, 0);

        for(T i = 2; i < N / i + 1; ++i) {
            if(start[i] != 0) continue;

            start[i] = i;

            for(T j = i * i; j < N; j += i) start[j] = i;
        }
    }

    /**
     * Sieve of Eratosthenes algorithm with complexity O( N * logN)
     * Sets array with 0 - value on prime index and least prime divider value on non-prime indexes
     * @tparam T - value type
     * @param start - address of array start's
     * @param N - array size
     */
    template <typename T> void fill_prime(T * start, T N) {
        fill_prime(start, start + N);
    }

    /**
     * Euler function with complexity: O( logN )
     * @tparam T - value type
     * @param n
     * @param array with 0 - value on prime index and least prime divider value on non-prime indexes
     * @return count of natural values i from 1 to n that gcd(i, n) = 1
     */
    template <typename T> T phi(T n, T * prime) {
        T result = n;

        while(n > 1) {
            result = (result / prime[n]) * (prime[n] - 1);
            n /= prime[n];
        }

        return result;
    }

    /**
     * Euler function with complexity: O( sqrt(N) )
     * @tparam T - value type
     * @param n
     * @return count of natural values i from 1 to n that gcd(i, n) = 1
     */
    template <class T> T phi(T n) {
        T result = n;

        for(T i = 2; i < n / i + 1 && n > 1; ++i) {
            if(n % i == 0) {
                result = (result / i) * (i - 1);
            }

            while (n % i == 0) {
                n /= i;
            }
        }

        if(n > 1) result = (result / n) * (n - 1);
        return result;
    }
}





#endif //CODE_ALGEBRA_H


