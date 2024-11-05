class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.length();
        std::vector<bool> dp(n + 1, false);
        dp[0] = true; // Base case: empty string can always be segmented

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && wordSet.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};