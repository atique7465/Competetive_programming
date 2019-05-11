#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ar[28];
    for(int k=0; k<28; k++)
    {
      ar[k]=9999999;
    }

    int n,i,j,l,r;
    char s[300010];
    scanf("%d",&n);
    for(i=0; i<=n; i++)
    {
        scanf("%c",&s[i]);
       if(ar[s[i]-96]==9999999)
            ar[s[i]-96]=i;
    }
  // for(i=1; i<=n; i++)
  //  {
     //  cout<<ar[i]<<" ";
   // }

    int ck=0;
    for(i=1; i<=n; i++)
    {
      //cout<<s[i]<<" "<<s[i]-96<<endl;
      for(j=s[i]-96+1; j<=26; j++)
      {
           //cout<<"k"<<j<<endl;
          if(ar[j]<i)
          {
              r=i;
              l=ar[j];
              ck=1;
              break;
          }
      }
      if(ck==1)
            break;
    }

    if(ck==0)
        printf("NO");
    else
    printf("YES\n%d %d",l,r);

    return 0;
}
