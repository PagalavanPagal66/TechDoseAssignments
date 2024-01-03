class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        string ar="";
        while(!pq.empty()){
            int freq=pq.top().first;
            char a=pq.top().second;
            pq.pop();
            for(int i=0;i<freq;i++){
                ar+=a;
            }
        }
        return ar;
    }
};