class Solution {
public:
	void genereateTable(string& needle,vector<int>& PMT){//partial match table
		for (int len = 0; len < needle.length(); ++len)
		{
			int maxLen = len;
			while (maxLen >= 1 && needle[len] != needle[0 + PMT[maxLen - 1]])
			{
				maxLen = PMT[maxLen - 1];
			}
			if(maxLen >= 1)
				maxLen = PMT[maxLen - 1] + 1;
			PMT[len] = maxLen;
		}
	}
	int strStr(string haystack, string needle) {
		if (needle.length() == 0)
			return 0;
		vector<int> PMT(needle.length());
		genereateTable(needle,PMT);
		int i = 0;
		int startIndex = 0;
		while(i < int(haystack.length() - needle.length()) + 1)
		{
			int j = startIndex;
			while (j < needle.length() && haystack[j + i] == needle[j])
				++j;
			if (j == needle.length())
				return i;
			if (j == 0)
			{
				++i;
			}
			else
			{
				startIndex = PMT[j - 1];
				i += j - PMT[j - 1];
			}
		}
		return -1;
	}
};
