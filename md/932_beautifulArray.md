### 932\. [Beautiful Array](https://leetcode.com/problems/beautiful-array/)

For some fixed N, an array A is beautiful if it is a permutation of the integers 1, 2, ..., N, such that:

For every i < j, there is no k with i < k < j such that A[k] * 2 = A[i] + A[j].

Given N, return any beautiful array A.  (It is guaranteed that one exists.)
 
Example 1:
```
Input: 4
Output: [2,1,4,3]
```

Example 2:
```
Input: 5
Output: [3,1,2,5,4]
```

Note:

1 <= N <= 1000

#### Solution 1

[https://leetcode.com/problems/beautiful-array/discuss/187669/Share-my-O(NlogN)-C%2B%2B-solution-with-proof-and-explanation](https://leetcode.com/problems/beautiful-array/discuss/187669/Share-my-O(NlogN\-C%2B%2B-solution-with-proof-and-explanation)

C++

```
class Solution {
public:
    int partition(vector<int> &v, int start, int end, int mask)
    {
        int j = start;
        for(int i = start; i <= end; i++)
        {
            if((v[i] & mask) != 0)
            {
                swap(v[i], v[j]);
                j++;
            }
        }
        return j;
    }
    
    void sort(vector<int> & v, int start, int end, int mask)
    {
        if(start >= end) return;
        int mid = partition(v, start, end, mask);
        sort(v, start, mid - 1, mask << 1);
        sort(v, mid, end, mask << 1);
    }
    
    vector<int> beautifulArray(int N) {
        vector<int> ans;
        for(int i = 0; i < N; i++) ans.push_back(i + 1);
        sort(ans, 0, N - 1, 1);
        return ans;
    }
};
```

#### Solution 2

[https://leetcode.com/problems/beautiful-array/discuss/371380/C%2B%2B-separate-odd-index-with-even-index](https://leetcode.com/problems/beautiful-array/discuss/371380/C%2B%2B-separate-odd-index-with-even-index)

Shift even-indexed elements to the first half and odd-indexed elements to the second half.

C++

```
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res(N, 0);
        for (int i = 0; i < N; i++) res[i] = i + 1;
        dfs(res, 0, N-1);
        return res;
    }
    void dfs(vector<int>& res, int left, int right) {
        if (left >= right) return;
        vector<int> even, odd;      
        for (int i = 0; i <= right - left; i += 2) {
            even.push_back(res[i+left]);
        }
        
        for (int i = 1; i <= right - left; i += 2) {
            odd.push_back(res[i+left]);
        }
        copy(even.begin(), even.end(), res.begin() + left);
        copy(odd.begin(), odd.end(), res.begin() + left + even.size());
        int mid = left + (right - left) / 2;
        dfs(res, left, mid);
        dfs(res, mid + 1, right);
    }
};
```
