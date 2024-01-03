class Solution {
public:
    
    int shortestSubarray(vector<int>& nums, int k) {
        int len=INT_MAX;
        int n=nums.size();
        long long sum=0;
        int res=INT_MAX;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=k){
                res=min(res,i+1);
            }
            while(!pq.empty() && sum-pq.top().first>=k){
                int t=pq.top().second;
                res=min(res,i-t);
                pq.pop();
            }
            pq.push({sum,i});
        }
        return res==INT_MAX?-1:res;
    }
};