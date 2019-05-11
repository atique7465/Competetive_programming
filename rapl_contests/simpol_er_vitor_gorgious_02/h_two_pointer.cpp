#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define LL long long
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define sch(n) scanf(" %c", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <ll, ll>
#define plp pair <int, pll >
#define pb push_back
#define fr first
#define sc second
#define all(a)  a.begin(),a.end()
#define Unique(a)  sort(all(a)),a.erase(unique(all(a)),a.end())

#define inf (1LL<<50)
#define eps 1e-9

ll Set(ll n, ll pos)
{
    return n|(1LL<<pos);
}

bool Check(ll n, ll pos)
{
    return (bool) (n&(1LL<<pos));
}

char s[100010];

ll mf, sf, smf, smsf, msf;

int main ()
{
//    freopen(".txt", "r", stdin);
 //   freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, ts, i, j, k, x, y, z, q, m, n;

    sl(ts);
    assert(1 <= ts && ts <= 10);

    while(ts--)
    {
        ss(s);
        sl(k);

        ll len = strlen(s);

        assert(1 <= len && len <= 1e5);
        assert(0 <= k && k <= 1e12);

        ll l = 0, r = 0;

        sf = smf = smsf = mf = msf = 0;
        z = -1;

        while(1)
        {
            if (s[r] == 0)
                break;

            assert('a' <= s[r] && s[r] <= 'z');

            if (s[r] == 'm')
            {
                smf += sf;
                mf++;
            }
            else if (s[r] == 's')
            {
                smsf += smf;
                sf++;
                msf += mf;
            }

            while (l <= r + 1 && smsf > k)
            {
                if (s[l] == 's')
                {
                    smsf -= msf;
                    smf -= mf;
                    sf--;
                }
                else if (s[l] == 'm')
                {
                    msf -= sf;
                    mf--;
                }

                l++;
            }

            if (smsf == k)
            {
                if (r - l + 1 > z)
                {
                    x = l, y = r, z = r - l + 1;
                }
            }

            r++;
        }

        if (z == -1)
        {
            printf("%lld\n", z);
        }
        else
        {
            printf("%lld %lld\n", x+1, y+1);
        }
    }

    return 0;
}
