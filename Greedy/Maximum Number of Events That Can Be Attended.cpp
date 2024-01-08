class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int ans=0;
        int ind=0;
        int n=events.size();
        for(int i=0;i<=100000;i++){
            while(!pq.empty() && pq.top().first<i){
                pq.pop();
            }
            while(ind<n && events[ind][0]<=i){
                pq.push({events[ind][1],events[ind][0]});
                ind++;
            }
            if(pq.size()){
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};