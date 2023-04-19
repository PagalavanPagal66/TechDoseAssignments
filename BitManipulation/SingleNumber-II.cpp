class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=31;i>=0;i--){
            int mask=1<<i;
            int cnt=0;
            for(auto i:nums){
                if(i&mask)cnt++;
            }
            if(cnt%3!=0)res|=mask;
        }
        return res;
    }
};