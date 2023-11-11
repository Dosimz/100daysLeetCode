[5,2,6,1]
[5,2] [6,1]

[2,5] [1,6]

[1,2, ]

```cpp
    pair
    count

    void merge(vector<int>& nums, int lo, int mid, int hi) {
        for (int it = lo; it <= hi; it++) {
            temps[it] = nums[it];
        }
        int p = lo; int j = mid + 1;
        for (int i = lo; i <= hi; i++) {
            if (p == (mid + 1)) {
                nums[i] = temps[j++];
            } else if (j == hi + 1) {
                nums[i] = temps[p++];
                // 
                count[arr[p].id] += j - mid - 1;
            } else if (temps[p] < temps[j]) {
                nums[i] = temps[p++];
            } else {
                nums[i] = temps[j++];
                //
                count[arr[p].id] += j - mid - 1;
            }
        }
    }
```