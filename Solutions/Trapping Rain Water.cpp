class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int n=height.size();
        int right=n-1; 
        // no other bars on the left to the 0 th index
        int leftm=height[0];
        // no other bars on the right to the n-1 th index 
        int rightm=height[n-1];
        // to store the ans
        int res=0;
        
        while(left<right){
            if(height[left]<=height[right]){ // water possibly can leak at the left index
                 res+=max(0,leftm-height[left]); // we have to store the water possibly in the current left 
                 leftm=max(leftm,height[left]);
                 left++;
            }
            else{
                res+=max(0,rightm-height[right]);
                rightm=max(rightm,height[right]);
                right--;
            }
        }
        return res;
    }
};
/*
if(leftm<height[left]){ no other bars heighter then currentleft . so we cant store any values
    continue;
}
else{
    res+=(leftm-height[left]);
}
*/