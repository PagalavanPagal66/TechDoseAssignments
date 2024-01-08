class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0;
        int n=colors.size();
        for(int i=1;i<n;i++){
            int j=i;
            int s=neededTime[j-1];
            int mx=neededTime[j-1];
            while(colors[j]==colors[j-1]){
                mx=max(mx,neededTime[j]);
                s+=neededTime[j];
                j++;
                i=j-1;
            }
            time+=s-mx;
        }
        return time;
    }
};