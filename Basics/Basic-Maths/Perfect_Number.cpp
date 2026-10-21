#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPerfectNumber(int n)
    {
        //TC: O(root(n)), SC: O(1);
        if(n==1)
        {
            return false;
        }
        int sum=1;
        for(int i=2;i*i<=n;i++) //TC: O(n)
        {
            if(n%i==0)
            {
                sum+=i;
                sum+=n/i;
            }
        }
        // cout<<sum<<" "<<n<<endl;
        if(sum==n)
        {
            return true;
        }
        return false;
    }

    bool checkPerfectNumber1(int n)
    {
        //TC: O(n), SC: O(1);
        int sum=0;
        for(int i=1;i<n;i++) //TC: O(n)
        {
            if(n%i==0)
            {
                sum+=i;
            }
        }
        // cout<<sum<<" "<<n<<endl;
        if(sum==n)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int num;
    cin>>num;

    Solution sol;
    bool ans=sol.checkPerfectNumber(num);
    cout<<ans;
    return 0;
}