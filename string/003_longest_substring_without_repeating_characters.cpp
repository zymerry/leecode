/**
 * 3. 无重复字符的最长子串 (Longest Substring Without Repeating Characters)
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/
 *
 * 题目描述:
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
 * 
 * 示例 1:
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
 * 
 * 示例 2:
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 示例 3:
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 *      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 提示：
 * 0 <= s.length <= 5 * 104
 * s 由英文字母、数字、符号和空格组成.
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> lookup;
        int ret = 0;
        int left = 0;

        int n = s.size();
        if (n <= 1) return n;

        for (int i=0; i<n; ++i) {

            while (lookup.find(s[i]) != lookup.end()) {
                lookup.erase(s[left++]);
            }

            lookup.insert(s[i]);
            ret = max(ret, i-left+1);
        }

        return ret;
    }
};

/**
 * --------------------------------------------------------------------------
 * 📝 学习笔记 & 错误记录 (Notes & Mistakes)
 * --------------------------------------------------------------------------
 * 
 * [在此处记录你的解题思路、遇到的错误、以及修正过程]
 * 
 * 1. 核心思路 (滑动窗口)：
 *    - 维护一个窗口 [left, i]，保证窗口内的字符不重复。
 *    - 使用 unordered_set (lookup) 来记录窗口内已存在的字符。
 *    - 遍历字符串，对于当前字符 s[i]：
 *      - 如果 s[i] 已经在 set 中（出现重复），则不断右移左边界 left，并从 set 中移除 s[left]，直到 s[i] 不再重复。
 *      - 将 s[i] 加入 set。
 *      - 更新最大长度 ret = max(ret, i - left + 1)。
 * 
 * 2. 错误记录：
 *    - 
 *    - 
 * 
 * 3. 心得体会：
 *    - 滑动窗口是解决“子串”问题的常用套路。
 *    - 本题也可以使用 vector<int>(128) 来替代 unordered_set 作为哈希表（因为 ASCII 字符有限），这样在查找和移除时可能会更快一点，且无需频繁的内存分配。
 * 
 * --------------------------------------------------------------------------
 */

// 辅助函数：打印测试结果
void printTest(string s, int expected, Solution& solution) {
    cout << "Input: s = \"" << s << "\"" << endl;
    
    int result = solution.lengthOfLongestSubstring(s);
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << (result == expected ? "✅ Passed" : "❌ Failed") << endl;
    cout << "--------------------------------" << endl;
}

// 测试代码
int main() {
    Solution solution;

    // 示例 1
    printTest("abcabcbb", 3, solution);

    // 示例 2
    printTest("bbbbb", 1, solution);

    // 示例 3
    printTest("pwwkew", 3, solution);

    // 额外测试：空字符串
    printTest("", 0, solution);

    // 额外测试：空格
    printTest(" ", 1, solution);

    // 额外测试：au
    printTest("au", 2, solution);

    return 0;
}