class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int sumgas=0;
        int sumcost=0;
        for(int i=0;i<gas.length;i++){
            sumgas+=gas[i];
            sumcost+=cost[i];
        }
        if(sumgas<sumcost){
            return -1;
        }
        int res=0;
        int tot=0;
        for(int i=0;i<gas.length;i++){
            tot+=(gas[i]-cost[i]);
            if(tot<0){
                tot=0;
                res=i+1;
            }
        }
        return res;
    }
}