#include<bits/stdc++.h>
using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int> > arr)
{
    int res=-9999999,sum;
    for (int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            sum=0;
            sum+=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            if(sum>res)
            {
                res=sum;
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int> > arr(6);
    for (int i = 0; i < 6; i++)
    {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
        }

    }

    int result = hourglassSum(arr);

    cout << result;

    return 0;
}
