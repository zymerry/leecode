/**
 * 1. 两数之和 (Two Sum)
 * https://leetcode.cn/problems/two-sum/
 *
 * 题目描述:
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
 * 你可以按任意顺序返回答案。
 *
 * 示例 1：
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 *
 * 示例 2：
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 *
 * 示例 3：
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 *
 * 提示：
 * 2 <= nums.length <= 104
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 * 只会存在一个有效答案
 *
 * 进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ret(2);
        unordered_multimap<int, int> storage;
        for (int i=0; i<nums.size(); i++) {
            storage.emplace(nums[i], i);
        }

        for (auto const & pair : storage) {

            int sub = target - pair.first;
            unordered_multimap<int, int>::iterator it = storage.find(sub);
            if (it != storage.end() && it->second != pair.second) {
                ret[0] = pair.second;
                ret[1] = it->second;
                return ret;
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
 * 1. 错误记录：
 *    - unordered_multimap 没有 operator[]
 *      operator[] 只存在于：unordered_map 和 map
 *
 *    - 容器特性对比：
 *      | 容器                     | key 是否唯一 | 底层      | 查找       |
 *      | ---------------------- | -------- | ------- | -------- |
 *      | map                    | 唯一       | 红黑树     | O(logN)  |
 *      | multimap               | 不唯一      | 红黑树     | O(logN)  |
 *      | unordered_map          | 唯一       | 哈希表     | O(1)     |
 *      | **unordered_multimap** | **不唯一**  | **哈希表** | **O(1)** |
 *
 * 2. 知识点总结 (unordered_multimap 使用)：
 *    - 允许键重复：std::unordered_multimap 允许不同的元素具有相同的键。在处理数组中可能有重复元素的情况（例如示例 3 中的 [3, 3]）时非常有用。
 *    - 插入元素：使用 .emplace(key, value) 或 .insert({key, value})。
 *    - 查找元素：.find(key) 返回一个迭代器，指向找到的第一个匹配元素。如果未找到，返回 .end()。
 *    - 迭代器：it->first 是键 (key)，it->second 是值 (value)。
 *    - 注意：在本题中，我们使用 find() 查找差值，并需要通过 `it->second != pair.second` 来确保我们没有重复使用同一个元素（即不能自己加自己）。
 *
 * 3. 心得体会：
 *    - 本解法使用了 unordered_multimap 来存储所有元素的下标。虽然题目保证每种输入只会对应一个答案，使用 unordered_map 配合“边遍历边查找”通常更简洁（只需一次遍历），但使用 unordered_multimap 并先完全构建哈希表也是一种直观的思路，特别是当需要处理更复杂的重复元素查找逻辑时。
 * 
 * --------------------------------------------------------------------------
 */

// 辅助函数：打印 vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// 测试代码
int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    cout << "Input: nums = [2, 7, 11, 15], target = 9" << endl;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Output: ";
    printVector(result1);

    // 示例 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    cout << "Input: nums = [3, 2, 4], target = 6" << endl;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Output: ";
    printVector(result2);

    // 示例 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    cout << "Input: nums = [3, 3], target = 6" << endl;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Output: ";
    printVector(result3);

    return 0;
}