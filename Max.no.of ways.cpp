#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout <<"Enter the number of coins: ";
    cin >> n;

    int coin[n];
    for(int i=0; i<n; i++)
    {
        cin >> coin[i];
    }

    int a;
    cout <<"Enter the amount: ";
    cin >> a;
    int table[n+1][a+1];

    for(int i=0; i<=n; i++)
    {
        table[i][0]=0;
    }
    for(int j=1; j<=a; j++)
    {
        if(j % coin[0]==0)
        {
            table[0][j]=1;
        }
        else
        {
            table[0][j]=0;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=a; j++)
        {
            if(j>=coin[i])
            {
                table[i][j]=table[i-1][j]+table[i][j-coin[i]];
            }
            else{
                table[i][j]=table[i-1][j];
            }
        }
    }

    cout << "Maximum number of ways of coin change: " <<table[n-1][a] <<endl;
}
