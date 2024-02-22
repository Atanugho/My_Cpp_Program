#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int fbu(int n)
{
    if (n == 0 || n == 1)
        return n;
    dp.resize(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fbuo(int n)
{
    if (n == 0 || n == 1)
        return n;
    int a = 0;
    int b = 1;
    int c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main()
{

    int n;
    cin >> n;
    dp.resize(n + 1, -1);
    cout << fbu(n) << "\n";
    cout << fbuo(n) << "\n";
    return 0;
}