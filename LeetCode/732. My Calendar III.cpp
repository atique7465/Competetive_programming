#include<bits/stdc++.h>

using namespace std;

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

class MyCalendarThree {

private:
    SegmentTree *st;

public:
    MyCalendarThree() {
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