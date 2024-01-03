class Solution {
public:
    int select(vector<int>&nums, int l, int r, int k){
        int pivot=nums[r];
        int p = l;
        for(int i=l;i<r;i++){
            if(pivot>=nums[i]){
                swap(nums[p],nums[i]);
                p++;
            }
        }
        swap(nums[p],nums[r]);
        return p;
    }
    int quick_part(vector<int>&nums, int l,int r,int k){
        int half = select(nums,l,r,k);
        if(half == k){
            return nums[half];
        }
        if(half<k){
            return quick_part(nums,half+1,r,k);
        }
        else{
            return quick_part(nums,l,half-1,k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quick_part(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
