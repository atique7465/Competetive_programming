#include<bits/stdc++.h>
using namespace std;
int arr1[10],arr2[10];
int main()
{
    int n,ck=1;
    char s[10];
    char a[]="M";
    char b[]="S";
    char c[]="XS";
    char d[]="XXS";
    char e[]="XXXS";
    char f[]="L";
    char g[]="XL";
    char h[]="XXL";
    char i[]="XXXL";
    scanf("%d",&n);
       while(ck<=n)
       {
           cin>>s;
           if(strcmp(s,a)==0)
           {
               arr1[1]++;
           }
           else if(strcmp(s,b)==0)
           {
               arr1[2]++;
           }
           else if(strcmp(s,c)==0)
           {
               arr1[3]++;
           }
           else if(strcmp(s,d)==0)
           {
               arr1[4]++;
           }
           else if(strcmp(s,e)==0)
           {
               arr1[5]++;
           }
           else if(strcmp(s,f)==0)
           {
               arr1[6]++;
           }else if(strcmp(s,b)==0)
           {
               arr1[2]++;
           }else if(strcmp(s,b)==0)
           {
               arr1[2]++;
           }
           else if(strcmp(s,g)==0)
           {
               arr1[7]++;
           }
           else if(strcmp(s,h)==0)
           {
               arr1[8]++;
           }
           else if(strcmp(s,i)==0)
           {
               arr1[9]++;
           }
           ck++;
       }
       ck=1;
       while(ck<=n)
       {
           cin>>s;
           if(strcmp(s,a)==0)
           {
               arr2[1]++;
           }
           else if(strcmp(s,b)==0)
           {
               arr2[2]++;
           }
           else if(strcmp(s,c)==0)
           {
               arr2[3]++;
           }
           else if(strcmp(s,d)==0)
           {
               arr2[4]++;
           }
           else if(strcmp(s,e)==0)
           {
               arr2[5]++;
           }
           else if(strcmp(s,f)==0)
           {
               arr2[6]++;
           }else if(strcmp(s,b)==0)
           {
               arr2[2]++;
           }else if(strcmp(s,b)==0)
           {
               arr2[2]++;
           }
           else if(strcmp(s,g)==0)
           {
               arr2[7]++;
           }
           else if(strcmp(s,h)==0)
           {
               arr2[8]++;
           }
           else if(strcmp(s,i)==0)
           {
               arr2[9]++;
           }
           ck++;
       }
       int count=0;
       int j;
       for(j=1; j<10; j++)
       {
           if(arr1[j]<arr2[j])
           {
               count=count+(arr2[j]-arr1[j]);
           }
       }
       printf("%d",count);
    return 0;
}
