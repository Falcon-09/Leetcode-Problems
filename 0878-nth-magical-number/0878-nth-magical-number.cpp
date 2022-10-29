class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long l = min(a,b);
        long long r = l*n;
        int mod = 1e9+7;
        
        int lcm = (a*b)/__gcd(a,b);
        
        while(l<=r){
            long long mid = l+(r-l)/2;
            long long f = mid/a+mid/b-mid/lcm;
            if(f<n) l=mid+1;
            else r=mid-1;
        }
        
        return l%mod;
    }
};