#include<iostream> 
#include<vector>
#include<sstream> 
#include<algorithm>
using namespace std; 

void display(vector<int> nums){
    for(auto it : nums){
        cout<<it<<" ";
    }
    cout<<endl;
}

/*
3 2 2 -1 4 1 1 0 0 0 
*/
/* *********************************************************************
 ! Count Sort Algorithm : Only for the positive numbers and natural numbers .  
 *  Calculate the frequency =>  It tells how many  times the element in the array exists. 
 * Calculate the cummulative frequency => It helps to determine the correct position of the element.  
 * Iterate through the back and store elements in the result. => It ensure the relative order of the element remains same. 
************************************************************************/
/*
? How the algorithm works ? 
    . The frequency table just help with the number of times the element is present in it. 
    . The normal  counting sort will  just mainatin the count and sort irrespective of the order. 
    . That where the concept of the cummulative frequency comes , where it defines the number of elements that will be  skipped so that the current element can come. 
    . We need to traverse from the back so that we can effectively map the current element in their correct order. 
*/

vector<int> countSort(const vector<int> nums  ){
    int maximum = *max_element(nums.begin(), nums.end());
    vector<int> freq(maximum+1 , 0); // We will keep track of the number of times the element has come in the array

    for(int i =0; i<nums.size(); i++){
        freq[nums[i]]++;
    }

    vector<int> cumFreq(maximum+1 , 0);
    //We will find the cummulative frequency that will help us to put the element in their correct order inside the result. 
    for(int i = 1 ; i<cumFreq.size(); i++){
        cumFreq[i] = cumFreq[i-1] + freq[i]; 
    }

    // Now we will use the cummulative frequency to find the correct position of the element. 
    vector<int> result(nums.size()); 
    for(int i = nums.size()-1 ; i>=0 ; i--){
        cumFreq[nums[i]]--; 
        result[cumFreq[nums[i]]] = nums[i]; 
    }
    return result; 
}
/* Count Sort for the negative numbers also */
vector<int> countSortNegative(const vector<int> nums){
    int maximum = *max_element(nums.begin(),  nums.end()); 
    int minimum = *min_element(nums.begin() ,nums.end()); 
    vector<int>freq(maximum-minimum+1 , 0); 
    
    // =>  Count the frequency of the elements 
    for(int i =0; i<nums.size(); i++){
        freq[nums[i] - minimum]++; 
    }
    //  => Now create cummulative freq and map it 
    vector<int> cumFreq( maximum - minimum  + 1 , 0); 
    cumFreq[0] = freq[0]; 
    for(int i = 1; i<cumFreq.size(); i++){
        cumFreq[i] = cumFreq[i-1] + freq[i]; 
    }

    // => Create result and map the element in their correct postion
    vector<int> result(nums.size(), 0); 
    cumFreq[0] = freq[0]; 
    for(int i = nums.size() -1; i>=0; i--){
        cumFreq[nums[i] - minimum]--;
        result[cumFreq[nums[i] - minimum]] = nums[i]; 
    }
    return result; 
}




// ! ------------ Main ----------------------
int main(){
    int testcases; 
    cout<<"Enter the number of testcases : "; 
    cin>>testcases;

    while(testcases--){ 
        string inputs; 
        cout<<"\nEnter the array elements seperated by the spaces..............\n";
        cout<<"=> ";
        cin.ignore(); 
        getline(cin , inputs); 
        istringstream stream(inputs);
        vector<int> nums; 
        int num = 0; 
        while(stream >> num ){
            nums.emplace_back(num); 
        }
        cout<<"Given elements : "; 
        display(nums);
        cout<<"After the sorting : "; 
        nums = countSortNegative(nums);
        display(nums); 
    }
}
