class Solution {
public:
    int bina(int mid,vector<int>weights,int days){
        int val=0;
        int num=1;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+val<=mid){
                val+=weights[i];
            }
            else{
                val=weights[i];
                num++;
            }
        }
        if(num>days){
            return 0;
        }
        return 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int strt=*max_element(weights.begin(),weights.end());
        int n=weights.size();
        int end=0;
        for(auto i:weights){
            end+=i;
        }
        int temp=strt;
        while(strt<=end){
            int mid=(strt+end)/2;
            if(bina(mid,weights,days)==1){
                temp=mid;
                end=mid-1;
            }
            else{
                strt=mid+1;
            }
        }
        return temp;
    }
};