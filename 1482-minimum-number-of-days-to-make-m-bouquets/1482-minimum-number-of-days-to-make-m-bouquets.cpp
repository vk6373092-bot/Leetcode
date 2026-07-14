class Solution {
public:
        bool possible(vector<int>& bloomDay, int day,int m, int k){
            int count=0;
            int bouquet=0;
            for(int flower:bloomDay){
                if(flower<=day){
                    count++;
                    if(count==k){
                        bouquet++;
                        count=0;
                    }
                }
                else{
                    count=0;
                }
            }
                return bouquet>=m;
        }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need=(long long)m*k;
        if(need>bloomDay.size()) {
            return -1;
        }
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());

        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid, m,k)){
                    high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};