#include <iostream>
#include <vector>


using namespace std;


class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> valueIndex;
    RandomizedSet() {
        // srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if(valueIndex.count(val)){
            return false;
        }
        // emplace_back 和 push_back 的区别： 当使用 push_back 时会报错
        nums.push_back(val);
        valueIndex[val] = nums.size();
        return true;
    }
    
    bool remove(int val) {
        if(valueIndex.count(val)){
            nums[valueIndex[val]] = nums[nums.size()-1];
            valueIndex[nums[nums.size()-1]] = valueIndex[val];
            valueIndex.erase(val);
            nums.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        // 随机获取 nums 中的一个元素
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */