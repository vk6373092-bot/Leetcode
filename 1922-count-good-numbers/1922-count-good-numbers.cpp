class Solution {
public:

    // dispaly mod 
    long long mod=1e9+7;
        int power(long long x,long long n){
            //base case
            if(n==0){
                return 1;
            }
           long long half=power(x,n/2);
           //if even
           if(n%2==0){
            return (half*half)%mod;
           }else{
            // if odd
            return x*(half*half)%mod;
           }
        }

    int countGoodNumbers(long long n) {
        long long even= (n+1)/2; // no. of even index 0,2,4,6,8
        long long odd=n/2; // no. odd odd 2,3,5,7, question ma likha ha
        // no. of side ways
        long long evenways=power(5,even);
         long  long  oddways=power(4,odd); 
        
        //return no. of ways
        return (evenways*oddways)%mod;
    }
};