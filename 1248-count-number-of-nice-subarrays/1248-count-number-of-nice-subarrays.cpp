class Solution {
public:
    int solve(vector<int>& nums, int k){
        int left=0;
        int odd=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]%2==1){
               odd++;
            }
            while(odd>k){
                if(nums[left]%2==1){
                    odd--;
                }
                left++;    
            }
            ans+=right-left+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
          return solve(nums,k)-solve(nums,k-1);
    }
};