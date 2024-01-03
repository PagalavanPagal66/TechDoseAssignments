class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> result;
        if(interval.size()==0)return result;
        sort(interval.begin(),interval.end());
        result.push_back(interval[0]);
        int j=0;
        for(int i=1;i<interval.size();i++)
        {
            if(result[j][1]>=interval[i][0]){
                 result[j][1]=max(result[j][1],interval[i][1]);
            }
            else
            {
                j++;
                result.push_back(interval[i]);
            }
        }
        return result;
    }
};