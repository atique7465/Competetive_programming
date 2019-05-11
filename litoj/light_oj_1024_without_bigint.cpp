#include<bits/stdc++.h>
using namespace std;
vector<int>v;
vector<int>factors;
int status[10001];
int numfactor[10000];
vector<int>s1,s2;
vector<int>n1,n2;
int ans[4000];

void prime(int n)
{
    int i, j, sqrtn;
    for( i = 2; i <= n; i++ ) status[i] = 0;
    sqrtn = int( sqrt((double) n));
    for( i = 3; i <= sqrtn; i += 2 )
    {
        if( status[i] == 0 )
        {
            for( j = i * i; j <= n; j += i + i )
                status[j] = 1;
        }
    }
    v.push_back(1);
    v.push_back(2);
    for(i=3; i<=n; i+=2)
    {
        if( status[i] == 0 )
            v.push_back(i);
    }
}

void primefactorize(int n)
{
    if(n==1)
    {
        if(numfactor[n]==0)
        {
            factors.push_back(1);
            numfactor[n]=1;
        }
    }
    else if(n>1)
    {
        int sqrtn=int(sqrt((double)n));
        int i;
        for(i=1; v[i]<=sqrtn; i++)
        {
            int count=0;
            if(n%v[i]==0)
            {
                while(n%v[i]==0)
                {
                    n/=v[i];
                    count++;
                }
                if(numfactor[v[i]]==0)
                {
                    factors.push_back(v[i]);
                }
                if(count>numfactor[v[i]])
                {
                    numfactor[v[i]]=count;
                }
            }
        }
        if( n > 1 )
        {
            if(numfactor[n]==0)
            {
                factors.push_back(n);
                numfactor[n]=1;
            }
        }
    }
}

void multiplication(int r)
{
    int a[4000],b[4000];
    int i,j,tmp=0;
    int l1 = s1.size();
    int l2 = s2.size();
    for(i = l1-1,j=0; i>=0; i--,j++)
    {
        a[j] = s1[i];
    }
    for(i = l2-1,j=0; i>=0; i--,j++)
    {
        b[j] = s2[i];
    }
    for(i = 0; i < l2; i++)
    {
        for(j = 0; j < l1; j++)
        {
            ans[i+j] += b[i]*a[j];
        }
    }
    for(i = 0; i < l1+l2; i++)
    {
        tmp = ans[i]/10;
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + tmp;
    }
    for(i = l1+l2; i>= 0; i--)
    {
        if(ans[i] > 0)
            break;
    }
    s1.clear();
    for(; i >= 0; i--)
    {
        s1.push_back(ans[i]);
        ans[i]=0;
    }
    for(int q=0; q<4000; q++)
    {
        a[q]=0;
        b[q]=0;
    }
}

int main()
{
    prime(10000);
    int tc,cas=1;
    scanf("%d",&tc);
    while(cas<=tc)
    {
        int n;
        scanf("%d",&n);
        while(n>0)
        {
            int desec;
            scanf("%d",&desec);
            primefactorize(desec);
            n--;
        }
        int value=1;
        for(int z=1; z<=numfactor[factors[0]]; z++)
        {
            value=value*factors[0];
        }
        numfactor[factors[0]]=0;
        int h=value,m=value,dg;
        while(h>0)
        {
            h=h/10;
            dg=m-(h*10);
            n1.push_back(dg);
            m=h;
        }
        for(int w=n1.size()-1; w>=0; w--)
        {
            s1.push_back(n1[w]);
        }
        n1.clear();
        int t;
        for(t=1; t<factors.size(); t++)
        {
            int value2=1;
            for(int z2=1; z2<=numfactor[factors[t]]; z2++)
            {
                value2=value2*factors[t];
            }
            int h2=value2,m2=value2,dg2;
            while(h2>0)
            {
                h2=h2/10;
                dg2=m2-(h2*10);
                n2.push_back(dg2);
                m2=h2;
            }
            for(int w=n2.size()-1; w>=0; w--)
            {
                s2.push_back(n2[w]);
            }
            n2.clear();
            multiplication(1);
            s2.clear();
            numfactor[factors[t]]=0;
        }
        factors.clear();
        printf("Case %d: ",cas);
        for(int e=0; e<s1.size(); e++)
        {
            printf("%d",s1[e]);
        }
        printf("\n");
        s1.clear();
        cas++;
    }
    return 0;
}
