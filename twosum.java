class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,List<Integer>> map=new HashMap<>();

        for(int i=0;i<nums.length;i++){
            map.putIfAbsent(nums[i], new ArrayList<>());
            map.get(nums[i]).add(i);
        }

        int[] twosum=new int[2];
        int i=0;
       
        for(i=0;i<nums.length;i++){
            int complement=target-nums[i];

            if(map.containsKey(complement)){
                if(map.get(complement).size()>1){
                    twosum[0]=map.get(complement).get(0);
                    twosum[1]=map.get(complement).get(1);
                    break;
                }
                else{
                     twosum[0]=map.get(nums[i]).get(0);
                     twosum[1]=map.get(complement).get(0);
                }
            }
        }
        return twosum;
    }
}
