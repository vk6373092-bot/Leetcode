class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int left=0;
        int max_length=0;
        int max_freq=0;
        for(int right=0;right<s.size();right++){
            freq[s[right]-'A']++;
            // make maximum frequency
            max_freq=max(freq[s[right]-'A'],max_freq);
            while((right-left+1)-max_freq>k){
                freq[s[left]-'A']--;
                left++; // here this is inside because this can be the case where we have to start out latter after so many left excedds;
                
            }
            max_length=max(max_length,right-left+1);
           
        }
        return max_length;

    }
};