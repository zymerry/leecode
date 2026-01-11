/**
 * 11. 盛最多水的容器 (Container With Most Water)
 * https://leetcode.cn/problems/container-with-most-water/
 *
 * 题目描述:
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 返回容器可以储存的最大水量。
 * 说明：你不能倾斜容器。
 * 
 * 示例 1：
 * ![question_11.jpg](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49
 * 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 示例 2：
 * 输入：height = [1,1]
 * 输出：1
 * 
 * 提示：
 * n == height.length
 * 2 <= n <= 105
 * 0 <= height[i] <= 104
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l = 0;
        int r = height.size() - 1;
        int ans = 0; // 修复：初始化为 0

        while (l < r) {

            int area = min(height[r], height[l]) * (r-l);
            ans = max(ans, area);

            if (height[l] <= height[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return ans;
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
 *    - 在原始代码中，`int ans;` 没有初始化。在 C++ 中，局部变量未初始化时其值是未定义的（可能是内存中的随机值）。
 *      修正：`int ans = 0;`
 * 
 * 2. 核心思路 (双指针法)：
 *    - 初始状态：l指向左边界，r指向右边界，此时宽度最大。
 *    - 移动策略：
 *      - 容器的容量由短板决定：min(height[l], height[r])。
 *      - 每次移动较短的那根柱子。原因：如果移动长板，宽度变小，而高度受限于短板（或者变得更短），面积只可能变小；
 *        只有移动短板，高度才有可能变大，从而可能获得更大的面积。
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
    
    int result = solution.maxArea(height);
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << (result == expected ? "✅ Passed" : "❌ Failed") << endl;
    cout << "--------------------------------" << endl;
}

// 测试代码
int main() {
    Solution solution;

    // 示例 1
    printTest({1, 8, 6, 2, 5, 4, 8, 3, 7}, 49, solution);

    // 示例 2
    printTest({1, 1}, 1, solution);

    // 额外测试
    printTest({4, 3, 2, 1, 4}, 16, solution);
    printTest({1, 2, 1}, 2, solution);

    return 0;
}