class Solution {
public:
    void subs(vector<int>& nums,int strt,int end,vector<int>&v,int sum){
        if(strt>=end){
            v.push_back(sum);
            return ;
        }
        subs(nums,strt+1,end,v,sum);
        subs(nums,strt+1,end,v,sum+nums[strt]);
    }
    
    void search(int goal,vector<int>& left,vector<int>& right,int& ans){
        int l=left.size();
        int r=right.size();
        int lp=0,rp=r-1;
        while(lp<l && rp>=0){
            int temp = left[lp]+right[rp];
            ans=min(ans,abs(goal-temp));
            if(temp<goal){
                lp++;
            }
            else if(temp>goal){
                rp--;
            }
            else{
                break;
            }
        }
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        int mid=n/2;
        vector<int>left,right;
        subs(nums,0,mid+1,left,0);
        subs(nums,mid+1,n,right,0);
        int ans=INT_MAX;
        for(auto i:left){
            ans=min(ans,abs(goal-i));
        }
        for(auto i:right){
            ans=min(ans,abs(goal-i));
        }
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        search(goal,left,right,ans);
        return ans;
    }
};