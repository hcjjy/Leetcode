/*
https://leetcode.com/problems/course-schedule/
用深度优先搜索DFS判断有向图是否有环,注意circle[]和visited[]的区别。
circle[]在一个节点的所以路径走完后，恢复其访问标志。
*/
class Solution {
public:
	bool flag;
	int n;
	void DFS(int v,vector<vector<bool> >& graph,bool circle[],bool visited[])
	{
		if(flag)
		{
			return;
		}
		if(!circle[v])
		{
			circle[v] = true;
		}
		else
		{
			flag = true;
			return;
		}
		if(!visited[v])
		{
			visited[v] = true;
			for(int d = 0; d < n; ++d)
			{
				if(graph[v][d] && !flag)
				{
				     /*static int i = 0;
			         if(i < 100)
			    	 {
				        cout<<v<< " "<<d<<endl;
			     	 }*/
					DFS(d, graph, circle, visited);
				}
			}
		}
		circle[v] = false;
	}
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		n = numCourses;
		vector<vector<bool> > graph(numCourses, vector<bool>(numCourses));
		
		for(int i = 0;i < prerequisites.size(); ++i)
		{
			int next = prerequisites[i].first;
			int pre = prerequisites[i].second;
			graph[pre][next] = true;
		}
		
		bool circle[n],visited[n];
		flag = false;
		memset(visited,0,sizeof(bool) * n);
		memset(circle,0,sizeof(bool) * n);
		for(int i = 0; i < n; ++i)
		{
			if(flag)
			{
				return false;
			}
			if(!visited[i])
			{
				DFS(i,graph,circle,visited);
			}
		}
		if(flag)
		{
			return false;
		}
		return true;
    }
};

/*链表存储节省空间和时间*/
class Solution {
public:
	bool flag;
	int n;
	struct Node
	{
		int index;
		Node* next;
	};
	//void DFS(int v,vector<vector<bool> >& graph,bool circle[],bool visited[])
	void DFS(int v,Node* nodeList[],bool circle[], bool visited[])
	{
		if(flag)
		{
			return;
		}
		if(!circle[v])
		{
			circle[v] = true;
		}
		else
		{
			flag = true;
			return;
		}
		if(!visited[v])
		{
			visited[v] = true;
			/*for(int d = 0; d < n; ++d)
			{
				if(graph[v][d] && !flag)
				{
					DFS(d, graph, circle, visited);
				}
			}*/
			for(Node* p = nodeList[v];p != NULL; p = p->next)
			{
				if(!flag)
				{
					DFS(p->index,nodeList,circle,visited);
				}
			}
		}
		circle[v] = false;
	}
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		n = numCourses;
		//vector<vector<bool> > graph(numCourses, vector<bool>(numCourses));
		Node* nodeList[numCourses];
		Node* lastNodeList[numCourses];
		for(int i = 0; i < n; ++i)
		{
			nodeList[i] = NULL;
		}
		for(int i = 0; i < prerequisites.size(); ++i)
		{
			int next = prerequisites[i].first;
			int pre = prerequisites[i].second;
			//graph[pre][next] = true;
			if(nodeList[pre] == NULL)
			{
				lastNodeList[pre] = new Node();
				lastNodeList[pre]->index = next;
				lastNodeList[pre]->next = NULL;
				nodeList[pre] = lastNodeList[pre];
			}
			else
			{
				lastNodeList[pre]->next = new Node();
				lastNodeList[pre]->next->index = next;
				lastNodeList[pre] = lastNodeList[pre]->next;
				lastNodeList[pre]->next = NULL;
			}	
		}
		
		bool circle[n],visited[n];
		flag = false;
		memset(visited,0,sizeof(bool) * n);
		memset(circle,0,sizeof(bool) * n);
		for(int i = 0; i < n; ++i)
		{
			if(flag)
			{
				return false;
			}
			if(!visited[i])
			{
				//DFS(i,graph,circle,visited);
				DFS(i,nodeList,circle,visited);
			}
		}
		if(flag)
		{
			return false;
		}
		return true;
    }
};

/*用拓扑算法判断有向图是否有环，用一个数组 incomingNum[n]记录每个节点的入点，
找到一个入点为0点节点，将该点相关连的点的入点更新，直到每个点的入点为0或者有入点不为0的点存在*/
class Solution {
public:
	int n;
	struct Node
	{
		int index;
		Node* next;
	};
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		n = numCourses;
		Node* nodeList[numCourses];
		Node* lastNodeList[numCourses];
		int incomingNum[numCourses];
		bool visited[numCourses];
		for(int i = 0; i < n; ++i)
		{
			nodeList[i] = NULL;
			incomingNum[i] = 0;
			visited[i] = false;
		}
		for(int i = 0; i < prerequisites.size(); ++i)
		{
			int next = prerequisites[i].first;
			int pre = prerequisites[i].second;
			
			if(nodeList[pre] == NULL)
			{
				lastNodeList[pre] = new Node();
				lastNodeList[pre]->index = next;
				lastNodeList[pre]->next = NULL;
				nodeList[pre] = lastNodeList[pre];
			}
			else
			{
				lastNodeList[pre]->next = new Node();
				lastNodeList[pre]->next->index = next;
				lastNodeList[pre] = lastNodeList[pre]->next;
				lastNodeList[pre]->next = NULL;
			}
			++incomingNum[next];
		}
		bool flag = false;
		int cnt = 0;
		while(cnt < n)
		{
		    int i = 0;
    		for( ; i < n; ++i)
    		{
    		    if(!visited[i] && !incomingNum[i])
    		    {
    		        visited[i] = true;
    		        ++cnt;
    		        for(Node* p = nodeList[i]; p != NULL; p = p->next)
    		        {
    		            --incomingNum[p->index];
    	        	}
    	        	break;//一次只找一个
    		    }
    		}
    		//找不到没有访问过且入点为0的点
    		if(i == n)
    		{
    		    return false;
    		}

		}
		return true;
    }
};
/*
活捉大神的算法，开心的是和大神的算法如此相似。
As suggested by the hints, this problem is equivalent to detecting a cycle in the graph represented by prerequisites. Both BFS and DFS can be used to solve it using the idea of topological sort. If you find yourself unfamiliar with these concepts, you may refer to their wikipedia pages. Specifically, you may only need to refer to the link in the third hint to solve this problem.

Since pair<int, int> is inconvenient for the implementation of graph algorithms, we first transform it to a graph. If course u is a prerequisite of course v, we will add a directed edge from node u to node v.
*/

//BFS

//BFS uses the indegrees of each node. We will first try to find a node with 0 indegree. If we fail to do so, there must be a cycle in the graph and we return false. Otherwise we have found one. We set its indegree to be -1 to prevent from visiting it again and reduce the indegrees of all its neighbors by 1. This process will be repeated for n (number of nodes) times. If we have not returned false, we will return true.

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++)
                if (!degrees[j]) break;
            if (j == numCourses) return false;
            degrees[j] = -1;
            for (int neigh : graph[j])
                degrees[neigh]--;
        }
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    vector<int> compute_indegree(vector<unordered_set<int>>& graph) {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }
}; 
//DFS

//For DFS, it will first visit a node, then one neighbor of it, then one neighbor of this neighbor... and so on. If it meets a node which was visited in the current process of DFS visit, a cycle is detected and we will return false. Otherwise it will start from another unvisited node and repeat this process till all the nodes have been visited. Note that you should make two records: one is to record all the visited nodes and the other is to record the visited nodes in the current DFS visit.

//The code is as follows. We use a vector<bool> visited to record all the visited nodes and another vector<bool> onpath to record the visited nodes of the current DFS visit. Once the current visit is finished, we reset the onpath value of the starting node to false.

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
                return false;
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    } 
    bool dfs_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
        if (visited[node]) return false;
        onpath[node] = visited[node] = true; 
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
                return true;
        return onpath[node] = false;
    }
};
