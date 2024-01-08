class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> intervals;
        for(int i = 0; i < ranges.size(); i++){
            intervals.push_back({-ranges[i] + i, ranges[i] + i});
        }

        sort(intervals.begin(), intervals.end());
        int i = 0, start_time = 0, end_time = 0;
        int ans = 0;

        while(end_time < n){
            for(; i < intervals.size() && intervals[i][0] <= start_time; i++)
                end_time = max(end_time, intervals[i][1]);                   
            if(start_time == end_time)
                return -1;
            
            start_time = end_time;
            ans++;
        }
        return ans;
    }
};