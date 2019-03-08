//
//  Stack.hpp
//  Rabbit_Cheetah
//
//  Created by Andrea Fiorucci on 15/02/2016.
//
//

#ifndef Stack_hpp
#define Stack_hpp

#include "ofMain.h"

template <class S> class Stack // class Stack
{
    int size,top; // size and top of the stack
    S *s_ptr; // pointer of type template
    
public:
    
    Stack(int); // constructor
    ~Stack()//destructor
    {delete s_ptr;  // delete and set to null s_ptr
    s_ptr = nullptr;}
    void push(S val); // push values
    S pop(); // pop values
    bool isfull(); // check if full
    bool isempty(); // check if empty
    int get_top(); // get top
    void setTop(int x); // set top
    
};

template<class S>Stack<S>:: Stack(int x): // initialise the stack

    size(x), // size
    top(-1), // top = -1
    s_ptr(new S[size]) // new Template
{}

template <class S>
void Stack<S>:: push(S val) // push values if not full
{
    if(!isfull())
    {
        
        s_ptr[++top]=val;
    }
    else
    {
        cout<<"stack is full"<<endl; // if full print full
    }
}

template<class S> // pop values
S Stack<S>::pop()
{
    if(!isempty()) // if not empty pop values
    {
        return s_ptr[top--];
    }
    else
    {
        cout<<"Stack is empty"; // if empty print empty
    }
    
    
}

template<class S> int Stack<S>::get_top() // return top
{
    return top;
    
    
}

template<class S> void Stack<S>::setTop(int x) // set top
{
    top = x;
    
    
}

template<class S>
bool Stack<S>:: isfull() // check if full
{
    return top==size-1; // if top = size-1 it is full
}

template<class S> // check if empty
bool Stack<S>:: isempty()
{
    return top==-1; // if top = -1, starting point, the stack is empty 
}




#endif /* Stack_hpp */
