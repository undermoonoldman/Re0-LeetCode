/**401. Binary Watch
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".*/


#include <iostream>
#include <vector>
#include <map>
using namespace std;

void showVector(vector<string>& ret)
{
    cout<<"result is : "<<endl;
    cout<<"{";
    for(string i : ret)
        cout<<i<< ", ";

    cout<<"}"<<endl;
}

class Solution
{
private:
    vector<int> mark;

    vector<bool> used;

    vector<int> sum;

    map<int,bool> check;

    int doSum()
    {
        int ret = 0;
        for(int i : sum)
            ret += i;

        return ret;
    }

    string numToTime(int num)
    {
        int remainder = num % 60;

//        if((num / 60 ) > 11)
//            return "";

        int quotient = num / 60;
        string ret;
        if(remainder < 10)
            ret = to_string(quotient) + ":" + "0" + to_string(remainder);
        else
            ret = to_string(quotient) + ":" + to_string(remainder);

        return ret;
    }

    void helper(vector<string>& ret, int step)
    {
        if(step == 0)
        {
            int temp = doSum();
            if(check.count(temp) == false)
            {
                if(numToTime(temp) != "")
                {
                    ret.push_back(numToTime(temp));
                    check.insert(pair<int,bool>(temp, true));
                }
            }

            return;
        }

        for(int i = 0 ; i < 10 ; i++)
        {
            if(used[i] == false)
            {
                used[i] = true;
                sum.push_back(mark[i]);
                helper(ret, step-1);
                used[i] = false;
                sum.pop_back();
            }
        }
    }

public:


    vector<string> readBinaryWatch(int num)
    {
        vector<string> ret;
        mark.push_back(1);
        mark.push_back(2);
        mark.push_back(4);
        mark.push_back(8);
        mark.push_back(16);
        mark.push_back(32);
        mark.push_back(60);
        mark.push_back(120);
        mark.push_back(240);
        mark.push_back(480);
        used = vector<bool>(10, false);

        helper(ret, num);
        ret.clear();
        map<int, bool> ::iterator it;
        for(it = check.begin() ; it != check.end() ; it++)
            ret.push_back(numToTime(it->first));
        return ret;
    }
};



int main()
{
    vector<string> ret = Solution().readBinaryWatch(4);
    showVector(ret);
    return 0;
}