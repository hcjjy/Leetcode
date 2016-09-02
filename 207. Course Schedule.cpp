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
