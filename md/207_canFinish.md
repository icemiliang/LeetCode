### 207\. [Course Schedule](https://leetcode.com/problems/course-schedule/)

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
```
Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
```
Example 2:
```
Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
```
Note:

1. The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
2. You may assume that there are no duplicate edges in the input prerequisites.


#### Solution 1

BFS topological sort for detecting clcle.
The key idea is an indegree for each node recording how many 
incoming connection. Each time we see a node, indegree minus one.

C++

```
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in(numCourses, 0);
        for (auto& e : prerequisites) {
            graph[e[1]].push_back(e[0]);
            in[e[0]]++;
        }
        
        queue<int> todo;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) todo.push(i);
        }
        
        while (!todo.empty()) {
            int t = todo.front(); todo.pop();
            for (int i : graph[t]) {
                in[i]--;
                if (in[i] < 0) return false;
                if (in[i] == 0) todo.push(i);
            }
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (in[i] != 0) return false;
        }
        return true;
    }
};
```

Every course will be pushed into the queue once and only once. Thus,
we can use a counter to track how many times the queue has popped anything.
This can skip counter indegree for every course.

C++

```
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in(numCourses, 0);
        for (auto& e : prerequisites) {
            graph[e[1]].push_back(e[0]);
            ++in[e[0]];
        }
        
        queue<int> todo;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) todo.push(i);
        }
        
        int cnt = numCourses;
        while (!todo.empty()) {
            int t = todo.front(); todo.pop();
            if (--cnt < 0) return false;
            for (int i : graph[t]) {
                if (--in[i] < 0) return false;
                if (in[i] == 0) todo.push(i);
            }
        }
        
        return cnt == 0;
    }
};
```
