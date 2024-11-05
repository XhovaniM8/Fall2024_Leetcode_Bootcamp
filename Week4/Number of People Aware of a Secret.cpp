#include <vector>
using namespace std;

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0); // dp[i] represents the number of people who learn the secret on day i
        dp[1] = 1;                // Initially, only one person knows the secret on day 1

        int totalSharing = 0; // Total number of people who can share the secret on each day
        for (int day = 2; day <= n; ++day)
        {
            // Add new sharers who learned the secret exactly `delay` days ago
            if (day - delay >= 1)
            {
                totalSharing = (totalSharing + dp[day - delay]) % MOD;
            }
            // Remove people who forget the secret after `forget` days
            if (day - forget >= 1)
            {
                totalSharing = (totalSharing - dp[day - forget] + MOD) % MOD;
            }
            // The number of new people who learn the secret today
            dp[day] = totalSharing;
        }

        // Sum up people who are aware of the secret and haven't forgotten it by day n
        int result = 0;
        for (int day = n - forget + 1; day <= n; ++day)
        {
            result = (result + dp[day]) % MOD;
        }
        return result;
    }
};
