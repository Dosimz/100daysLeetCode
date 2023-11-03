#include <iostream>
#include <vector>

using namespace std;
/*
该题包含的知识点：
** 前缀和
** 差分
** 二分查找 这个二分算法不是基于容器长度的二分，而是基于值域范围的二分。
*/
class Solution {
public:
    long long maxPower(vector<int> &stations, int r, int k) {
        int n = stations.size();
        long sum[n + 1], power[n], diff[n];
        sum[0] = 0;
        for (int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + stations[i]; // 前缀和
        for (int i = 0; i < n; ++i)
            power[i] = sum[min(i + r + 1, n)] - sum[max(i - r, 0)]; // 电量

        auto check = [&](long min_power) -> bool {
            memset(diff, 0, sizeof(diff)); // 重置差分数组
            long sum_d = 0, need = 0;
            for (int i = 0; i < n; ++i) {
                sum_d += diff[i]; // 累加差分值
                long m = min_power - power[i] - sum_d;
                if (m > 0) { // 需要 m 个供电站
                    need += m;
                    if (need > k) return false; // 提前退出这样快一些
                    sum_d += m; // 差分更新
                    if (i + r * 2 + 1 < n) diff[i + r * 2 + 1] -= m; // 差分更新
                }
            }
            return true;
        };

        long left = *min_element(power, power + n), right = left + k + 1; // 开区间写法
        while (left + 1 < right) {
            long mid = left + (right - left) / 2;
            check(mid) ? left = mid : right = mid;
        }
        return left;
    }
};

int main() {
    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int r = 9;
    int k = 9;
    Solution s;
    long long answer = s.maxPower(stations, r, k);
    cout << answer << endl;
    return 0;
}

/*
check 函数的意义。
这段代码是算法的核心部分，用于判断是否存在一个长度为 `k` 的连续子数组，使得该子数组中所有元素的平均值大于等于 `min_power`。

具体来说，这段代码使用了差分数组的思想，通过维护一个差分数组 `diff` 来记录相邻两个元素之间的差值。在每次循环中，首先累加差分值，
然后计算出当前位置到右侧第 `r * 2 + 1` 个位置之间的元素的平均值是否大于等于 `min_power`，如果不是，则需要在这些位置中添加一
定数量的供电站，使得平均值大于等于 `min_power`。

具体来说，对于当前位置 `i`，如果当前位置到右侧第 `r * 2 + 1` 个位置之间的元素的平均值小于 `min_power`，则需要在这些位置中
添加一定数量的供电站，使得平均值大于等于 `min_power`。具体地，需要计算出需要添加的供电站的数量 `m`，然后将 `need` 累加上 `m`，
如果 `need` 大于 `k`，则说明需要添加的供电站的数量已经超过了 `k`，此时可以提前退出循环。然后，将差分数组 `diff` 中
从位置 `i + r * 2 + 1` 开始的 `m` 个元素减去 `m`，表示在这些位置中添加了 `m` 个供电站。

最后，如果所有的位置都被遍历完了，并且需要添加的供电站的数量不超过 `k`，则说明存在一个长度为 `k` 的
连续子数组，使得该子数组中所有元素的平均值大于等于 `min_power`，返回 `true`，否则返回 `false`。

需要注意的是，这段代码中使用了一个 lambda 表达式 `check`，用于判断是否存在一个长度为 `k` 的
连续子数组，使得该子数组中所有元素的平均值大于等于 `min_power`。在 lambda 表达式中，使用了
变量 `min_power`、`power`、`diff`、`n` 和 `k`，这些变量都是在外部定义的。
*/