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
        if(!node)return NULL;
        map<UndirectedGraphNode *,UndirectedGraphNode *> mp;
    queue<UndirectedGraphNode *> q;
    set<int> visited;
    q.push(node);
    visited.insert(node->label);
    while(!q.empty())
    {
        UndirectedGraphNode * front = q.front();
        q.pop();
        mp[front]=new  UndirectedGraphNode(front->label);
        for(auto it = front->neighbors.begin();it!=front->neighbors.end();it++)
        {
         if(!visited.count((*it)->label)) 
         {
             q.push(*it);
             visited.insert((*it)->label);
         }
        }
        
    }
    q.push(node);
    visited.clear();
    visited.insert(node->label);
         while(!q.empty())
    {
         UndirectedGraphNode * front = q.front();
        q.pop();
         UndirectedGraphNode * nn = mp[front];
          for(auto it = front->neighbors.begin();it!=front->neighbors.end();it++)
        {
            nn->neighbors.push_back(mp[*it]);
         if(!visited.count((*it)->label)) 
         {
             q.push(*it);
             visited.insert((*it)->label);
         }
        }
    }
    return mp[node];
        
    }
};
