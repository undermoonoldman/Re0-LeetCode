/*9. Palindrome Number
 * Determine whether an integer is a palindrome. Do this without extra space.
 * Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.*/
#include <stdio.h>
#include <stdbool.h>
/*比较通用的解法是每次分别从数的头跟尾把所在位的数字取出来进行比对，如果相等，则去掉头尾位再新数上再执行如上操作*/
bool isPalindrome(int x)//还可以把一个整数倒转后从前往后比对，但这样会耗费额外的空间
{
    if(x < 0)//负数不被看为回文数
        return false;

    int len = 1;//记录数的长度
    while(x / len >= 10)//计算数的长度，用除的方法做判断，乘的方法会造成溢出
    {
        len *= 10;
    }
    if(len == 1)//个位数必定回文
        return true;
    int l;//头
    int r;//尾
    while(len > 1)//数头取得方式:除以长度的商 数尾的取得方式:除以十的余数
    {
        l = x / len;
        r = x % 10;
        if(l != r)
            return false;
        x = x % len;//去掉数头的方式:除以长度的余数 去掉数尾的方式:除以十的商
        x = x / 10;
        len = len / 100;//更新长度
    }
    return true;
}
void check(int number)
{
    if(isPalindrome(number))
        printf("ture! number:%d it is palindrome.\n",number);
    else
        printf("false! number:%d it is not palindrome\n",number);
}
int main()
{
    printf("Hello, World!\n");
    check(123);
    return 0;
}