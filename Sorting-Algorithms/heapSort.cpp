#include<iostream>
#include<windows.h>
#include<vector>
using namespace std; 
void loading(string message){
    cout<<("Loading "+message); 
    for(int i = 0; i<10; i++){
        Sleep(150); 
        cout<<"..."; 
    }
    cout<<"\n\n"; 
}

void display(vector<int> array){
    for(auto it : array){
        cout<<it<<" "; 
    }
    cout<<endl;
}




/* *********************** 
        * Max Heap
 ***********************/
void heapifyMax(vector<int>&array , const int size, int i){
    int child1 = 2*i  + 1; 
    int child2 = 2*i  + 2; 
    int maximum = i;  
    if(child1 < size && array[child1] > array[maximum]){
        maximum = child1; 
    }
    if(child2 < size && array[child2] > array[maximum]){
        maximum = child2; 
    }
    if(maximum != i){
        swap(array[i], array[maximum]); 
        heapifyMax(array, size, maximum); 
    }
}

void buildMaxHeap(vector<int> &array ){
    loading("Heap Sort Function "); 

    int size = array.size();
    for(int i = size/2; i>=0; i--){
        heapifyMax(array, size , i);  
    }
}

void extractMaximum(vector<int> &array, int size){
    while(size){
        swap(array[0] , array[size-1]); 
        heapifyMax(array, size-1, 0);
        size--;  
    }
}

void maxHeapSort(vector<int> & array){
    buildMaxHeap(array);
    extractMaximum(array, array.size()); 

}

/* *********************** 
        * Min Heap
***********************/

void heapifyMin(vector<int> &nums, int size , int i ){
    int child1 = 2*i+1; 
    int child2 = 2*i+2;

    int minimum = i; 

    if(child1 < size && nums[child1] < nums[minimum]){
        minimum = child1; 
    } 

    if(child2 < size  && nums[child2] < nums[minimum]){
        minimum = child2; 
    }

    if(minimum != i ){
        swap(nums[minimum], nums[i]); 
        heapifyMin(nums , size , minimum); 
    }
}

void buildMinHeap(vector<int> &nums){
    int size = nums.size();

    for(int i = size/2; i>=0; i-- ){
        heapifyMin(nums, size , i);
    } 
}

void extractMinimum(vector<int> &nums ){
    int size = nums.size(); 
    while(size){
        swap(nums[0] , nums[size-1]); 
        heapifyMin(nums , --size, 0); 
    }
}

void minHeapSort(vector<int>&array){
    /**
     * Build the heap tree , iterate through the parents only 
     * Use heapify function to put the children at their original order according to the max heap or min heap tree
     * After complete tree is created extract the maximum or minimum according to the tree type (max heap ot min heap) 
    */

   buildMinHeap(array); 
   extractMinimum(array);
}


    /* *********************************************************************||  
                            ? Main function                                                         
    *********************************************************************** ||*/

int main(){
    int numberOfTestCases = 0;  
    cout<<"Please Enter the number of testcases : "; 
    cin>>numberOfTestCases; 
    while(numberOfTestCases--){
        system("clear"); 
        loading("Terminal");
        int size = 0; 
        cout<<"Size : "; 
        cin>>size; 
        vector<int> array; 
        while(size--){
            int num = 0; 
            cout<<"Enter element : "; 
            cin>>num; 
            array.emplace_back(num);  
        }
        display(array); 
        loading(" after heap sort"); 
        minHeapSort(array); 

        display(array); 
        char ch ; 
        cin>>ch;
    }
}