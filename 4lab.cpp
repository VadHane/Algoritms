#include <iostream>

using namespace std;

class Stack {
    struct elem {
        int value;
        elem* next;
    };
    
private:
    elem* last;
    int len;
    
public:
    Stack(){
        last = new elem();
        len = 0;
    }
    
    int pop(){
        if (len <= 0) {
            return 0/0;
        }
        
        elem* tmp = last->next;
        int result = last->value;

        delete last;

        last = tmp;

        len--;
        
        return result;
    }
    
    void add(int value){
        elem* tmp = new elem();
        tmp->next = last;
        
        last = tmp;
        
        last->value = value;
       
        len++;
    }
    
    int getLen(){
        return len;
    }
    
};



struct List {
    struct elem {
        double value;
        elem* next;
    };
    
    List(){
        head = nullptr;
        position = nullptr;
        end = nullptr;
    }
    
    elem* head;
    elem* end;
    elem* position;
    
    // func for adding new element into list
    void addInEnd(int);
    
    void addInBegin(int);
    
    void firstWay(int, int);
    
    void secondWay(int, int);
    
    elem* get(int);
    
    // func for iteration on all elem of list
    double next();
    
    // func for checking list on availability some elem
    bool isEmpty();
    
    //
    bool isEnd();
    
};


bool List::isEmpty(){
    return end == nullptr;
}


bool List::isEnd(){
    return position == nullptr;
}

List::elem* List::get(int index){ // need to added validation by index > length of list
    position = head;
    
    for (int i = 1; i < index; i++) {
        position = position->next;
    }
    
    return position;
}

void List::addInBegin(int value) {
    if (isEmpty()) {
        head = new elem();
        head->value = value;
        head->next = nullptr;
        end = head;
        position = head;
    } else {
        elem* tmp = new elem();
        tmp->value = value;
        tmp->next = head;
        head = tmp;
    }
}

void List::addInEnd(int value){
    if (isEmpty()) {
        head = new elem();
        head->value = value;
        head->next = nullptr;
        end = head;
        position = head;
    } else {
        end->next = new elem();
        end = end->next;
        end->value = value;
        end->next = nullptr;
    }
}


void List::firstWay(int i, int k){
    elem* firstElem;
    elem* secondElem = get(k + 1);
    
    if ((i - 1) > 0) {
        firstElem = get(i - 1);
        position = firstElem->next;
    } else {
        position = get(i);
        firstElem = secondElem;
    }
    
    Stack stack = *new Stack();
    
    while (position != secondElem) {
        stack.add(position->value);
        elem* tmp = position;
        position = position->next;
        
        delete tmp;
    }
    
    while (stack.getLen()) {
        addInBegin(stack.pop());
    }
    
    firstElem->next = secondElem;
    
    if (i > 1) {
        firstElem->next = secondElem;
    } else {
        head = secondElem;
    }
}

void List::secondWay(int i, int k){
    elem* firstElem;
    elem* secondElem = get(k + 1);
    
    if ((i - 1) > 0) {
        firstElem = get(i - 1);
        position = firstElem->next;
    } else {
        firstElem = secondElem;
        position = get(i);
    }
    
    while (position != secondElem) {
        addInEnd(position->value);
        elem* tmp = position;
        position = position->next;
        
        delete tmp;
    }
    
    if (i > 1) {
        firstElem->next = secondElem;
    } else {
        head = secondElem;
    }
}


int main(int argc, const char * argv[]) {
    List list = *new List();
    int numOfMembers, numOfQuery;
    
    cin >> numOfMembers;
    cin >> numOfQuery;
    
    for (int i = 0; i < numOfMembers; i++) {
        int item;
        cin >> item;
        list.addInEnd(item);
    }
    
    
    for (int i = 0; i < numOfQuery; i++) {
        int typeOfQuery, l, k;
        cin >> typeOfQuery;
        
        if (typeOfQuery == 1) {
            cin >> l;
            cin >> k;
            list.firstWay(l, k);
        } else if (typeOfQuery == 2) {
            cin >> l;
            cin >> k;
            list.secondWay(l, k);
        } else {
            cout << "Undefine command";
        }
    }
    
    cout << list.get(1)->value - list.get(numOfMembers)->value << endl;
    for (int i = 1; i <= numOfMembers; i++) {
        cout << list.get(i)->value << " ";
    }
     
}

