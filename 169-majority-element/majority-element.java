class Solution {
    public int majorityElement(int[] nums) {
       HashMap<Integer,Integer>mp=new HashMap<>();
       for(int it:nums){
        mp.put(it,mp.getOrDefault(it,0)+1);
       }
       for(Map.Entry<Integer,Integer>it:mp.entrySet()){
       if(it.getValue()>nums.length/2)
       return it.getKey();
       }
       return -1;

    }
}