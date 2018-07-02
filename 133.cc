/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        // 存储已创建的节点，节点有两种状态: 已完成克隆和半克隆(neighbors尚未克隆)
        unordered_map<int, UndirectedGraphNode*> map;
        queue<UndirectedGraphNode*> q; // 半克隆节点对应的的original节点
        q.push(node);
        UndirectedGraphNode *result = new UndirectedGraphNode(node->label);
        map[node->label] = result;
        while (!q.empty()) {
            for (int i = 0, size = q.size(); i < size; ++i) {
                UndirectedGraphNode *originalNode = q.front();
                q.pop();
                unordered_map<int, UndirectedGraphNode*>::iterator iter = map.find(originalNode->label);
                UndirectedGraphNode *cloneNode = NULL;
                if (iter == map.end()) {
                    cloneNode = new UndirectedGraphNode(originalNode->label);
                    map[cloneNode->label] = cloneNode;
                } else {
                    cloneNode = iter->second;
                }
                for (auto neighbor : (originalNode->neighbors)) {
                    int neighborLabel = neighbor->label;
                    unordered_map<int, UndirectedGraphNode*>::iterator iter = map.find(neighborLabel);
                    UndirectedGraphNode *cloneNeighbor = NULL;
                    if (iter == map.end()) {
                        cloneNeighbor = new UndirectedGraphNode(neighborLabel);
                        map[neighborLabel] = cloneNeighbor;
                        // 防止出现重复克隆。一个节点有多个入度会导致重复克隆，环也会导致这种情况。
                        q.push(neighbor);
                    } else {
                        // 一个label已出现在map中，表示对应节点已创建。不能重复创建。
                        cloneNeighbor = iter->second;
                    }
                    cloneNode->neighbors.push_back(cloneNeighbor);
                }
            }
        }
        return result;
    }
};
