#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int sz;
    unordered_map<int, int> indexValue;
    Solution(int n, vector<int>& blacklist) {
        // 加了 int 后，会有部分实例不通过
        /*
        如果你写成了int sz = n - blacklist.size();，你实际上创建了一个新的、
        名为sz的局部变量，它只会遮蔽（shadow）类的成员变量sz。
        */
        sz = n - blacklist.size();
        for(int b: blacklist){
            indexValue[b] = 6;
        }
        
        int last = n-1;
        for(int b: blacklist){
            if(b>=sz){
                continue;
            }
            while(indexValue.count(last)){
                last--;
            }
            indexValue[b] = last;           
            last--;
        }
    }
    
    int pick() {
        int index = rand() % sz;   // sz 相当关键，意味着 >= sz 的映射为 666 的值不用被使用
        if(indexValue.count(index)){
            return indexValue[index];
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */