class Solution
{
public:
    int myAtoi(string s)
    {
        // Check Empty
        if (s.empty())
        {
            return 0;
        }

        int len = s.length();
        int i = 0;
        int sign = 1;
        long result = 0;

        // Skip leading whitespaces
        while (i < len && s[i] == ' ')
        {
            i++;
        }

        // Check for sign
        if (i < len && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert characters to integer
        while (i < len && isdigit(s[i]))
        {
            result = result * 10 + (s[i] - '0');
            // Check for overflow
            if (result * sign > INT_MAX)
                return INT_MAX;
            if (result * sign < INT_MIN)
                return INT_MIN;
            i++;
        }

        return static_cast<int>(result * sign);
    }
};
