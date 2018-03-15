/**125. Valid Palindrome
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

*/
#include <iostream>
using namespace std;

class Solution
{
private:
    bool check(char c)//判断字符合法性，数字 0~9 字母 a-z A-Z,坑很多
    {
        if((int(c) >= 48 && int(c) <= 57) || (int(c) >= 65 && int(c) <= 90) || (int(c) >= 97 && int(c) <= 122))
            return true;
        else
            return false;
    }

    bool equal(char a, char b)//字符相同比较，分字符与数字两种情况
    {
        if((int(a) >= 48 && int(a) <= 57) && (int(b) >= 48 && int(b) <= 57))
            return a== b;
        else if((int(a) >= 65 && int(a) <= 122) && (int(b) >= 65 && int(b) <= 122))
            return (a == b) || (a - b == 32) || (b - a == 32);
        else
            return false;
    }

public:
    bool isPalindrome(string s)
    {
        if(s == "") return true;
        int l = 0;
        int r = s.length()-1;
        while(true)
        {
            while(check(s[l]) == false) l++;
            while(check(s[r]) == false) r--;
            if(l >= r) break;
            if(!equal(s[l], s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};

int main()
{
    string a = "`l;`` 1o1 ??;l`";
    bool b = Solution().isPalindrome(a);
    cout<<b;

    return 0;
}