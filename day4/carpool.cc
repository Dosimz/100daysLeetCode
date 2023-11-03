#include <iostream>
#include <vector>

using  namespace std;

class Solution{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        int d[1001]{};   // 如果使用 int d[1001]; 则未初始化，其值是未定义的，可能是任意值，可能是0，可能是-1，可能是1000，可能是1000000
        for(auto trip: trips){
            int nump = trip[0];
            int from = trip[1];
            int to = trip[2];
            d[(from)] += nump;
            d[(to)] -= nump;
        } //0 1 2 3 4 5 6 7
        int sum = 0;
        for(auto i: d){
            sum += i;
            if(sum>capacity)
                return false;
        }
        return true;

    }

};


int main(){
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    int capacity = 4;
    Solution s;
    bool answer = s.carPooling(trips, capacity);
    cout<<answer<<endl;
    return 0;
}