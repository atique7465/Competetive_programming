#include<bits/stdc++.h>

using namespace std;

/**
 *  sweep-line algorithm from Solution section
 */
class MyCalendarThree {

    map<int, int> eventMap;

public:
    MyCalendarThree() {
    }

    int book(int start, int end) {
        eventMap[start]++;
        eventMap[end]--;
        int curr = 0, res = 0;
        for (auto const &[k, v]: eventMap) {
            curr += v;
            res = max(res, curr);
        }

        return res;
    }
};

/**
 * Unordered Map for lazy & max
 */
class MyCalendarThree_SegmentTree_02 {

private:
    unordered_map<int, int> lazy;
    unordered_map<int, int> maxBook;

public:
    MyCalendarThree_SegmentTree_02() {
    }

    int book(int start, int end) {
        update(start, end - 1, 1, 1000000000, 1);
        return maxBook[1];
    }

    void update(int start, int end, int left, int right, int index) {
        if (start > right || end < left) return;
        if (left >= start && right <= end) {
            lazy[index]++;
            maxBook[index]++;
        } else {
            int mid = (left + right) / 2;
            update(start, end, left, mid, 2 * index);
            update(start, end, mid + 1, right, 2 * index + 1);
            maxBook[index] = lazy[index] + max(maxBook[2 * index], maxBook[2 * index + 1]);
        }
    }
};

class Node {
public:
    Node *left = nullptr;
    Node *right = nullptr;
    int lo;
    int hi;
    int lazy = 0;
    int maxi = 0;

    Node(int lo, int hi) {
        this->lo = lo;
        this->hi = hi;
    }
};


class SegmentTree {
public:
    Node *root;

    SegmentTree(int n) {
        root = new Node(0, n);
    }

    void update(int L, int R, int value, Node *curr) {
        if (L <= curr->lo && R >= curr->hi) {
            curr->lazy += value;
        }

        push(curr);

        if (L <= curr->lo && R >= curr->hi || L > curr->hi || R < curr->lo) {
            return;
        }

        update(L, R, value, curr->left);
        update(L, R, value, curr->right);

        curr->maxi = max(curr->left->maxi, curr->right->maxi);
    }

    int query(int L, int R, Node *curr) {
        push(curr);

        if (L > curr->hi || R < curr->lo) {
            return 0;
        }

        if (L <= curr->lo && R >= curr->hi) {
            return curr->maxi;
        }

        return max(query(L, R, curr->left), query(L, R, curr->right));
    }

    void push(Node *curr) {
        curr->maxi += curr->lazy;

        if (curr->lo != curr->hi) {
            int mid = (curr->lo + curr->hi) / 2;
            if (curr->left == nullptr) {
                curr->left = new Node(curr->lo, mid);
            }

            if (curr->right == nullptr) {
                curr->right = new Node(mid + 1, curr->hi);
            }

            curr->left->lazy += curr->lazy;
            curr->right->lazy += curr->lazy;
        }

        curr->lazy = 0;
    }
};

/**
 * Segment Tree using linked list
 */
class MyCalendarThree_SegmentTree_01 {

private:
    SegmentTree *st;

public:
    MyCalendarThree_SegmentTree_01() {
        st = new SegmentTree(1000000000);
    }

    int book(int start, int end) {
        st->update(start, end - 1, 1, st->root);
        return st->root->maxi;
    }
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */