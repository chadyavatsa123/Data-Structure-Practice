class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int m=n;
        int sum=0;
        while(num){
            int digit=num%10;
            sum+=digit;
            num=num/10;

        }
        
        int prod=1;
        while(m){
            int digits=m%10;
            prod*=digits;
            m=m/10;
        }
        if(n%(sum+prod)==0)return true;
        return false;
    }
};