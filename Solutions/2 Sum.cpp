class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v(2);
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=nums[i]; 
            int b=target-nums[i]; 
            if(mp.find(b)!=mp.end()){ 
                int second_value_index=mp[b];
                v[0]=second_value_index; 
                v[1]=i; 
                return v;
            }
            mp[nums[i]]=i; 
        }
        return v;
    }
};

// a+b=target
// a=target-b
// a+target-a = target