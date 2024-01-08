class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        for(auto i:tasks){
            mp[i]++;
            maxi=max(maxi,mp[i]);
        }
        int cnt=0;
        for(auto i:mp){
            if(i.second == maxi)cnt++;
        }
        int tasksize = tasks.size();
        return max(tasksize,(maxi-1)*(n+1)+cnt);
    }
};