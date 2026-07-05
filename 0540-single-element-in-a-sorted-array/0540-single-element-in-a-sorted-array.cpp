class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int low=0;
       int high=nums.size()-1;
       while(low<high){
        int mid=low+(high-low)/2;

        // first made mid even
        if(mid%2==1){
            mid--;
        }
        //if it is a pair so
        if(nums[mid]==nums[mid+1]){
            low=mid+2;
        }else{
            high=mid;
        }
       } 
       return nums[low];
    }
};