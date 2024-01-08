class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        string ans ="";
        while(pq.size()>=2){
            int cnt = pq.top().first;
            char a = pq.top().second;
            pq.pop();
            int cnt2 = pq.top().first;
            char a2 = pq.top().second;
            

            ans+=a;
            
            pq.pop();

            ans+=a2;
            if(cnt!=1){
                pq.push({cnt-1,a});
            }
            if(cnt2!=1){
                pq.push({cnt2-1,a2});
            }
        }
        if(pq.size()){
            if(pq.top().first >1){
                return "";
            }
            ans+=pq.top().second;
        }
        return ans;
    }
};