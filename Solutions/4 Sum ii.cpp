class Solution {
public:
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        int n=nums1.size();
        unordered_map<int,int> mp; //o(1)
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=nums1[i]+nums2[j];
                mp[sum]++;
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=nums3[i]+nums4[j];
                if(mp.count(0-(sum))!=0){
                    count+=mp[0-(sum)];
                }
            }
        }
        return count;
    }
};
