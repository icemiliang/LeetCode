#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode *t1, TreeNode *t2) {
	if (!t1 and !t2) return true;
	if (!t1 and t2) return false;
	if (t1 and !t2) return false;
	if (t1->val != t2->val) return false;
	return isSameTree(t1->left, t2->left) and isSameTree(t1->right, t2->right);
}

int main() {

	TreeNode* t1 = new TreeNode(1);
	t1->left = new TreeNode(2);
	t1->right = new TreeNode(1);

	TreeNode* t2 = new TreeNode(1);
	t2->left = new TreeNode(1);
	t2->right = new TreeNode(2);

	string trueOrFalse12 = isSameTree(t1, t2) ? "True" : "False";


	TreeNode* t3 = new TreeNode(1);
	t3->left = new TreeNode(2);
	t3->right = new TreeNode(3);

	TreeNode* t4 = new TreeNode(1);
	t4->left = new TreeNode(2);
	t4->right = new TreeNode(3);
	
	string trueOrFalse34 = isSameTree(t3, t4) ? "True" : "False";

	cout << "Tree 1 == Tree 2 (False)? " + trueOrFalse12 << endl;
	cout << "Tree 3 == Tree 4 (True)? " + trueOrFalse34 << endl;

	return 0;
}
