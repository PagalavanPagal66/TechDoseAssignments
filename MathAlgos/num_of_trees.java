class Solution {
    public int numTrees(int n) {
        int cat[]=new int[n+1];
        cat[0]=1;
        cat[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                cat[i]+=cat[j]*cat[i-j-1];
            }
        }
        return cat[n];

        
    }
}