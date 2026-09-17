class Solution {
    public int removeDuplicates(int[] nums) {
        Set<Integer>st=new HashSet<>();
        int k=0;
        for(int i=0;i<nums.length;i++){
            if(!st.contains(nums[i])){
                st.add(nums[i]);
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
}