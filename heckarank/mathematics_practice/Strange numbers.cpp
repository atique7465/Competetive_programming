#include <iostream>
#include <vector>

using namespace std;

int t;
long long l,r;
vector<long long> V;
const unsigned long long MAX=1e+18;

int length(long long X)
{
    int sol=1;
    while (X>9){
        ++sol;
        X/=10;
    }
    return sol;
}

void precalc()
{
    V.clear();
    for(int i=0; i<10; ++i)
        V.push_back(i);

    for(int i=1; i<V.size(); ++i)
    {
        int len=length(V[i]);
        unsigned long long next=V[i]*len;

        for(int new_len=len; new_len<=len+2; ++new_len)
        {

            if (next>MAX) break;
            int L=length(next);
            if (L>1 && length(next)==new_len){
                V.push_back(next);
            }
            next+=V[i];
        }
    }
}

int solve(long long L, long long R)
{
    int res=0;
    for(int i=0; i<V.size(); ++i)
        if (L<=V[i] && V[i]<=R)
            ++res;
    return res;
}

int main()
{
    precalc();
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        cout << solve(l,r) << endl;
    }

    return 0;
}
