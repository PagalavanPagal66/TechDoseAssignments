class Solution {
public:
    int sorting(vector<int>& nums, int strt, int mid, int end){
        vector<int>sorted;
        int half=mid+1;
        int cnt=0;
        while(strt<=mid && half<end){
            if(nums[strt]<=nums[half]){
                sorted.push_back(nums[strt]);
                strt++;
            }
            else{
                sorted.push_back(nums[half]);
                cnt+=(mid-half+1);
                half++;
            }
        }
        while(strt<=mid){
            sorted.push_back(nums[strt++]);
        }
        while(half<end){
            sorted.push_back(nums[half++]);
        }
        return cnt;
    }
    int merge(vector<int>& nums, int strt, int end){
        int cnt=0;
        int mid=strt+(end-strt)/2;
        merge(nums,strt,mid);
        merge(nums,mid+1,end);
        cnt += sorting(nums,strt,mid,end);
        return cnt;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
           ans.push_back(merge(nums,0,nums.size()-1));
        }
        return ans;
    }
};