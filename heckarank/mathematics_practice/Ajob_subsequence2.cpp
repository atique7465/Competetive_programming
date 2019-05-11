#include <bits/stdc++.h>
using namespace std;

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sgn(x,y) ((x)+eps<(y)?-1:((x)>eps+(y)?1:0))
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((i64)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<i64> vi;
typedef vector<st> vs;
typedef map<i64,i64> mii;
typedef map<st,i64> msi;
typedef set<i64> si;
typedef set<st> ss;
typedef pair<i64,i64> pii;
typedef vector<pii> vpii;

i64 mod;

i64 Pow(i64 b,i64 p,i64 m){
    i64 ret=1;
    for(i64 i=(1LL<<62); i; i>>=1){
        ret=(ret*ret)%m;
        if(p&i) ret=(ret*b)%m;
    }
    return ret;
}

i64 factmod (i64 n,i64 p) {
    i64 res = 1;
    while (n > 1) {
        res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
        for (i64 i=2; i<=n%p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}

i64 calc(i64 a,i64 b){
    i64 now=1;
    i64 ret=0;
    while(now<=a/b){
        now*=b;
        ret+=a/now;
    }
    return ret;
}

i64 NCR(i64 n,i64 r){
    i64 powerOfMod=0;
    i64 ret=factmod(n,mod); powerOfMod+=calc(n,mod);
    i64 down=factmod(r,mod); powerOfMod-=calc(r,mod);
    down*=factmod(n-r,mod); powerOfMod-=calc((n-r),mod);
    down%=mod;
    down=Pow(down,mod-2,mod);
    ret*=down;
    ret%=mod;
   if(powerOfMod>0)return 0;
    return ret%mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    int test;
    cin>>test;
    while( test-- ){
        i64 n,k,p;
        cin>>n>>k>>p;
        mod=p;
        cout<<NCR(n+1,n-k)<<endl;
    }
    return 0;
}
