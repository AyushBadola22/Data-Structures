// ############################################################################################

/*
    1. Word Search
    Given a matrix of characters , you can move left , right , up and down
    Cannot use the same character twice.

    Approach : Find the first occurence where the word matches with the character in matrix.

    > After that recursively move up , down , left and right.
    > Mark * when visiting path , so that it may not repeated.
    > After exploring change the path back to its original character.
*/

class Solution
{
public:
    int rows = 0, cols = 0, wordLength = 0;

    bool pathExists(int i, int j, int index, vector<vector<char>> &board, string word)
    {
        if (index == wordLength)
            return true;

        if (i >= rows || j >= cols || i < 0 || j < 0 ||
            board[i][j] != word[index]){
            return false; // either word doesnt match or out of bounds
        }

        board[i][j] = '*';  // marks the path visited
        bool result = pathExists(i + 1, j, index + 1, board, word) ||
                      pathExists(i, j + 1, index + 1, board, word) ||
                      pathExists(i - 1, j, index + 1, board, word) ||
                      pathExists(i, j - 1, index + 1, board, word);

        board[i][j] = word[index];
        return result;
    }

    bool exist(vector<vector<char>> &board, string word){
        rows = board.size();
        cols = board[0].size();
        wordLength = word.length();

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (board[i][j] == word[0] && pathExists(i, j, 0, board, word))
                    return true;                
            }
        }
        return false;
    }
};

// ############################################################################################


/*
    Merge two sorted array
    I tried to actually solve the problem by not moving all data in one array and then sort. 
    It was like insertion sort but with some modifications. 
*/
class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // idea is like insertion sort

        for(int i = 0; i < n ; i++){
            int j = m-1;
            int value = nums2[i];
            
            while(j>=0 && nums1[j] > value){
                nums1[j+1] = nums1[j];
                j--;  
            }
            nums1[j+1] = value; 
            m++;  
        }
    }
};


// ############################################################################################

/*
    Majority Element - easy one 
*/

    
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num != candidate) {
                count--;
            } else {
                count++;
            }
        }
        return candidate;
    }
};


// ############################################################################################

/*
    Jump Game
    A very good greedy and dp question 
    If i can reach a index , that means i can use all the jumps from between , 
    if somehow i can jump upto the last or beyond , then the last index is reachable.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0 , size = nums.size() , i = 0;

        for(i = 0; i<size-1; i++){
            if(i > reachable) return false;
            reachable = max(reachable , nums[i]+i); 
        }
        return (reachable < size-1) ? false : true;
    }
};


// ############################################################################################

/*
    Permutations of the array 

    Generate permutations and use sets to store the unique vectors
*/

class Solution {

  public:
  
    void check(vector<int> arr , int size , vector<int> current , vector<bool> &visited ,  set<vector<int>>&answer){
        if(current.size() == arr.size()){
            answer.insert(current);
            return; 
        }        
        
        for(int i = 0; i<arr.size(); i++){
            if(visited[i] == true) continue; 
            visited[i] = true; 
            current.push_back(arr[i]); 
            check(arr , size, current ,visited, answer); 
            visited[i] = false; 
            current.pop_back(); 
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        
        vector<bool>visited(arr.size(), false); 
        set<vector<int>> answer; 
        
        sort(arr.begin(), arr.end()); 
        check(arr,n , {}, visited , answer);
        return {answer.begin(), answer.end()}; 
    }
};


// ############################################################################################
