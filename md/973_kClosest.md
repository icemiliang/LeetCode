### 973\. [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

Example 1:
```
Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
```

Example 2:
```
Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 ```

Note:

1. 1 <= K <= points.length <= 10000
2. -10000 < points[i][0] < 10000
3. -10000 < points[i][1] < 10000


#### Solution 1

The most straightforward solution is to compute the distances of all the points,
and then select the closest k points. We can use a priority queue to store all
the distances and then pop the first k elements. The default priority queue
stores the largest element at the top, so we need to modify the compare function.
We can also keep the original compare function of the priority queue. The trick is
pop the top element if the size exceeds K so that the queue stores the K closest
elements seen so far. Because the problems says the returned elements can be in
any order. We can pop the queue in this descening order.

C++

```
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
		for (int i = 0; i < points.size(); i++) {
			pq.push({euclidean(points[i]), i});
		}
		vector<vector<int>> res;
		for (int i = 0; i < K; i++) {
			res.push_back(points[pq.top().second]);
			pq.pop();
		}
		return res;
	}
	double euclidean(vector<int>& p) {
		return p[0] * p[0] + p[1] * p[1];
	}
};
```

```
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		priority_queue<pair<long, int>> pq;
		for (int i = 0; i < points.size(); i++) {
			pq.push({euclidean(points[i]), i});
			if (pq.size() > K) pq.pop();
		}
		vector<vector<int>> res;
		for (int i = 0; i < K; i++) {
			res.push_back(points[pq.top().second]);
            pq.pop();
		}
		return res;
	}
	double euclidean(vector<int>& p) {
		return p[0] * p[0] + p[1] * p[1];
	}
};
```

#### Solution 2

The general idea of solving this problem is through sorting. However, because 
the returned elements can be in any order, we only need to put the k closest
elements in the front of the array. We can borrow the quicksort idea to implement
this idea. There is a name for this algorithm, quickselect. The idea is to 
randomly select a pivot, partition the array so that all the elements that are
smaller than this pivot comes before rest of the elements. If the pivot is after 
the kth position, then the k closest elements are all in front of it. Redo the 
process for the first section; otherwise find the kth positioin in the second
section. keep track of the index of the most left element in the current secion,
so that we can trace which element is at the kth position. Then, all the elemnets
including itself are the k closest points.

C++

```
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        quickselect(points, 0, points.size() - 1, K);
        return vector<vector<int>> (points.begin(), points.begin() + K);
    }
    
    void quickselect(vector<vector<int>>& points, int left, int right, int K) {
        if (left >= right) return;
        int mid = partition(points, left, right);
        if (mid < K) {
            quickselect(points, mid + 1, right, K);
        }
        else if (mid > K) {
            quickselect(points, left, mid - 1, K);
        }
    }
    
    int partition(vector<vector<int>> &points, int left, int right) {
        long pivot = dist(points[right]);
        int pivot_idx = right;
        while (left < right) {
            if (dist(points[left]) < pivot) left++;
            else if (dist(points[right]) >= pivot) right--;
            else swap(points[left], points[right]);
        }
        swap(points[left], points[pivot_idx]);
        return left;
    }
    
    long dist(vector<int>& p) {
        return p[0] * p[0] + p[1] * p[1];
    }
};
```
