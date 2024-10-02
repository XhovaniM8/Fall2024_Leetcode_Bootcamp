class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // Bucket to store the count of each color (0, 1, and 2)
        int color[3] = {0, 0, 0};

        for (int i = 0; i < nums.size(); i++)
        {
            color[nums[i]]++;
        }

        int index = 0;

        for (int i = 0; i < color[0]; i++)
        {
            nums[index++] = 0;
        }

        for (int i = 0; i < color[1]; i++)
        {
            nums[index++] = 1;
        }

        for (int i = 0; i < color[2]; i++)
        {
            nums[index++] = 2;
        }
    }
};
