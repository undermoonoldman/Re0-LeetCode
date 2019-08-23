    class Solution {
        public int lengthOfLongestSubstring(String s) {
            //统计字母的频率，以字母的ascii码为下标
            int freq[] = new int[256];
            //当收缩左边界时会进行频度的减少，所以左边界的初始位置为0，即等待下标为0位置的字母被移除
            int l = 0;
            //当扩展右边界时才会进行频度的增加，所以右边界的初始位置为-1，即不包含任何字母
            int r = -1;
            //记录最长不含重复字母的子串长度
            int res = 0;
            //左边界未到达字符串尾部都是可以继续扩展的
            while(l < s.length()){
                //右边界向右扩展之后还没有出界而且新扩展位置的字母没有出现过
                //满足就向右扩展，并且更新频度
                if(r+1 < s.length() && freq[s.charAt(r+1)] == 0)
                    freq[s.charAt(++r)]++;
                //向右扩展之后越界或者是扩展位置字母已经存在了
                //满足就收缩左边界，并且更新频度
                else
                    freq[s.charAt(l++)]--;
                res = Math.max(res, r-l+1);
            }
            return res;
        }
    }