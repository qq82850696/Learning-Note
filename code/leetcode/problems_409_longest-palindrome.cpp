
/* 
data-time 2020-03-19 14:14:53


题目描述:

409. 最长回文串

给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

/**
主要思路使用unordered_map 统计字符出现的次数，添加所有的偶数次数
 */

#include <cmath>
#include <cctype>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <cstdint>

using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
            int res=0;
            if(s.size()<1) return s.size();
            unordered_map<char ,int> char_dict;
            for(int i=0;i<s.size();++i){
                if(char_dict.find(s[i])!=char_dict.end()){
                        ++char_dict[s[i]];
                }else{
                    char_dict[s[i]]=1;
                }
            }
            int is_single=0;
            for(auto temp:char_dict){
                res+=(temp.second/2)*2;
            }
            if(res<s.size()){
                ++res;
            }
            return res;
    }
};

//关闭流输出
static auto static_lambda = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();

int main(int argc,char* argv[]){
    Solution a;
    vector<int> temp={0,2,1,-6,6,-7,9,1,2,0,1};
    a.longestPalindrome("ccc");
    return 0;
}
/*
优质解析1:思路相同使用数组作为统计

class Solution{
    public:
        int longestPalindrome(string s){
            int flag= 0;
            int char_map[128] = {0};
            int max_length = 0;
            for(int i=0;i<s.length();i++){
                char_map[s[i]] += 1;
            }
            for(int i=0;i<128;i++){
                if(char_map[i] % 2 == 0){
                    max_length+=char_map[i];
                }
                else{
                    max_length += char_map[i] -1;
                    flag = 1;
                }
            }
            return max_length + flag;
        }

};

//官方题解：
https://leetcode-cn.com/problems/longest-palindrome/solution/zui-chang-hui-wen-chuan-by-leetcode-solution/
//优质解析1:
https://leetcode-cn.com/problems/longest-palindrome/solution/409-zui-chang-hui-wen-chuan-shuang-100ti-jie-by-yx/
*/