class Solution {
private:
    void getcomb(vector<int>& nums, int i, int t, vector<int>&cur, vector<vector<int>>&res){
        if(t == 0){
            res.push_back(cur);
            return;
        }
        if(t < 0 || i >= nums.size()) return;
        for(int k = i ; k < nums.size(); k++){
            cur.push_back(nums[k]);
            getcomb(nums, k, t-nums[k], cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>cur;
        vector<vector<int>>res;
        getcomb(candidates, 0, target, cur, res);
        return res;
    }
};