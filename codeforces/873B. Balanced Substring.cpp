#include bitsstdc++.h

using namespace std;

int main() {

    int n, res = 0;
    string str;
    cin  n;
    mapint, int firstFoundAt;
    firstFoundAt[0] = -1;

    cin  str;

    int sum = 0;
    for (int i = 0; i  n; i++) {
        if (str[i] == '1')
            sum++;
        else
            sum--;

        if (firstFoundAt.find(sum) != firstFoundAt.end()) {
            res = max(res, i - firstFoundAt[sum]);
        } else {
            firstFoundAt[sum] = i;
        }
    }

    cout  res;

    return 0;
}
