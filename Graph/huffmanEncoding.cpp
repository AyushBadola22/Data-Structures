#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<map>
#include <unordered_map>
using namespace std;


struct node {
    node * left , *right;
    char character ; 
    int frequency; 
};

node * createNode (char ch , int freq){
    node * newNode = new node; 
    newNode->character = ch; 
    newNode->frequency = freq;
    return newNode; 
}

typedef struct node node; 
void heapify (vector<node * > &nodeArray, int i , int size){
    int smallest = i; 
    int child1 = i*2+1; 
    int child2 = i*2+2; 

    if(child1<size && nodeArray[child1]->frequency < nodeArray[smallest]->frequency){
        smallest = child1;
    }
    
    if(child2<size && nodeArray[child2]->frequency < nodeArray[smallest]->frequency){
        smallest = child2;
    }

    if(smallest != i){
        swap(nodeArray[smallest], nodeArray[i]); 
        heapify(nodeArray, smallest , size); 
    }
}


void print(node * root , string s){
    if(root->character != '$'){
        cout<<root->character<<" : "<<s<<" ,"; 
        return ; 
    }
    print(root->left, s + "0"); 
    print(root->right, s + "1"); 
}


vector<node *> buildNodeArray (string str ){
    unordered_map<char , int> freqTable ; 

    for(char ch : str ){
        freqTable[ch]++; 
    }

    vector<node * >nodeArray ;

    for(auto pair : freqTable){
        nodeArray.push_back(createNode(pair.first, pair.second));
    }
    return nodeArray;
}

void buildHeap (vector<node *> &nodeArray){
    for(int i = nodeArray.size()/2; i>=0; i--){
        heapify(nodeArray, i , nodeArray.size()); 
    }
    
}

node * extractMinimum (vector<node * >&minHeap , int &size){
    node * newNode = minHeap[0]; 
    swap(minHeap[0], minHeap[size-1]);
    heapify(minHeap, 0 , size-1 ); 
    minHeap.pop_back(); 
    size -- ; 
    return newNode; 
}

void buildHuffman(vector<node *> minHeap, int size){
    while(size != 1){
        node * n1 = extractMinimum(minHeap , size); 
        node * n2 = extractMinimum(minHeap , size); 

        node * temp = new node; 
        temp->character = '$'; 
        temp->frequency = n1->frequency + n2->frequency; 
        temp->left = n1; 
        temp->right = n2; 
        minHeap.push_back(temp); 
        size++; 
        heapify(minHeap, size-1 , size) ; 
    }
    print(minHeap[0], "");
}



int main(){
    string str ; 
    cin>>str; 
    vector<node * > tree  = buildNodeArray(str); 
    buildHeap(tree); 

    for(auto it : tree){
        cout<<it->character<<" "<<it->frequency<<endl; 
    }
    int size = 4; 
    buildHuffman(tree, tree.size());
}

