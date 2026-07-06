class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        long long num=0;
        //whitespace remove
        while(i<s.size()&& s[i]==' ')
                 i++;

                 //check sign
                 if(i<s.size()&& s[i]=='-'){
                    sign=-1;
                    i++;
                 }
                 else if(i<s.size()&& s[i]=='+'){
                    i++;
                 }

                 //now overflow terms
                 while(i<s.size()&& isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    if(sign*num>INT_MAX)
                    return INT_MAX;

                    if(sign*num<INT_MIN)
                    return INT_MIN;
                    i++;
                 }
                 return num*sign;

    }
};