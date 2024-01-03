class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int m=a.size();
        int n=a[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
                int temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
        }
        int strt=0,end=n-1;
        while(strt<=end){
            for(int i=0;i<m;i++){
                 int swap=a[i][strt];
                 a[i][strt]=a[i][end];
                 a[i][end]=swap;
            }
            strt++;
            end--;
        }
    }
};