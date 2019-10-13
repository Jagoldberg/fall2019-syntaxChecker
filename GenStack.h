#include <iostream>

using namespace std;

template <typename E>
class GenStack
{
  public:
    GenStack(); //constructor
    GenStack(int maxSize); // overloaded constructor
    ~GenStack(); //destructor

    void push(E d);
    E pop();
    E peek(); //AKA top()

    bool isFull();
    bool isEmpty();

    int size;
    int top;

    E *myArray;
};

GenStack::GenStack()//default constructor
{
  //Initilization of default values
  myArray = new char[128];
  size = 128;
  top = -1;
}

GenStack::GenStack(int maxSize)
{
  myArray = new char[maxSize];
  size = maxSize;
  top = -1;
}

GenStack::~GenStack()
{
  //lets build some character
  //your job to research this
}

void GenStack::push(E d)
{
  //need to check error/boundary check
  //this is your job
  if (!isFull){
    myArray[++top] = d;
  } else {
    throw Exception("")
  }
}

E GenStack::pop(){
  //error checking, make sure its not isEmpty
  if(!isEmpty()){
    return myArray[top--];
  } else {
    throw Exception("Stack is empty, nothing to return");
  }

}

E GenStack::peek()
{
  //check if empty
  if(!isEmpty()){
    return myArray[top];
  } else {
    throw Exception("Stack is empty, nothing to return");
  }
}

bool GenStack::isFull()
{
  return (top == size-1);
}

bool GenStack::isEmpty()
{
  return (top == -1);
}
