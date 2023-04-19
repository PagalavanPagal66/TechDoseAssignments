class Solution {
public:
    int hammingDistance(int x, int y) {
        int c = 0;
        for(int i=31;i>=0;i--) if((x& 1<<i)^(y& 1<<i)) c++;
        return c;
    }
};