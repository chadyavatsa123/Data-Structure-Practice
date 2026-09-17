class Solution {
    public void moveZeroes(int[] nums) {
        int cnt=0;
        int k=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                cnt++;
                continue;
            }
            nums[k]=nums[i];
            k++;
            
        }
        while(cnt>0){
            nums[k]=0;
            cnt--;
            k++;
        }
    }
}