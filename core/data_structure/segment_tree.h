//
// Created by Oleg on 10.08.2020.
//

#ifndef CODE_DATA_STRUCTURE_H
#define CODE_DATA_STRUCTURE_H

#include <functional>
using namespace std;

namespace alg {

/**
 * Segment tree. Complexity: build - O( N logN ), get - O( logN ), update - O( logN )
 * More information: https://e-maxx.ru/algo/segment_tree
 * @tparam T
 */

    template<typename T>
    class SegmentTree {
    private:
        const int n;
        T *a;
        T *t;

        typedef function<T(T, T)> op_f;

        const op_f operation;
        const T zero_value;

        /**
         * Build function with complexity O( logN )
         * @param v - tree node index
         * @param tl - left array bound for current node
         * @param tr - right array bound for current node
         */
        void build(int v, int tl, int tr);

        /**
         * Update function with complexity O( logN )
         * @param v - tree node index
         * @param tl - left array bound for current node
         * @param tr - right array bound for current node
         * @param pos - position for update
         * @param val - value for update
         */
        void update(int v, int tl, int tr, int pos, T val);

        /**
         * Get function with complexity O( logN )
         * @param v - tree node index
         * @param tl - left array bound for current node
         * @param tr - right array bound for current node
         * @param l - left border
         * @param r - right border
         * @return operation on [l; r]
         */
        T get(int v, int tl, int tr, int l, int r);

        /**
         * Get tree vertex function (for out-class interaction)
         * @param v - vertex index
         * @return t[v];
         */
        T getNode(int v);

    public:
        /**
         * Segment tree constructor
         * @param n - array size
         * @param a - array
         * @param zero - zero value when value not found, etc.
         * @param operation - lambda-function with two T type arguments that returns operation result for node's sons
         */
        SegmentTree(const int n, T *a, const T zero, const op_f &operation);

        ~SegmentTree();

        /**
         * Get operation on [l; r] with complexity O( logN )
         * @param l - left border
         * @param r - right border
         * @return operation on [l; r]
         */
        T get(int l, int r);

        /**
         * Update val in pos with complexity O( logN )
         * @param pos - position for update
         * @param val - value for update
         */
        void update(int pos, T val);
    };

    template<typename T>
    void SegmentTree<T>::build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        t[v] = operation(t[v * 2], t[v * 2 + 1]);
    }


    template<typename T>
    T SegmentTree<T>::get(int v, int tl, int tr, int l, int r) {
        if (l > r) return zero_value;
        if (tl == tr) return t[v];

        int tm = (tl + tr) / 2;
        return operation(
                get(v * 2, tl, tm, l, min(r, tm)),
                get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    }

    template<typename T>
    T SegmentTree<T>::get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }

    template<typename T>
    void SegmentTree<T>::update(int v, int tl, int tr, int pos, T val) {
        if (tl == tr) {
            t[v] = val;
            return;
        }

        int tm = (tl + tr) / 2;

        if (pos <= tm) {
            update(v * 2, tl, tm, pos, val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pos, val);
        }

        t[v] = operation(t[v * 2], t[v * 2 + 1]);
    }

    template<typename T>
    void SegmentTree<T>::update(int pos, T val) {
        update(1, 0, n - 1, pos, val);
    }

    template<typename T>
    SegmentTree<T>::~SegmentTree() {
        delete[] t;
    }

    template<typename T>
    SegmentTree<T>::SegmentTree(const int n, T *a, const T zero, const op_f &o):n(n), a(a), operation(o),
                                                                                zero_value(zero) {
        t = new int[4 * n];
        build(1, 0, n - 1);
    }

    template<typename T>
    T SegmentTree<T>::getNode(int v) {
        return t[v];
    }
}

#endif //CODE_DATA_STRUCTURE_H