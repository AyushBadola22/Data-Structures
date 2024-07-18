#include<iostream> 
#include<sstream>
using namespace std;

typedef struct node {
    int val; 
    node * next = NULL; 
} node; 

void display(node * head){
    if(head == NULL){
        cout<<"Empty\n"; 
        return ; 
    }
    while(head){
        cout<<head->val<<"->"; 
        head = head->next; 
    }
    cout<<"NULL\n"; 
}

void erase(node ** head){
    cout<<"Process of deleting nodes ............\n"; 
    while(*head){
        node * previous = *head; 
        (*head) = (*head)->next; 
        delete previous;     
    }
}

void insert (node ** head , int value  ){
    node * newnode = new node; 
    newnode->val = value; 

    if(*head == NULL){
        *head = newnode; 
    }
    else {
        node * last = *head; 
        while(last->next){
            last = last->next; 
        } 
        last->next = newnode; 
    }
}
///////////////////////////////////////////

void splitNode(node *head, node ** list1, node ** list2){
    node * slow = head, *fast = head->next; 

    while(fast){
        fast = fast->next; 
        if(fast != NULL){
            slow= slow->next; 
            fast = fast->next; 
        }
    }

    *list1 = head;  
    *list2 = (slow->next);
    slow->next = NULL;  
}

node * mergeNode (node * head1 , node * head2 ){ // leetcode question 
    node * result = new node; 
    node * rear = result;   

    if(head1 == NULL) return head2; 
    else if(head2 == NULL) return head1; 

    while (head1 && head2)
    {
        if(head1->val < head2->val){
            rear->next = head1; 
            head1 = head1->next; 
        }
        else {
            rear->next = head2; 
            head2 = head2->next; 
        }
        rear = rear->next;
    }

    while(head1){
        rear->next = head1; 
        head1 = head1->next; 
        rear = rear->next ;
    }
    while(head2){
        rear->next = head2; 
        head2 = head2->next; 
        rear = rear->next; 
    }
    return result->next; 
}

void mergeSort(node **headNode){
    node * head = *headNode;
    node * list1; 
    node * list2; 

    if(head == NULL || head->next == NULL) return ; 
    
    splitNode(head, &list1, &list2); 
    mergeSort(&list1); 
    mergeSort(&list2);
    *headNode = mergeNode(list1 , list2);  
}

int main(){
    node * head = NULL ; 
    cout<<"Enter the list elements seperate by spaces => \n"; 
    string input = ""; 
    getline(cin , input); 
    stringstream ss(input); 
    while(ss >> input){
        insert(&head , stoi(input)); 
    }
    display(head); 
    mergeSort(&head); 
    display(head); 
    erase(&head);
    display(head); 
}