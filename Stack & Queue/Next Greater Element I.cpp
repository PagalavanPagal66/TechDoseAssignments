class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int ind=0;
        for(auto i:nums2){
            mp[i]=ind;
            ind++;
        }
        ind=0;
        stack<int>s;
        int n=nums2.size();
        s.push(INT_MIN);
        vector<int>nge;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<nums2[i]){
                s.pop();
            }
            if(!s.empty())
                nge.push_back(s.top());
            else
                nge.push_back(-1);
            s.push(nums2[i]);
        }
        reverse(nge.begin(),nge.end());
        vector<int>ans;
        for(auto i:nums1){
            ans.push_back(nge[mp[i]]);
        }
        return ans;
    }
};