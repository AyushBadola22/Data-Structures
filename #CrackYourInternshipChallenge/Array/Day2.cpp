
/*
    Distribute the chocolates (GFG)
    Sliding window
    Stament : Given array of numbers of chocolates inside a packet.
    There are M students , distribute such that the difference bwtween
    who get maximum and minimum chocolate is minimum.
*/

    class Solution
    {
    public:
        long long findMinDiff(vector<long long> arr, long long n, long long m)
        {
            // code
            sort(arr.begin(), arr.end());
            long long minDiff = LONG_MAX;
            for (int i = 0; i < n - m + 1; i++)
            {
                if (arr[i + m - 1] - arr[i] < minDiff)
                {
                    minDiff = arr[i + m - 1] - arr[i];
                }
            }
            return minDiff;
        }
    };

// ######################################################################
/*
    2. Two sum
    Brute force says check the each number pairs to find it.

    Optimized says use a map to find whether the numbers exists.
    > Since the target is the sum of two numbers , we can try to find the other number through the map.
*/

    class Solution
    {
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            map<int, int> mpp;
            int size = nums.size();
            for (int i = 0; i < size; i++)
            {
                auto it = mpp.find((target - nums[i]));
                if (it == mpp.end())
                {
                    mpp[nums[i]] = i;
                }
                else
                {
                    return {it->second, i};
                }
            }
            return {};
        }
    };

// ######################################################################

/*
    Buy and Sell stocks II

    You can buy and sell stocks more than one time.
    But at the same day you cannot buy and sell at the same time.
    To find the maximum profit we can use either recursion , dp or some intutive way.

    Here we can determine when to buy and when to sell by plotting a graph.
    When the graph goes down then buy the stock and sell it to the day when it rises again .
    Find local minima and local maxima. To make it more optimized just saw previous day prices,
    if previous day prices is lesser than today's , just add the profit and at last return it.
*/

    class Solution
    {
    public:
        int maxProfit(vector<int> &prices)
        {
            int i = 1, size = prices.size(), profit = 0;
            for (i = 1; i < size; i++)
            {
                if (prices[i] > prices[i - 1])
                {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }
    };

// ######################################################################

/*
    4. Subarray sum is divisble by k
    Uses the logic of the prefix sum and some calculations.
    according to maths
        >>>>  (p2 - p1) = r  , where p2 and p1 is sum from a range and p2 distance is more than p1.
    So if we subtract the prefix sum we can find the sum of a range. Adding modulous both side
        >>>> (p2 - p1)% k  =  r % k , if sum of subarray inside the range R is divisible by K then
        >>>> (p2 - p1)% k = 0
        >>>> (p2)% k = (p1) % k
    This proves that if modulous of a prefix sum from range is equals to the modulous of prefix sum of another range
    then in that case  the there exists am subarray somewhere in range which is divisble by K.

    The number of the subarrays depends on the subarrays that it previously created.
    Ultimately depending on the frequency .
    So if we can find the prefix sum whose modulous is repeating then we can determine that subarray sum if equals to K.

    The only problem is handling negative cases.
*/

    class Solution
    {
    public:
        int maxProfit(vector<int> &prices)
        {
            int i = 1, size = prices.size(), profit = 0;
            for (i = 1; i < size; i++)
            {
                if (prices[i] > prices[i - 1])
                {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }
    };


// ######################################################################

/*
    5.  Find all the duplicates in the array

    Brute force says use the hashmap to count the frequency of the numbers , 
    whichever elements have more than 1 frequency than that element is repeated.

    Another approach says sort the element , then find whichever repeating. 

    Optimized says  traverse through array , and make the element negative at whatever index its pointing to. 
    Since the element can occurs only 1 or 2 times then if numbers repeats then it will point to the index whose value is already negative. 
    For that case we will put it inside the result array. 
*/

    class Solution {
    public:
        vector<int> findDuplicates(vector<int>& nums) {
            vector<int> result ; 

            for(int i : nums ){
                if(nums[abs(i)-1] < 0){
                    result.emplace_back(abs(i)); 
                }
                else {
                    nums[abs(i)-1] = -nums[abs(i)-1] ; 
                }
            }
            return result; 
        }
    };