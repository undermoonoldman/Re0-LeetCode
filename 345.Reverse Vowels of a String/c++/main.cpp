/**345. Reverse Vowels of a String
 * Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".*/
#include <iostream>
using namespace std;

class Solution
{
private:
    bool isVowel(char c)//注意大小写
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }
public:
    string reverseVowels(string s)
    {
        int l = 0;
        int r = s.length() - 1;
        while(l < r)
        {
            while(!isVowel(s[l])) l++;
            while(!isVowel(s[r])) r--;
            if(l >= r) break;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};

int main()
{
    string a = "hello";
    string b = Solution().reverseVowels(a);
    cout<<b;
    return 0;
}