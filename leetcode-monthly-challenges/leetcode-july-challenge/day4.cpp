class Solution
{
public:
    long int mod = 1e9 + 7;
    int countVowelPermutation(int n)
    {
        long int a[5][n];
        a[0][0] = 1;
        a[1][0] = 1;
        a[2][0] = 1;
        a[3][0] = 1;
        a[4][0] = 1;
        for (int i = 1; i < n; i++)
        {
            a[0][i] = (a[1][i - 1] + a[2][i - 1] + a[4][i - 1]) % mod;
            a[1][i] = (a[0][i - 1] + a[2][i - 1]) % mod;
            a[2][i] = (a[1][i - 1] + a[3][i - 1]) % mod;
            a[3][i] = (a[2][i - 1]) % mod;
            a[4][i] = (a[2][i - 1] + a[3][i - 1]) % mod;
        }
        return (a[0][n - 1] + a[1][n - 1] + a[2][n - 1] + a[3][n - 1] + a[4][n - 1]) % mod;
    }
};