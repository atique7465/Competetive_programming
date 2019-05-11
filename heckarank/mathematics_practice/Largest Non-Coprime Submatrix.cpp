#include <bits/stdc++.h>
using namespace std;

int n, m;
const int mx = 200;
vector<int> h;
int a[mx + 10][mx + 10];
int b[mx + 10][mx + 10];

vector<int> s;

int Histogram(vector<int>& height)
{
    s.clear();
    height.push_back(0);

    int sum = 0;
    int i = 0;
    while (i < height.size())
    {
        if (s.empty() || height[i] > height[s.back()])
        {
            s.push_back(i);
            i++;
        }
        else
        {
            int t = s.back();
            s.pop_back();

            sum = max(sum, height[t] * (s.empty() ? i : i - s.back() - 1));
        }
    }

    return sum;
}

int isPrime(int x)
{
    int i;
    if (x < 2)
        return false;
    for (i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
int main(void)
{
    int i, j, k, kase = 0;

    cin >> n >> m;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];

    int prime;
    int ans = 0;
    h.resize(m, 0);

    for (prime = 0; prime < 10000; prime++)
    {
        if (!isPrime(prime))
            continue;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                b[i][j] = ((a[i][j] % prime) == 0);

        h.assign(m, 0);

        int base;
        for (base = 0; base < n; base++)
        {
            for (i = 0; i < m; i++)
            {
                if (b[base][i])
                    h[i] += b[base][i];
                else
                    h[i] = 0;
            }
            ans = max(ans, Histogram(h));
        }
    }
    cout << ans << endl;

    return 0;
}

