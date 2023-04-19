class Solution {
public:
   string db(int n)
    {
    string res = bitset<64> (n).to_string();
     
    const auto loc1 = res.find('1');
     
    if(loc1 != string::npos)
        return res.substr(loc1);
     
    return "0";
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            string temp=db(i);
            int res=0;
            for(auto i:temp){
                if(i=='1'){
                    res++;
                }
            }
            ans.push_back(res);    
        }   
        return ans;
    }
};