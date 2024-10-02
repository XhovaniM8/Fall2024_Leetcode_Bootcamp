class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            int curSum = numbers[left] + numbers[right];

            if (curSum > target)
            {
                right--;
            }
            else if (curSum < target)
            {
                left++;
            }
            else
            {
                return {left + 1, right + 1};
            }
        }

        // In case no solution is found (although the problem guarantees there is one)
        return {};
    }
};
