class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int l=0;
        int r=0;
        int mxlen=0;
        while(r<nums.length){
            if(nums[r]==0){
                l=r+1;
            }
            if(nums[r]==1){
                mxlen=Math.max(mxlen,r-l+1);
            }
            r++;

        }
        return mxlen;

    }
}