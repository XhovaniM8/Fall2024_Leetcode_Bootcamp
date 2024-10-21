class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        // Step 1: Determine which rows and columns need to be zeroed
        // Check if the first row needs to be zeroed
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[0][j] == 0)
            {
                firstRowZero = true;
                break;
            }
        }

        // Check if the first column needs to be zeroed
        for (int i = 0; i < rows; ++i)
        {
            if (matrix[i][0] == 0)
            {
                firstColZero = true;
                break;
            }
        }

        // Use the first row and column to mark the rows and columns that need to be zeroed
        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // Mark the row
                    matrix[0][j] = 0; // Mark the column
                }
            }
        }

        // Step 2: Set the rows and columns to zero based on the markers
        // Zero out cells in the marked rows and columns
        for (int i = 1; i < rows; ++i)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < cols; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < cols; ++j)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < rows; ++i)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Zero out the first row and column if needed
        if (firstRowZero)
        {
            for (int j = 0; j < cols; ++j)
            {
                matrix[0][j] = 0;
            }
        }

        if (firstColZero)
        {
            for (int i = 0; i < rows; ++i)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
