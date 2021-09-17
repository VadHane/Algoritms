#include <iostream>
#include <stdio.h>
using namespace std;

class Queue {
    struct elem{
        int value;
        elem* next;
    };
public:      
    Queue(){
        first = nullptr;
        last = nullptr;
    }
        
    elem* first;
    elem* last;
        
    bool isEmpty(){
        return first == nullptr;
    }
        
    void add(int value){
        if(isEmpty()){
            first = new elem();
            first->value = value;
            first->next = nullptr;
            last = first;
        } else {
            last->next = new elem();
            last = last->next;
            last->value = value;
            last->next = nullptr;
        }
    }
        
    int pop(){
        if(isEmpty()){
            return 0;
        }
            
        int res = first->value;
        elem* garbage = first;
            
        first = first->next;
            
        delete garbage;
            
       return res;
    }
};

class Stack{
    Queue* buffer = new Queue();
public:   
    void add(int value){
        Queue* tmp = new Queue();
        tmp->add(value);
        
        while(!buffer->isEmpty()){
            tmp->add(buffer->pop());
        }
        
        buffer = tmp;
        tmp = nullptr;
    }
    
    int pop(){
        return buffer->pop();
    }
    
};

int main()
{
    Stack tmp = *new Stack();
    
    for (int i = 0; i < 5; i++) {
        int item;
        cin >> item;
        tmp.add(item);
    }
    
    for (int i = 0; i < 5; i++) {
        
        cout << tmp.pop() << " ";
        
    }

    return 0;
}
