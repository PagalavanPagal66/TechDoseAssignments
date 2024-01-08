class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int pos;
        int len=0;
        for(int i=0;i<s.length();i++)
        {
            pos=s.find_last_of(s[i]);
            len=pos-i+1;
            for(int j=i+1; j<pos; j++)
            {
                if(s.find_last_of(s[j])>pos)pos=s.find_last_of(s[j]);
                len = pos-i+1;
            }
            i= pos;
            ans.push_back(len);
        }
        return ans;
    }
};