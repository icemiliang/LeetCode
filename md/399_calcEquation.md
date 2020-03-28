### 399\. [Evaluate Division](https://leetcode.com/problems/evaluate-division/)

Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
```
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
```
Note:

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.


#### Solution 1

Union find. 

Eeach division is an directed edge. Its direction is determined by
whether one of the nodes have been visited. Use a hashmap to store value for
each string which is a node. When both nodes have not been visited, define
a reference e.g. b = 1 and thus a = 2. If two separated components will be
connected by a division/edge, change the reference of one component which
means change value of all nodes in that component according to the new reference.

C++

```
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i ++) {
            string s1 = equations[i][0], s2 = equations[i][1];
            if (!m.count(s1) and !m.count(s2)) {
                // no s1 no s2
                m[s1] = new Node(values[i]);
                m[s2] = new Node(1.0);
                m[s2]->parent = m[s1];
            } 
            else if (!m.count(s1)) {
                // s2 no s1
                m[s1] = new Node(m[s2]->val * values[i]);
                m[s1]->parent = m[s2];
            } 
            else if (!m.count(s2)) {
                // s1 no s2
                m[s2] = new Node(m[s1]->val / values[i]);
                m[s2]->parent = m[s1];
            } 
            else {
                unionNodes(m[s1], m[s2], values[i]);
            }
        }
        
        vector<double> res;
        for (auto& q : queries) {
            if (!m.count(q[0]) or !m.count(q[1]) or findParent(m[q[0]]) != findParent(m[q[1]])) {
                res.push_back(-1);
            }
            else {
                res.push_back(m[q[0]]->val / m[q[1]]->val);
            }
        }
        return res;
    }
    
private:
    struct Node {
        Node* parent;
        double val = 0.0;
        Node(double v) { val = v; parent = this; }
    };

    unordered_map<string, Node*> m;
    
    void unionNodes(Node* node1, Node* node2, double num) {
        Node* parent1 = findParent(node1), *parent2 = findParent(node2);
        if (parent1 == parent2) return;
        double ratio = node2->val * num / node1->val;
        for (auto& it : m) {
            if (findParent(it.second) == parent1) {
                it.second->val *= ratio;
            }
        }
        parent1->parent = parent2;
    }
    
    Node* findParent(Node* node) {
        if (node->parent == node) return node;
        node->parent = findParent(node->parent);
        return node -> parent;
    }
};
```
