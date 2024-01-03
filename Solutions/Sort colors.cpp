class Solution {
public:
    void sortColors(vector<int>& nums) {
        int rcnt=0;
        int wcnt=0;
        int bcnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                rcnt++;
            }
            else if(nums[i]==1){
                wcnt++;
            }
            else{
                bcnt++;
            }
        }
        int ind=0;
        while(rcnt--){
            nums[ind++]=0;
        }
        while(wcnt--){
            nums[ind++]=1;
        }
        while(bcnt--){
            nums[ind++]=2;
        }
    }
};