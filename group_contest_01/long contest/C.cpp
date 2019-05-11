#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ss;
    int x, i, j, len, k;

    cin>>ss;
    len = ss.length();

    for(i=0; i<len; i++)
    {
        x = ss[i]-'0';
        if(x%8 == 0)
        {
            printf("YES\n");
            printf("%c", ss[i]);
            return 0;
        }
        for(j=i+1; j<len; j++)
        {
            x = (ss[i]-'0')*10+ss[j]-'0';
            if(x%8==0)
            {
                printf("YES\n");
                printf("%c%c", ss[i], ss[j]);
                return 0;
            }
            for(k=j+1; k<len; k++)
            {
                x = (ss[i]-'0')*100+(ss[j]-'0')*10+(ss[k]-'0');
                if(x%8==0)
                {
                    printf("YES\n");
                    printf("%c%c%c\n", ss[i], ss[j], ss[k]);
                    return 0;
                }
            }
        }
    }

    printf("NO\n");
    return 0;
}
