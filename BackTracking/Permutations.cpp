class Solution {
public:
vector<vector<int>> ans;
void permutation(vector<int>&a, int ind, int n)
{
if(ind==n)
{
ans.push_back(a);
return;
}
for(int i=ind;i<n;i++)
{
swap(a[ind],a[i]);
permutation(a,ind+1,n);
swap(a[ind],a[i]);
}
}
vector<vector<int>> permute(vector<int>& nums) {
permutation(nums,0,nums.size());
return ans;
}
};