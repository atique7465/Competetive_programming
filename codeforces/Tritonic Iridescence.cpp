#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n;
    char s[100];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        cin>>s[i];
    }

    int count=0,ck1=0,ck2=0,ck3=0,t=1,kk=1;

    if(s[0]!='?'&&s[0]==s[1]){
            t=0;
            kk=0;
             printf("No\n");}

      if(s[0]=='?'&&n>0&&kk==1){
            s[0]='C';
                if(s[1]!=s[0]){
                        count++;
               }


                s[0]='M';
                if(s[1]!=s[0]){
                        count++;
                }

                 s[0]='Y';
                 if(s[1]!=s[0]){
                     count++;
                }
                if(count>=2){
                    ck1=1;
                }
                s[0]='?';
    }
  if(kk==1){
    for(i=1; i<n; i++)
    {
        if(s[i]=='?')
            {
                count=0;
                s[i]='C';
                if(s[i-1]!=s[i]&&s[i+1]!=s[i]){
                        count++;
               }


                s[i]='M';
                if(s[i-1]!=s[i]&&s[i+1]!=s[i]){
                        count++;
                }

                 s[i]='Y';
                 if(s[i-1]!=s[i]&&s[i+1]!=s[i]){
                     count++;
                }
                if(count>=2){
                     ck2=1;
                }
               s[i]='?';
            }

     else if(s[i]==s[i+1])
            {
                ck3=1;
                break;
            }
    }}
    if((ck1==1||ck2==1)&&ck3==0){
        printf("Yes\n");
        }
    else {
          if(t==1){
            printf("No\n");}}
    return 0;
}
