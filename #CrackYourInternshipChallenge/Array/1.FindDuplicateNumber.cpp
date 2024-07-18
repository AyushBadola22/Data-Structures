/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.
*/


// Brute-force - Sort and find the duplicate  O(nlogn)  
// Optimized - Use hashmap to find the duplicate O(n) but space complexity increases to O(n)


// its mathamatically proved that the point where the fast and slow collides 
// From that point its X distance far from the starting point and same distance from the point where they collided. 
// From that point if we move X distance we can get the point where the loop starts.

class Solution {
public:


    int findDuplicate(vector<int>& nums) {  
        int fast = 0 , slow = 0; 

        fast = nums[nums[fast]]; 
        slow = nums[slow]; 

        while(fast != slow){
            fast = nums[nums[fast]]; 
            slow = nums[slow]; 
        }
        slow = 0; // move it back to the starting point.
        while(nums[fast] != nums[slow]){
            fast = nums[fast]; 
            slow = nums[slow]; 
        }
        return nums[slow]; 
    }
}; 


