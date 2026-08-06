class Solution {
public:
    int smallestNumber(int n, int t) {
        
         int num=n;
        while(true){
             int prod=1;
            while(num>0){
                int digit=num%10;
                prod*=digit;
                num=num/10;
            }
            if(prod % t ==0)break;
           n=n+1;
           num=n;
        }
        return n;
    }
};