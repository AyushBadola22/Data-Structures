/*
    1. Container with the most water.
    Given heights of the walls , except two walls all walls can be destroyed.
    After choosing which two walls contains the most water.
*/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int start = 0, end = height.size() - 1, maxArea = 0;
        while (start < end)
        {
            int waterLevel = min(height[start], height[end]);
            maxArea = max(maxArea, waterLevel * (end - start));
            if (height[end] >= height[start])
                start++;
            else
                end--;
        }
        return maxArea;
    }
};


// ##########################################################################################

/*
    2.  3 SUM 
    Kind of brute force type - uses the set data structure to avoid the repetition of the vector. 
    >   Instead could have been done more efficiently by checking if the element at i , j or k 
        is equals to its previous value , then move it forward or backwards. 
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> result; 
        for(int i =0; i<nums.size(); i++){
            if( i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1 , k = nums.size()-1; 
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k]; 
                if(sum < 0) j++; 
                else if(sum > 0)k--; 
                else {
                    result.emplace_back(vector<int>{nums[i] , nums[j] , nums[k]});
                    j++;
                    k--; 
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(k > j && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return result;
    }
};


// ##########################################################################################


/*
    3.  4 Sum 

    Sort the array and use 4 pointers to find four numbers. 
    Edge cases : If addition of two numbers result very great that cannot be stored in the int. 
    Edge cases : Chances of the array out of bounds and  need to maintain the result such that no duplicates are there
  
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> result; 
        int size = nums.size(); 

        for(int i = 0; i < size-3; i++ ){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i+1; j < size-2; j++){
                
                while( j != i+1 && j< size-2 && nums[j] == nums[j-1]) ++j; 
                if(j == size-2) continue;
                int k = j+1 , l = size-1;

                while(k < l){
                    long long sum= nums[i]; 
                    sum += nums[j]; 
                    sum += nums[k]; 
                    sum += nums[l];

                    if(sum == target){
                        result.push_back({nums[i], nums[j], nums[k], nums[l]}); 
                        ++k; --l; 

                        while(k < l && nums[k] == nums[k-1]) k++; 
                        while(k < l && nums[l] == nums[l+1]) l--; 
                    } 
                    else if(sum < target){
                        k++; 
                    }
                    else {
                        l--; 
                    }
                }
                
            }
        }
        return result;
    }
};

// ##########################################################################################

/*
    4.  Subarray Sum equals K 
    If the prefix sum at the current index is P , and K is the target. 
    >>>> Then  P - K = P0  ,  so while calculating the prefix sum, 
    >>>> if its repeating that means that there exists the subarray whose sum was equals K ,
    >>>> So we add it accordingly in our answer.   
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int , int > map; 
        map[0] = 1; 
        int count = 0, prefixSum = 0;  
        for(int num : nums){
            prefixSum += num; 
            count += map[prefixSum - k]; 
            map[prefixSum]++; 
        }
        return count; 
    }
};


// ##########################################################################################


/*
    5.  Maximum Point One can Obtain from Cards 

    Given an array of cards with points, can access the first or last card only. 
    Select the cards such that points are maximized. 
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0, rightSum = 0, maxSum = 0; 

        for(int i = 0; i<k; i++){
            leftSum  += cardPoints[i]; 
        }

        maxSum = max(maxSum, leftSum); 
        
        int j = cardPoints.size()-1; 
        
        for(int i = k-1; i >=0 ; i--){
            leftSum -= cardPoints[i]; 
            rightSum += cardPoints[j--]; 
            maxSum = max(rightSum + leftSum , maxSum); 
        }
        return maxSum ; 
    }
};

// ##########################################################################################

/*
    6 .  Spiral Matrix
*/
class Solution { 
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int top = 0, bottom = matrix.size() - 1, left = 0,
            right = matrix[0].size() - 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                result.emplace_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                result.emplace_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.emplace_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.emplace_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};

//#######################################################################
