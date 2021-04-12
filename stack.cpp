#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack() {
  st=NULL;
  size1=0;
}
Stack::Stack(const Stack& b) {
    size1=b.size1;
    st=new int[size1];
    for(int i=0;i<size1;++i) {
    st[i]=b.st[i];
    }
}
void Stack::push(int elem) {
  int*temp_stack=new int[size1];
  for(int i=0;i<size1;++i) {
    temp_stack[i]=st[i];
  }
  delete[]st;
  ++size1;
  st=new int[size1];
  for(int i=0;i<size1-1;++i) {
    st[i]=temp_stack[i];
  }
  delete[]temp_stack;
  st[size1-1]=elem;
}
int Stack::pop() {
  if(!isEmpty()) {
    int elem=st[size1-1];
    --size1;
    int*temp_stack=new int[size1];
    for(int i=0;i<size1;++i) {
      temp_stack[i]=st[i];
    }
    delete st;
    st= new int[size1];
    for(int i=0;i<size1;++i) {
      st[i] = temp_stack[i];
    }
    delete[] temp_stack;
    return elem;
  }
}
void Stack::multiPop(int N) {
  if(!isEmpty()) {
    size1-=N;
    int*temp_stack=new int[size1];
    for(int i=0;i<size1;++i) {
      temp_stack[i]=st[i];
    }
    delete[]st;
    st=new int[size1];
    for(int i=0;i<size1;++i) {
      st[i]=temp_stack[i];
    }
    delete[] temp_stack;
  }
}
bool Stack::isEmpty() {
  if(st==NULL) {
    return true;
  } else {
    return false;
  }
}
void Stack::show() {
  for(int i=0;i<size1;++i) {
    cout<<st[i];
    if(i<size1-1) {
        cout<<" ";
    }
  }
  cout<<endl;
}
Stack::~Stack() {
  delete[]st;
}
Stack& Stack::operator=(const Stack& b) {
  if(this==&b) {
    return*this;
  }
  size1=b.size1;
  st=new int[size1];
  for(int i=0;i<size1;++i) {
    st[i]=b.st[i];
  }
  return*this;
}
