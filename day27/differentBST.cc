class Solution {
public:
std::vector<std::vector<int>> mmm;

int numTrees(int n) {
        mmm.resize(n + 1, std::vector<int>(n + 1, 0));
        return count(1, n);
    }

    int count(int lower, int upper){
        if(lower>upper) return 1;
        if(mmm[lower][upper] != NULL){
            return mmm[lower][upper];
        }
        int res = 0;
        for(int mid=lower; mid<=upper; mid++){
            int left = count(lower, mid-1);
            int right = count(mid+1, upper);
            res += left*right;
        }
        mmm[lower][upper] = res;

        return res;
    }
};