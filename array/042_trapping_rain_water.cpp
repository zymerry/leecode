/**
 * 42. 接雨水 (Trapping Rain Water)
 * https://leetcode.cn/problems/trapping-rain-water/
 *
 * 题目描述:
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 示例 1：
 * ![rainwatertrap.png](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png)
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 * 
 * 示例 2：
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 提示：
 * n == height.length
 * 1 <= n <= 2 * 104
 * 0 <= height[i] <= 105
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        int ret = 0;
        int n = height.size();
        if (n <= 0) return 0;

        vector<int> l_max(n);
        vector<int> r_max(n);

        l_max[0] = height[0];
        for (int i=1; i<n; ++i) {
            l_max[i] = max(l_max[i-1], height[i]);
        }

        r_max[n-1] = height[n-1];
        for (int i = n-2; i>=0; --i) {
            r_max[i] = max(r_max[i+1], height[i]);
        }

        for (int i=0; i<n; i++) {
            ret += min(l_max[i], r_max[i]) - height[i];
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
 *    - 原代码末尾有多余字符 `å`，已在整理时删除。
 * 
 * 2. 核心思路 (动态规划 / 前后缀分解)：
 *    - 对于下标 `i` 处的柱子，它能接的雨水量等于 `min(左边最高柱子, 右边最高柱子) - height[i]`。
 *    - 如果 `min(左边最高, 右边最高)` <= `height[i]`，则该位置无法接水（或者说接水量为 0）。
 *    - 算法步骤：
 *      1. 预处理 `l_max` 数组：`l_max[i]` 表示下标 `[0...i]` 范围内的最大高度。
 *      2. 预处理 `r_max` 数组：`r_max[i]` 表示下标 `[i...n-1]` 范围内的最大高度。
 *      3. 遍历每个位置 `i`，累加 `min(l_max[i], r_max[i]) - height[i]`。
 *    - 时间复杂度：O(N)，需要遍历三次数组。
 *    - 空间复杂度：O(N)，需要两个辅助数组。
 * 
 * 3. 优化思考：
 *    - 可以使用双指针法将空间复杂度优化到 O(1)，但当前的解法更加直观易懂。
 * 
 * --------------------------------------------------------------------------
 */

// 辅助函数：打印 vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) cout << ",";
    }
    cout << "]";
}

// 辅助函数：打印测试结果
void printTest(vector<int> height, int expected, Solution& solution) {
    cout << "Input: height = ";
    printVector(height);
    cout << endl;
    
    int result = solution.trap(height);
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << (result == expected ? "✅ Passed" : "❌ Failed") << endl;
    cout << "--------------------------------" << endl;
}

// 测试代码
int main() {
    Solution solution;

    // 示例 1
    printTest({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6, solution);

    // 示例 2
    printTest({4, 2, 0, 3, 2, 5}, 9, solution);

    // 额外测试：递增数组（无法接水）
    printTest({1, 2, 3, 4, 5}, 0, solution);

    // 额外测试：递减数组（无法接水）
    printTest({5, 4, 3, 2, 1}, 0, solution);

    return 0;
}