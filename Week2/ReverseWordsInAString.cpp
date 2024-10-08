class Solution
{
public:
    string reverseWords(string s)
    {
        string result;
        int i = 0, n = s.length();

        while (i < n)
        {
            // Skip leading spaces
            while (i < n && s[i] == ' ')
                i++;

            if (i >= n)
                break;

            // Find end of the current word
            int j = i;
            while (j < n && s[j] != ' ')
                j++;

            // Extract the word and prepend to result
            string word = s.substr(i, j - i);
            result = result.empty() ? word : word + " " + result;

            // Move to the next word
            i = j + 1;
        }

        return result;
    }
};
