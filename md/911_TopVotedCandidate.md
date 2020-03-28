### 911\. [Online Election](https://leetcode.com/problems/online-election/)

In an election, the ```i```-th vote was cast for ```persons[i]``` at time ```times[i]```.

Now, we would like to implement the following query function: ```TopVotedCandidate.q(int t)``` will return the number of the person that was leading the election at time ```t```.  

Votes cast at time t will count towards our query.  In the case of a tie, the most recent vote (among tied candidates) wins.

Example 1:
```
Input: ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
Output: [null,0,1,1,0,0,1]
Explanation: 
At time 3, the votes are [0], and 0 is leading.
At time 12, the votes are [0,1,1], and 1 is leading.
At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
This continues for 3 more queries at time 15, 24, and 8.
```

Note:

1. 1 <= persons.length = times.length <= 5000
2. 0 <= persons[i] <= persons.length
3. times is a strictly increasing array with all elements in [0, 10^9].
4. TopVotedCandidate.q is called at most 10000 times per test case.
5. TopVotedCandidate.q(int t) is always called with t >= times[0].

#### Solution 1

C++

```
class TopVotedCandidate {
    vector<int> leads;
    vector<int> times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size(), lead = 0;
        this->times = times; // time at i-th time
        leads = vector<int>(n, 0); // person who leads at i-th time
        vector<int> count(n, 0);
        for (int i = 0; i < n; i++) {
            auto p = persons[i];
            if (++count[p] >= count[lead])
                lead = p;
            leads[i] = lead;
        }
    }
    
    int q(int t) {
        auto i = upper_bound(times.begin(), times.end(), t);
        int d = (i - 1) - times.begin();
        return leads[d];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
```
