class Solution {
public:

    bool ispossible(vector<int>& weights, int days, int capacity){
        int count_days=1;
        int current_weight=0;
        for(int weight:weights){
            if(current_weight+weight<=capacity){
                current_weight+=weight;

            }else{
                count_days++;
                current_weight=weight;
            }
        }
        return count_days<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(weights,days,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};