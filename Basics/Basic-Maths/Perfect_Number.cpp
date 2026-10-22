#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPrime(int num)
    {
        // TC: O(√num)   — trial division up to √num
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    bool checkPerfectNumber(int n)
    {
        // Overall TC:
        //   • O(log n)      — if n does NOT have perfect-number form (early exit at shape check)
        //   • O(n^(1/4))    — if n DOES have perfect-number form (worst case, ~256 iters for int)
        if (n & 1)
        {
            return false;
        }

        int oddPart = n;         
        int trailingZeros = 0;  
        while (oddPart % 2 == 0) // TC: O(log n)   — at most log₂ n iterations
        {
            trailingZeros++;
            oddPart /= 2;
        }

        int primeExponent = trailingZeros + 1;  
        int mersenne = pow(2, primeExponent) - 1; // O(1)

        if (mersenne != oddPart) // O(1) — cheap shape check FIRST
            return false;

        if (!isPrime(primeExponent)) // TC: O(√primeExponent) = O(√(log n))
            return false;

        if (!isPrime(mersenne)) // TC: O(√mersenne)
            return false;       //    after shape check: mersenne ≈ √n → O(n^(1/4))

        return true;
    }

    bool checkPerfectNumber2(int n)
    {
        // TC: O(root(n)), SC: O(1);
        if (n == 1)
        {
            return false;
        }
        int sum = 1;
        for (int i = 2; i * i <= n; i++) // TC: O(n)
        {
            if (n % i == 0)
            {
                sum += i;
                sum += n / i;
            }
        }
        // cout<<sum<<" "<<n<<endl;
        if (sum == n)
        {
            return true;
        }
        return false;
    }

    bool checkPerfectNumber1(int n)
    {
        // TC: O(n), SC: O(1);
        int sum = 0;
        for (int i = 1; i < n; i++) // TC: O(n)
        {
            if (n % i == 0)
            {
                sum += i;
            }
        }
        // cout<<sum<<" "<<n<<endl;
        if (sum == n)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int num;
    cin >> num;

    Solution sol;
    bool ans = sol.checkPerfectNumber(num);
    cout << ans;
    return 0;
}