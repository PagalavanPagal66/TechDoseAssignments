class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int ans = 0, n = prices.size()-1;
        for(int i=0; i < n; i++){
            ans += max(prices[i+1]-prices[i],0);
        }
        return ans;
    }
};