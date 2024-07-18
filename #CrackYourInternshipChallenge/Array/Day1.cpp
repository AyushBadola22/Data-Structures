/*
    1. Find the duplicate number from the array.

    Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
    There is only one repeated number in nums, return this repeated number.
    You must solve the problem without modifying the array nums and uses only constant extra space.

*/

// Brute-force - Sort and find the duplicate  O(nlogn)
// Optimized - Use hashmap to find the duplicate O(n) but space complexity increases to O(n)

/*
    its mathamatically proved that the point where the fast and slow collides
    From that point its X distance far from the starting point and same distance from the point where they collided.
    From that point if we move X distance we can get the point where the loop starts.

*/
#include <vector>
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int fast = 0, slow = 0;

        fast = nums[nums[fast]];
        slow = nums[slow];

        while (fast != slow)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        slow = 0; // move it back to the starting point.
        while (nums[fast] != nums[slow])
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return nums[slow];
    }
};

// ######################################################################################################################

/*
    2. Sort 0s , 1s and 2s
    Using two pointer approach ,
    move all the zeroes to the starting side ,
    and move all the 2s to the ending side,
    1s will automatically be sorted.
*/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int start = 0, end = nums.size() - 1, i = 0;
        while (i <= end)
        {
            switch (nums[i])
            {
            case 0:
                swap(nums[start++], nums[i++]);
                break;

            case 1:
                i++;
                break;

            case 2:
                swap(nums[i], nums[end--]);
            }
        }
    }
};

// ######################################################################################################################

/*
    3. Remove duplicates from the array.

    Using two pointer , if the current element == previous element then continue
    else move it to its correct place.

*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 1, j = 1, size = nums.size();

        while (j < size)
        {
            if (nums[j] != nums[j - 1])
            {
                nums[i++] = nums[j];
            }
            j++;
        }
        return i;
    }
};

// ######################################################################################################################

/*
  4. Move zeroes
  Two pointer approach
*/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0, size = nums.size(), j = 0;

        while (j < size)
        {
            if (nums[j] != 0)
            {
                swap(nums[i++], nums[j++]);
            }
            else
                j++;
        }
    }
};

// ######################################################################################################################

/*
    5. Buy and sell stocks
    We traverse from the last to keep track of the maximum
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0, size = prices.size();
        int maxSell = prices[size - 1];

        for (int i = size - 2; i >= 0; i--)
        {
            maxProfit = max(maxProfit, maxSell - prices[i]);
            maxSell = max(prices[i], maxSell);
        }
        return maxProfit;
    }
};

// ######################################################################################################################
