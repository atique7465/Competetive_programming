#include<bits/stdc++.h>
using namespace std;
int arn[60][2],arm[60][4];
int arnpl,arnpr;
int t,ans,n,m,i,j,k,d;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++)
        {
            for(j=0; j<=1; j++)
                scanf("%d",&arn[i][j]);
        }

        for(i=0; i<m; i++)
        {
            for(j=0; j<=3; j++)+
                scanf("%d",&arm[i][j]);
        }

        for(i=0; i<m; i++)
        {
            ans=0;
            for(k=0; k<n; k++)
            {
              //  cout<<ans<<endl;
                int x1=(arn[k][0]-arm[i][0]);
                int y1=(arn[k][1]-arm[i][1]);
                int x2=(arm[i][2]-arn[k][0]);
                int y2=(arm[i][3]-arn[k][1]);
                arnpl=(x1*x1)+(y1*y1);
                arnpr=(x2*x2)+(y2*y2);
                double p=sqrt((double) arnpl );
                double q=sqrt((double) arnpr );
                d=((arm[i][2]-arm[i][0])*(arm[i][2]-arm[i][0]))+((arm[i][3]-arm[i][1])*(arm[i][3]-arm[i][1]));
                 double v = sqrt((double) d );
                 //cout<<p<<" "<<q<<" "<<v<<endl;
                if((p+q)==v || abs(v-(p+q))<=0.00001)
                {
                    ans++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

