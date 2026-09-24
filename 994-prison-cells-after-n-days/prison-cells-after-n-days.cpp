class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<string,int>mpp;
        while(n>0){
            string state="";
            for(int it:cells)
            state+=(it+'0');
            if(mpp.count(state)){
                int m=mpp[state]-n;
                n=n%m;
            }
            else{
            mpp[state]=n;
            }
            if(n>0){
                vector<int>temp(cells.size(),0);
                for(int i=1;i<cells.size()-1;i++){
                temp[i]=cells[i-1]==cells[i+1];
                }
                cells=temp;
                n--;
            }
           
                
            
        }
        return cells;
    }
};