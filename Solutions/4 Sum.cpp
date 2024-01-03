class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()); //sorting the array
        vector<vector<int>>res; //two dimensional array to store the result
        int n=nums.size(); //given array size
        
        
        ///--------------  a+b+c+d=target -----------------
        for(int i=0;i<n;i++){ // for finding a
            for(int j=i+1;j<n;j++){ //for finding b
                
                int left=j+1;
                int right=n-1;
                
                //searching next part of the array for the remaining sum to get target
                
                while(left<right){
                long long int sum=nums[i]+nums[j]; //a+b
                long long int x=nums[left]+nums[right]; //c+d
                if(sum+x==target){ 
                //answer found so we can add them to result
                    vector<int>t;
                    t.push_back(nums[left]);
                    t.push_back(nums[right]);
                    t.push_back(nums[i]);
                    t.push_back(nums[j]);
                    res.push_back(t);
                    while(left<n-1 && nums[left]==nums[left+1]){
                        // to avoid the repeat of the same number quadraplet
                        left++;
                    }
                    while(right>=1 && nums[right]==nums[right-1]){
                        right--;
                    }
                }
                if(sum+x<target){ //current value of a+b+c+d is not enought to get the target
                    left++;
                }
                else{
                    //current value of a+b+c+d is too high than the target
                    right--;
                }
                }
                while(j<n-1 && nums[j]==nums[j+1]){
                    j++;
                }
            }
            while(i<n-1 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return res;
    }
};