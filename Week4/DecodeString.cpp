#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> counts;         // Stack to store repetition counts
        stack<string> resultStack; // Stack to store intermediate results
        string current;            // Current decoded substring
        int index = 0;

        while (index < s.size())
        {
            if (isdigit(s[index]))
            {
                // Calculate the number (count) before the '['
                int count = 0;
                while (isdigit(s[index]))
                {
                    count = count * 10 + (s[index] - '0');
                    index++;
                }
                counts.push(count);
            }
            else if (s[index] == '[')
            {
                // Push the current string to resultStack and reset it
                resultStack.push(current);
                current = "";
                index++;
            }
            else if (s[index] == ']')
            {
                // Pop the count and previous string to build the decoded string
                int repeatCount = counts.top();
                counts.pop();
                string temp = resultStack.top();
                resultStack.pop();
                for (int i = 0; i < repeatCount; i++)
                {
                    temp += current;
                }
                current = temp;
                index++;
            }
            else
            {
                // Append regular characters to the current string
                current += s[index];
                index++;
            }
        }
        return current;
    }
};
