/**
 * 49. 字母异位词分组 (Group Anagrams)
 * https://leetcode.cn/problems/group-anagrams/
 *
 * 题目描述:
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 
 * 示例 1:
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 解释：
 * 在 strs 中没有字符串可以通过重新排列来形成 "bat"。
 * 字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
 * 字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
 * 
 * 示例 2:
 * 输入: strs = [""]
 * 输出: [[""]]
 * 
 * 示例 3:
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 * 
 * 提示：
 * 1 <= strs.length <= 104
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> smap;

        for (const auto str : strs) {

            string tmp = str;
            sort(tmp.begin(), tmp.end());
            unordered_map<string, vector<string>>::iterator it = smap.find(tmp);
            if (it != smap.end()) {
                it->second.emplace_back(str);
            } else {
                vector<string> vs;
                vs.emplace_back(str);
                smap[tmp] = vs;
            }
        }

        for (const auto &mp : smap) {
            ret.emplace_back(mp.second);
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
 * 1. 错误记录：
 *    - 
 *    - 
 * 
 * 2. 心得体会：
 *    - 
 *    - 
 * 
 * --------------------------------------------------------------------------
 */

// 辅助函数：打印 vector<vector<string>>
void printResult(const vector<vector<string>>& result) {
    cout << "[" << endl;
    for (const auto& group : result) {
        cout << "  [";
        for (int i = 0; i < group.size(); ++i) {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

// 测试代码
int main() {
    Solution solution;

    // 示例 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    cout << "Input: strs = [\"eat\", \"tea\", \"tan\", \"ate\", \"nat\", \"bat\"]" << endl;
    vector<vector<string>> result1 = solution.groupAnagrams(strs1);
    cout << "Output: ";
    printResult(result1);

    // 示例 2
    vector<string> strs2 = {""};
    cout << "\nInput: strs = [\"\"]" << endl;
    vector<vector<string>> result2 = solution.groupAnagrams(strs2);
    cout << "Output: ";
    printResult(result2);

    // 示例 3
    vector<string> strs3 = {"a"};
    cout << "\nInput: strs = [\"a\"]" << endl;
    vector<vector<string>> result3 = solution.groupAnagrams(strs3);
    cout << "Output: ";
    printResult(result3);

    return 0;
}