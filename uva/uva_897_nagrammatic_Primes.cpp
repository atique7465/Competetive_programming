#include<bits/stdc++.h>
using namespace std;
int k=1000;
int status[501];
vector<int>v,v2,v3;
int used[20],number[20],cw=0;
void permutation(int at, int n)
{
    int i;
    if(at==n+1)
    {
        int e;
        for(i=n; i>0; i--)
        {
            e=number[i]-1;
            v3.push_back(v2[e]);
        }
        int kl,g=1,f,p=v3.size()-1;
        kl=v3[p];
        for(f=v3.size()-2; f>=0; f--)
        {
            g=g*10;
            kl=kl+(v3[f]*g);
        }
        if(status[kl>>1]!=0)
        {
            cw=1;
        }
        v3.clear();
        return;
    }

    for(i=1; i<=n; i++)
    {
        if(!used[i])
        {
            used[i]=1;
            number[at]=i;
            permutation(at+1,n);
            used[i]=0;
        }
    }
}

int main()
{
    int i,j,sqrtk;
    string s;
    sqrtk=int(sqrt((double)k));
    for(i=3; i<=sqrtk; i+=2)
    {
        if(status[i>>1]==0)
        {
            for(j=i*i; j<=k; j+=2*i)
                status[j>>1]=1;
        }
    }
    v.push_back(2);
    for(i=3; i<=k; i+=2)
    {
        if(status[i>>1]==0)
            v.push_back(i);
    }

    while((cin>>s)&&(s[0]!='0'))
    {
        int g=1,n=s[s.size()-1]-48,last=0,p;
        for(i=s.size()-2; i>=0; i--)
        {
            g=g*10;
            n=n+(s[i]-48)*g;
        }
        last=g*10;

        int start,end,mid,ck;
        start=0;
        end=v.size()-1;
        mid=(start+end)/2;
        while(start<=end)
        {
            if(v[mid]==n)
            {
                ck=mid+1;
                break;
            }
            else if(v[mid]>n)
            {
                end=mid-1;

            }
            else
            {
                start=mid+1;
            }

            mid=(start+end)/2;
        }
        if (start > end)
        {
            ck=start;

        }

        for(p=ck; v[p]<=last; p++)
        {
            v2.clear();
            int m,h=v[p],d=0,sckt1=0,sckt2=0;
            if(h<10)
            {
                printf("%d\n",h);
                break;
            }
            else if(h>=1000)
            {
             printf("0\n");
                break;
            }
            else if(h>10&&h<1000)
            {
                while(h>0)
                {
                    m=h;
                    h=h/10;
                    d=m-(h*10);
                    if(d%2==0)
                    {
                        sckt1=1;
                        break;
                    }
                    if(d%2!=0)
                    {
                        sckt2=1;
                    }
                    v2.push_back(d);
                }

                if(sckt1==1)
                {
                    continue;
                }
                else if(sckt2==1)
                {
                    permutation(1,v2.size());
                    if(cw==1)
                    {
                        cw=0;
                        continue;
                    }
                    else
                    {
                        printf("%d\n",v[p]);
                        break;
                    }
                }
                else if(sckt1==0&&sckt2==0)
                {
                    printf("%d\n",v[p]);
                    break;
                }
            }
        }
            if(v[p]>=last)
            {
                printf("0\n");
            }
    }
    return 0;
}
