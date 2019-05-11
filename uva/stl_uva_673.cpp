#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k=1;
    char c;
    cin>>n;
    getchar();
    for(int i=1; i<=n; i++)
    {
        stack<char>s;
        s.push('a');
        string str;
        getline(cin,str);
        for(int k = 0; k < str.length(); k++)
        {
            c=str[k];
            if(c==')'||c=='(')
            {
                if(s.top()!=c-1)
                {
                    s.push(c);
                }
                else
                {
                    s.pop();
                }
            }

            else if(c=='['||c==']')
            {
                if(s.top()!=c-2)
                {
                    s.push(c);
                }
                else
                {
                    s.pop();
                }
            }
        }
        if(s.top()=='a')
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}
