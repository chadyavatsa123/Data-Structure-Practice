class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int bottom1=rec1[0];
        int left1=rec1[1];
        int top1=rec1[2];
        int right1=rec1[3];
        int bottom2=rec2[0];
        int left2=rec2[1];
        int top2=rec2[2];
        int right2=rec2[3];
        if(left2>=right1)return false;
        else if(bottom2>=top1)return false;
        else if(right2<=left1)return false;
        else if(top2 <= bottom1)return false;
        return true;
    }
};