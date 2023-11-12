[5,2,6,1]
[5,2] [6,1]

[2,5] [1,6]

[1,2, ]

[5, 2, 6, 1, 4]
0+(4-0)/2 =2
[5, 2, 6]     [1, 4]
[5, 2]   [6]       [1]    [4] 

[5]  [2]       +1
merge
`p --loop-- lo-hi [0,1]`
`if(temps[i]>temps[j]) nums[p]=temps[j++]`   
`if(j==hi+1) nums[p]= temps[i++]`     `count[indNumP] += j-mid-1`
[2,5] [6]     [1] [4]  +1
merge
`if(temps[i]<temps[j]) nums[p]=temps[i++]`
`if(i==mid+1) nums[p]=temps[j++]`
[2,5,6] [1,4]        
merge
`if(temps[i]>temps[j]) nums[p] = temps[j++]`   
`else if(temps[j]>temps[i]) nums[p] = temps[i++]`     `count[indNumP] += j -mid-1`
`else if(j==hi+1) nums[p] = temps[j++]`
[1,2,4,5,6]

> 关键在于 `j-(mid+1)`，记录的是 `nums[p]=temps[i++]` 在右边数组中有多少个比其小的元素。 而对于每次 `temps[i]>temps[j]` 从而 `j++`，直到 `temps[i]<temps[j]` 或 `j==hi+1` 时，才对 `temps[i]` 统计完成。   `count[nums[p].id] += j-(mid+1)` 


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