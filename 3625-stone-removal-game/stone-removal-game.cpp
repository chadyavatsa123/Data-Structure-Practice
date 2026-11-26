class Solution {
public:
    bool canAliceWin(int n) {
        int value=10;
        bool Alice=true;
        while(n>=value){
            n-=value;
            value--;
            Alice=!Alice;
        }
        return !Alice;
    }
};