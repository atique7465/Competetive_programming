#include<bits/stdc++.h>

#define ll long long int
#define MAX 200001
using namespace std;

ll tree[4 * MAX];

/**
 * Build and init tree
 */
void build_tree(ll node, ll a, ll b) {
    if (a > b) return; // Out of range

    if (a == b) { // Leaf node
        tree[node] = 0; // Init value
        return;
    }

    build_tree(node * 2, a, (a + b) / 2); // Init left child
    build_tree(node * 2 + 1, 1 + (a + b) / 2, b); // Init right child

    tree[node] = tree[node * 2] + tree[node * 2 + 1]; // Init root value
}

/**
 * Update elements within range [i, j] with value
 */
void update_tree(ll node, ll a, ll b, ll i, ll j, ll value) {

    if (a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;

    if (a >= i && b <= j) { // Segment is fully within range
        tree[node] += value;
        return;
    }

    update_tree(node * 2, a, (a + b) / 2, i, j, value); // Updating left child
    update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value); // Updating right child

    tree[node] = tree[node * 2] + tree[node * 2 + 1]; // Updating root
}

/**
 * Query tree to get result within range [i, j]
 */
ll query_tree(ll node, ll a, ll b, ll i, ll j) {

    if (a > b || a > j || b < i) return 0; // Out of range

    if (a >= i && b <= j) // Current segment is totally within range [i, j]
        return tree[node];

    ll q1 = query_tree(node * 2, a, (a + b) / 2, i, j); // Query left child
    ll q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j); // Query right child

    return q1 + q2; // Return final result
}


int main() {
    ll t, n, x;
    cin >> t;

    while (t--) {
        cin >> n;
        build_tree(1, 1, n);

        ll res = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> x;
            res += query_tree(1, 1, n, x, n);
            update_tree(1, 1, n, x, x, 1);
        }

        cout << res << endl;
    }

    return 0;
}

