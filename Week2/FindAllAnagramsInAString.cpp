class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;
        int sLen = s.size(), pLen = p.size();

        if (pLen > sLen)
            return result; // Early return if p is longer than s

        // Frequency maps for characters in p and the current window in s
        vector<int> pCount(26, 0), windowCount(26, 0);

        // Populate the frequency map for p
        for (char c : p)
        {
            pCount[c - 'a']++;
        }

        // Initial window setup
        for (int i = 0; i < pLen; i++)
        {
            windowCount[s[i] - 'a']++;
        }

        // Slide the window over s
        for (int i = 0; i <= sLen - pLen; i++)
        {
            // Check if the current window is an anagram
            if (windowCount == pCount)
            {
                result.push_back(i);
            }

            // Slide the window: remove the starting character of the current window and add the next character
            if (i + pLen < sLen)
            {
                windowCount[s[i] - 'a']--;
                windowCount[s[i + pLen] - 'a']++;
            }
        }

        return result;
    }
};
