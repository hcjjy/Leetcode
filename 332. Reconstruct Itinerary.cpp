/*复杂的方法*/
//边界1：有些路不通
//边界2：用重复的边

class Solution {
public:
	void findSub(
		string key,
		unordered_map<string, vector<string>>& ticketsMap,
		unordered_map<string, unordered_map<string, int>>& visited,
		vector<string>& ret,int& l, int len) {
		if (l == len)
			return;
		ret.push_back(key);
		++l;
		for (int i = 0; i < ticketsMap[key].size(); ++i)
		{
			if (l == len)
				return;
			if (visited[key][ticketsMap[key][i]] > 0)
			{
				--visited[key][ticketsMap[key][i]];
				findSub(ticketsMap[key][i],ticketsMap, visited,ret,l,len);
				++visited[key][ticketsMap[key][i]];
			}
		}
		if (l < len)
		{
			ret.pop_back();
			--l;
		}
	}
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		if (!tickets.size())
			return vector<string>();
		unordered_map<string, vector<string>> ticketsMap;
		unordered_map<string, unordered_map<string, int>> visited;

		for (int i = 0; i < tickets.size(); ++i)
		{
			ticketsMap[tickets[i].first].push_back(tickets[i].second);
			++visited[tickets[i].first][tickets[i].second];
		}
		for (auto iter = ticketsMap.begin(); iter != ticketsMap.end(); ++iter)
		{
			vector<string>& valueVec = iter->second;
			sort(valueVec.begin(), valueVec.end());
		}
		vector<string>ret;
		string key = "JFK";
		int l = 0;
		findSub(key, ticketsMap, visited, ret, l, tickets.size()+1);
		return ret;
	}
};

/*
法二：
Explanation

First keep going forward until you get stuck. That's a good main path already.
Remaining tickets form cycles which are found on the way back and get merged into that main path.
By writing down the path backwards when retreating from recursion,
merging the cycles into the main path is easy - the end part of the path has already been written, 
the start part of the path hasn't been written yet, so just write down the cycle now and then keep backwards-writing the path.

Example:

enter image description here

From JFK we first visit JFK -> A -> C -> D -> A.
There we're stuck, so we write down A as the end of the route and retreat back to D. 
There we see the unused ticket to B and follow it: D -> B -> C -> JFK -> D. Then we're stuck again,
retreat and write down the airports while doing so: Write down D before the already written A, then JFK before the D, etc.
When we're back from our cycle at D, the written route is D -> B -> C -> JFK -> D -> A.
Then we retreat further along the original path, prepending C, A and finally JFK to the route, 
ending up with the route JFK -> A -> C -> D -> B -> C -> JFK -> D -> A.
*/
class Solution {
public:
	void findSub(string key) {
		while (ticketsSet[key].size() > 0)
		{
			string nextKey = *ticketsSet[key].begin();
			ticketsSet[key].erase(ticketsSet[key].begin());
			findSub(nextKey);
		}
		ret.push_back(key);
	}
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		for (int i = 0; i < tickets.size(); ++i)
			ticketsSet[tickets[i].first].insert(tickets[i].second);
		findSub("JFK");
		return vector<string>(ret.rbegin(), ret.rend());
	}
	vector<string> ret;
	unordered_map<string, multiset<string> >ticketsSet;
};
