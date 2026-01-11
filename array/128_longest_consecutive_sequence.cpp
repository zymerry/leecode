/**
 * 128. 最长连续序列 (Longest Consecutive Sequence)
 * https://leetcode.cn/problems/longest-consecutive-sequence/
 *
 * 题目描述:
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 示例 1：
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 示例 3：
 * 输入：nums = [1,0,1,2]
 * 输出：3
 * 
 * 提示：
 * 0 <= nums.length <= 105
 * -109 <= nums[i] <= 109
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() <= 1) return nums.size();

        sort(nums.begin(), nums.end());
        vector<int>::iterator last = unique(nums.begin(), nums.end());

        int ret = 1, vmax = 1;
        for (auto it=nums.begin(); it+1 != last; ++it) {

            if (*it+1 == *(it+1)) {
                ++vmax;
                ret = max(ret, vmax);
            } else {
                vmax = 1;
            }
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
 * 1. 复杂度分析：
 *    - 当前解法使用了 std::sort，时间复杂度为 O(N log N)。
 *    - 题目要求 O(N) 时间复杂度，通常需要使用哈希表 (unordered_set) 来实现。
 * 
 * 2. 错误记录：
 *    - 
 *    - 
 * 
 * 3. 心得体会：
 *    - 虽然排序法不满足严格的 O(N) 要求，但思路清晰，易于实现，且空间复杂度较低（仅为排序栈空间）。
 *    - 
 * 
 * --------------------------------------------------------------------------
 */

// 辅助函数：打印测试结果
void printTest(vector<int> nums, int expected, Solution& solution) {
    cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    int result = solution.longestConsecutive(nums);
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << (result == expected ? "✅ Passed" : "❌ Failed") << endl;
    cout << "--------------------------------" << endl;
}

// 测试代码
int main() {
    Solution solution;

    // 示例 1
    printTest({100, 4, 200, 1, 3, 2}, 4, solution);

    // 示例 2
    printTest({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9, solution);

    // 示例 3
    printTest({1, 0, 1, 2}, 3, solution);

    // 额外测试：空数组
    printTest({}, 0, solution);

    // 额外测试：单元素
    printTest({10}, 1, solution);

    return 0;
}