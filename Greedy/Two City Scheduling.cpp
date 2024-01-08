class Solution {
public:
    static bool compartor(vector<int>a,vector<int>b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans=INT_MAX;
        int n=costs.size()/2;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<costs.size();i++){
            pq.push({costs[i][0]-costs[i][1],i});
        }
        int sum=0;
        while(pq.size()>n){
            sum+=costs[pq.top().second][0];
            pq.pop();
        }
        while(!pq.empty()){
            sum+=costs[pq.top().second][1];
            pq.pop();
        }
        return sum;
        // sort(costs.begin(),costs.end(),compartor);
        // int s1=0,s2=0;
        // for(int i=0;i<n;i++){
        //     s1+=costs[i][0];
        // }   
        // for(int i=n;i<2*n;i++){
        //     s2+=costs[i][1];
        // }
        // ans=min(s1+s2,ans);
        // s1=0,s2=0;
        // for(int i=0;i<costs.size();i++){
        //     int temp=costs[i][0];
        //     costs[i][0]=costs[i][1];
        //     costs[i][1]=temp;
        // }
        // sort(costs.begin(),costs.end(),compartor);
        // for(int i=0;i<n;i++){
        //     s1+=costs[i][0];
        // }   
        // for(int i=n;i<2*n;i++){
        //     s2+=costs[i][1];
        // }
        // ans=min(s1+s2,ans);
        // return ans;
    }
};