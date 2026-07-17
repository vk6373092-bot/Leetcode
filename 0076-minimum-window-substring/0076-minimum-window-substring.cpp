class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(128,0);
        int start=0;
        for(char c:t)
            freq[c]++;
        int left=0;
        int right=0;
        int min_len=INT_MAX;
        int count=t.size();
        while(right<s.size()){
            // this is to expand the window
            if(freq[s[right]]>0)
            count--;
            freq[s[right]]--;
            right++;
            // now shrink the window we get
            while(count==0){
                if(right-left<min_len){
                    min_len=right-left;
                    start=left;
                }
                freq[s[left]]++;
                if(freq[s[left]]>0){
                    count++;
                }
                    left++;
            }
        }
        if(min_len==INT_MAX)
        return "";
        return s.substr(start,min_len);
    }
};