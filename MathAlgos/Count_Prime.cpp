class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }
    int cnt=0;
    for (int p = 2; p < n; p++){
        if (prime[p])
            cnt++;
    }
    return cnt;
    }
};