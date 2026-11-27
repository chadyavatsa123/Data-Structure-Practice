class Solution {
public:
    int myAtoi(string s) {
   /*    int i=0;
       while(s[i]==' ')i++;
       int sign=1;
      if(s[i]=='+' || s[i]=='-'){
       if(s[i]=='-')
       sign=-1;
       i++;
      }
       long ans=0;
       while(s[i]>='0' && s[i]<='9'){
        ans=ans*10+(s[i]-'0');
        if(ans*sign>INT_MAX)return INT_MAX;
        if(ans*sign<INT_MIN)return INT_MIN;
        i++;
       } 
       return ans*sign;*/
       int i=0;
       while(s[i]==' ')i++;
       int sign=1;
       if(s[i]=='+' ||s[i]=='-'){
         if(s[i]=='-')
          sign=-1;
          i++;
       }
      
       long res=0;
       while(s[i]>='0' && s[i]<='9'){
         res=res*10+(s[i]-'0');
         if(res*sign>INT_MAX)return INT_MAX;
         else if(res*sign<INT_MIN)return INT_MIN;
         i++;
       }
       return res*sign;
    }
};