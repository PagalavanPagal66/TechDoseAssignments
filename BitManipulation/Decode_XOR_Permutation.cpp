class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int odd=0;
        for(int i=1;i<=encoded.size()+1;i++){
            odd^=i;
        }
        for(int i=1;i<encoded.size();i+=2){
            odd^=encoded[i];
        }
        vector<int>res;
        res.push_back(odd);
        for(auto i:encoded){
            odd^=i;
            res.push_back(odd);
        }
        return res;
    }
};