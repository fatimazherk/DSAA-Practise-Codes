//stack implementation
//using arrays
//fatimaa khan

#include <iostream>
#include <vector>

using namespace std;
class Stack{
    int top;
    int capacity;
    int *arr;
    public:
    Stack(int c){
        capacity=c;
        top=-1;
        arr=new int[capacity];
    }
    //constructor ke through mene capacity ko initialize karwaya 
    // top ko -1 kiya kyuke array zero se shuru hota hai aur jitni bar push krenge toh top ko increment krenge
    //aur array ko dynamically allocate kiya capacity ke size jitna
    ~Stack(){
        delete[] arr;
    }
    //idher memory ko free kiya jaraha hai
    bool isEmpty(){
       if(top==-1){
        cout<<"Your Stack Is Empty"<<endl;
        //agar top -1 hai toh yani ke apne stack mei kch dala hi nai
        return true;
       }
       return false;
    }
   bool isFull(){
        if(top==capacity-1){
            cout<<"Stack Overflow"<<endl;
            return true;
            //agar capacity se aik niche hai mtlb apka array pura bhargeya hai
        }
        return false;
    }
   void push(int element) {
    if (isFull()) {
        cout << "Can't add element to stack" << endl;
        return;  // Exit the function if stack is full
    }
    arr[++top] = element;  // Only push if there's space
}
    // int pop(){
    //     if(isEmpty()){
    //         cout<<"Elements cant be removed"<<endl;
    //     } idher sahi output islye nai aega kyuke apne return nai kraya 
    //     top--;
    // }
    void pop() {
    if (isEmpty()) {
        cout << "Elements can't be removed" << endl;
        return;  // Exit the function if stack is empty
    }
    top--;  // Proceed with pop only if not empty
}

    // int peek(){
    //     if(isEmpty()){
    //         cout<<"Nothing to peek"<<endl; //kch return karana zaruri hai kyuke ye void type function nai hein
    //     }
    //     return arr[top];
    // }
    int peek() {
    if (isEmpty()) {
        cout << "Nothing to peek" << endl;
        return -1;  // Return a sentinel value when the stack is empty
    }
    return arr[top];  // Return top element
}

    void clear(){
       top=-1;
       cout<<"Stack Cleared";
    }
};

int main() {
    Stack s1(3);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << "Top Element: " << s1.peek() << endl;
    s1.push(4);  // Should show overflow error
    s1.pop();
    s1.pop();
    cout << "Top Element: " << s1.peek() << endl;
    s1.clear();
    return 0;
}
