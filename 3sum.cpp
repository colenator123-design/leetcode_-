#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    // 首先對數組進行排序
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int i = 0; i < nums.size() - 2; i++) {
        // 跳過重複的元素
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;

        // 使用雙指針來查找三元組
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});

                // 跳過重複的 left 元素
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                // 跳過重複的 right 元素
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }

                // 移動指針，繼續尋找其他組合
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);

    // 輸出結果
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
