class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
       a) nums1.insert(nums1.end(),nums2.begin(),nums2.end());
       a) for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
            }
        sort(nums1.begin(),nums1.end()); O((m+n)log(n+m))
        int len=nums1.size(); -->(n+m)
        if(len%2!=0){ 
            double res=nums1[len/2];
            return res;
        }
        double res=nums1[len/2]+nums1[(len/2)-1];
        res/=2.0;
        return res;
        */
        //---------------------------------------------------
        if(nums2.size() < nums1.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int n1 = nums1.size(); // size of the small array
        int n2 = nums2.size(); 
        int start = 0; int end = n1; // used for binary search
        while(start <= end){
            int mid = (start + end)/2; //considering as the cut region in the array
            int rem = (n1 + n2 + 1)/2 - mid; //considering the cut region in the another array
            //even left1 or left2 is not possible. we are not taking in the consideration of taking a whole into a left or right.. We have to return the other left element as the largest element in the left array
            int left1 = INT_MIN; 
            int left2 = INT_MIN; 
            //even right1 or right2 is not possible. we are not taking in the consideration of taking a whole into a left or right.. We have to return the other right element as the smallest element in the right array
            int right1 = INT_MAX;
            int right2 = INT_MAX;
            //if(mid ==0 )partition is happening in the 0 th index -> so, we are considering a whole array as a right elements
            // if(rem ==0) paritition is happening in the 0 th index -> so, we are considering a whole array as a right elements 
            if(mid > 0){
                left1 = nums1[mid -1];
            }
            if(rem > 0){
                left2 = nums2[rem - 1];
            }
            //if(mid == n1)partition is happening in the n1 th index -> so, we are considering a whole array as a left elements
            //if(rem ==n2)partition is happening in the n2 th index -> so, we are considering a whole array as a left elements
            if(mid < n1){
                right1 = nums1[mid];
            }
            if(rem < n2){
                right2 = nums2[rem];
            }
            int a=max(left1,left2);
            int b=min(right1,right2);
            if(a<=b){ // possible segmentation
                if((n1+n2)%2 == 0){ //even length
                     return (max(left1, left2) + min(right1, right2))/2.0;
                }
                else {
                    return max(left1, left2);
                }
            }
            else if(left1 > right2){ // the array is not segmented properly... if this condition passes. we know that the partition produces some unsorted format
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return 0;
    }
};
        
        