/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
	stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> iterSt;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
       iterSt.push(make_pair(nestedList.begin(), nestedList.end()));
    }

    int next() {
        return ((iterSt.top().first)++)->getInteger();
    }

    bool hasNext() {
	    while (!iterSt.empty()) {
		    if (iterSt.top().first == iterSt.top().second) {
			    iterSt.pop();
                if (!iterSt.empty()) {
			        ++(iterSt.top().first);
                }
		    } else {
			    if ((iterSt.top().first)->isInteger()) {
				    break;
			    } else {
				    vector<NestedInteger> &nestedList = (iterSt.top().first)->getList();
				    iterSt.push(make_pair(nestedList.begin(), nestedList.end()));
			    }
		    }
	    }
	    return !iterSt.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
