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
    ! Works only on the positive integers 
 ? Algorithm => 
 * Find The  Maximum element and iterate that much times . 
 * Apply the counting sort at the same time . 
 * In the counting sort store the occurences in the vector 'count'.  
*/ 

vector<int> countSort  (vector<int> nums , int exp){
    vector<int> result(nums.size() , 0 ); 
    int i = 0;
    vector<int> freq (10, 0);  

    for(int i=0; i<nums.size(); i++){
        freq[(nums[i]/exp)%10]++; 
    }

    vector<int> cumFreq(10, 0); 
    cumFreq[0] = freq[0]; 
    for(int i=1; i<10; i++){
        cumFreq[i] = cumFreq[i-1] + freq[i]; 
    }
    display(freq); 
    display(cumFreq); 
    for(int i = nums.size()-1; i>=0; i--){
        cumFreq[(nums[i]/exp)%10]--;   
        result[cumFreq[(nums[i]/exp)%10]]= nums[i]; 
    }
    display(result); 
    cout<<"\n\n"; 
    return result; 
}


void radixSort(vector<int> &nums ){
    int maximum = *max_element(nums.begin(), nums.end()); 
    for(int exp = 1; maximum / exp > 0; exp*=10 ){
        nums = countSort(nums , exp); 
    }
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
        radixSort(nums); 
        cout<<"After the sorting : "; 
        display(nums); 
    }
}