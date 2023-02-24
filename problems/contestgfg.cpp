long long solve(long long a, long long b) {
        // code here
        long long n=max(a,b);
        long long mval=INT_MAX;
        
        for(long long x=1;x<=n;x++){
            long long ans= (a&x) + (b&x);
            if(ans<mval){
                mval=ans;
            }
        }
        return mval;
}


//

long long solve(long long a, long long b) {
    long long minVal = LONG_LONG_MAX;
    long long x = 1;
    while (x <= max(a, b)) {
        minVal = min(minVal, (a & x) + (b & x));
        x = x << 1;
    }
    return minVal;
}


//
class Solution{
    private:
    int countUnsetBits(int N){
    int c = 0;
    while (N) {
 
        if (N % 2 == 0) {
            c += 1;
        }
        N = N >> 1;
    }
    return c;
}
    public:
    int count(int N)
    {
        int unsetbits = countUnsetBits(N);
        int ans = 1 << unsetbits;
        int count = N-ans;
        
        return count+1;
    }
};
