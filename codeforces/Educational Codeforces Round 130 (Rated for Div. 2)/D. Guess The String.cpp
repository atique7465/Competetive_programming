#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll n;

struct CharNode {
    char ch;
    ll pos;

    CharNode(char ch, ll pos) : ch(ch), pos(pos) {}

    bool operator<(const CharNode &cn) const {
        return (pos < cn.pos);
    }
};

char askChar(ll pos) {
    char chr;
    cout << "? 1 " << pos << endl;
    cin >> chr;
    return chr;
}

ll askCount(ll l, ll r) {
    ll cnt;
    cout << "? 2 " << l << " " << r << endl;
    cin >> cnt;
    return cnt;
}

int main() {
    cin >> n;
    ll cnt;
    vector<CharNode> posVector;
    string resStr;

    char ch = askChar(1);
    resStr.push_back(ch);
    posVector.emplace_back(ch, 1);

    for (ll i = 2; i <= n; i++) {

        cnt = askCount(1, i);

        if (cnt > posVector.size()) {
            ch = askChar(i);
            resStr.push_back(ch);
            posVector.emplace_back(ch, i);
        } else {
            sort(posVector.begin(), posVector.end());
            ll ln = posVector.size();

            ll start = 0, end = ln - 1;
            while (start <= end) {

                ll mid = (start + end) / 2;

                cnt = askCount(posVector[mid].pos, i);

                if (ln - mid == cnt) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }

            resStr.push_back(posVector[start - 1].ch);
            posVector[start - 1].pos = i;
        }
    }

    cout << "! " << resStr << endl;

    return 0;
}