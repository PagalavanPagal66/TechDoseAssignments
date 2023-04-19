class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0;
        int cnt=0;
        int half=nums.size()/2;
        for(int i=31;i>=0;i--){
            cnt=0;
            int mask=1<<i;
            for(auto j:nums){
                if(j&mask){
                    cnt++;
                }
            }
            if(cnt>half)
            res|=mask;
        }
        return res;
    }
};