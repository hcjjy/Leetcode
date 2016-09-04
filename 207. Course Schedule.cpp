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
