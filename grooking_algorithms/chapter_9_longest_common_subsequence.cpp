#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using string = std::string;

int main()
{
    const string target = "buoe";
    const std::vector<string> dict = {"fish", "vash", "blue"};

    // Max-heap to store the LCS length and the corresponding word
    std::priority_queue<std::pair<int, string>> max_heap;

    for (int d = 0; d < dict.size(); ++d)
    {
        const string &c_word = dict[d];
        /*
        The index 0 in the DP (Dynamic Programming) grid represents the case when one string has length 0.
        For this reason, the grid needs to have dimensions [target.length() + 1][c_word.length() + 1], where
        the extra row and column account for these empty string comparisons.
        */
        int grid[target.length() + 1][c_word.length() + 1] = {}; // Dynamically sized grid

        // Fill the DP grid for LCS calculation
        // We are starting at 1 because using row 0 would lead to a invalid index acces [i-1][j-1].
        for (int i = 1; i <= target.length(); ++i)
        {
            for (int j = 1; j <= c_word.length(); ++j)
            {
                if (target[i - 1] == c_word[j - 1])
                {
                    grid[i][j] = grid[i - 1][j - 1] + 1;
                }
                else
                {
                    grid[i][j] = std::max(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }

        // The bottom-right cell contains the LCS length
        // That's is true for Longest Common Subsequence (this algorithm), but NOT for Longest Common Substring.
        int lcs_length = grid[target.length()][c_word.length()];
        // Push the LCS length and the corresponding word into the max-heap
        max_heap.push({lcs_length, c_word});
    }

    auto [matches, word] = max_heap.top();

    std::cout << word << " : " << matches << std::endl;

    return 0;
}
