class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            //on right side 
            if(nums[mid]>nums[high]){
               low=mid+1; 
            }
            // if it in the left  side then no. alsways be in left see ex 3
            else{
                high=mid;
            }
        }
        return nums[low];
    }
};