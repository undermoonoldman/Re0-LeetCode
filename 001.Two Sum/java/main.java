    class Solution {
        public int[] twoSum(int[] nums, int target) {
            HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
            int[] index = new int[2];
            // 将数组中所有元素的值与下标存入map中，可以会出现同样值但不同下标被覆盖的情况，最终只会留下最后一个数，之前的都被覆盖了
            for(int i = 0 ; i < nums.length ; i++){
                map.put(nums[i], i);
            }

            for(int i = 0 ; i < nums.length ; i++){
                //取出数组中每个位置的值，在map中找是否能有与之加和为target的数
                Integer temp = (Integer)map.get(target - nums[i]);
                //题目中说答案肯定是不同下标的两个位置，这样如果出现同一个值但是两个不同下标的这种答案的话，那么相同的值最多有两个
                //由于map中存储的是相同值最后一个下标的位置，所以我们只要判断满足条件的值下标不相同就行了
                if(temp != null && temp.intValue() != i){
                    index[0] = i;
                    index[1] = temp;
                    break;
                }
            }
            return index;
        }
    }