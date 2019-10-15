#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
  ifstream sourceFile;
  GenStack <char> delimiterStack;
  GenStack <int> lineStack;

  sourceFile.open(argv[1]);
  if(sourceFile.is_open()){
    int count = 1;
    string line;
    while(getline(sourceFile, line)){
      for(int i = 0; i < line.length(); ++i){
        switch(line.at(i)){
          case '(':
          case '{':
          case '[':
            try{
              delimiterStack.push(line.at(i));
              lineStack.push(count);
            } catch (StackException s){ //Only occurs if the stack is full, in which case, a temporary stack and array are created to transfer the values into a larger stack
              char tmpD [delimiterStack.size];
              int tmpL [lineStack.size];
              for(int i = 0; i < delimiterStack.size; ++i){
                tmpD[i] = delimiterStack.pop();
                tmpL[i] = lineStack.pop();
              }
              GenStack<char> newDelimiter(delimiterStack.size * 2);
              GenStack<int> newLine(lineStack.size*2);
              for(int i = 0; i < newDelimiter.size; ++i){
                newDelimiter.push(tmpD[i]);
                newLine.push(tmpL[i]);
              }
              delimiterStack = newDelimiter;
              lineStack = newLine;
            }
            break;
          case ')':
            try{
              if(delimiterStack.peek() == '('){
                delimiterStack.pop();
                lineStack.pop();
              }
            } catch (StackException s){ //Only occurs if stack is empty, in which case, we push the value as an unattached delimiter
              try{
                delimiterStack.push(line.at(i));
                lineStack.push(count);
              } catch (StackException s){
                char tmpD [delimiterStack.size];
                int tmpL [lineStack.size];
                for(int i = 0; i < delimiterStack.size; ++i){
                  tmpD[i] = delimiterStack.pop();
                  tmpL[i] = lineStack.pop();
                }
                GenStack<char> newDelimiter(delimiterStack.size * 2);
                GenStack<int> newLine(lineStack.size*2);
                for(int i = 0; i < newDelimiter.size; ++i){
                  newDelimiter.push(tmpD[i]);
                  newLine.push(tmpL[i]);
                }
                delimiterStack = newDelimiter;
                lineStack = newLine;
              }
            }
            break;
          case '}':
          try{
            if(delimiterStack.peek() == '{'){
              delimiterStack.pop();
              lineStack.pop();
            }
          } catch (StackException s){ //Only occurs if stack is empty, in which case, we push the value as an unattached delimiter
            try{
              delimiterStack.push(line.at(i));
              lineStack.push(count);
            } catch (StackException s){
              char tmpD [delimiterStack.size];
              int tmpL [lineStack.size];
              for(int i = 0; i < delimiterStack.size; ++i){
                tmpD[i] = delimiterStack.pop();
                tmpL[i] = lineStack.pop();
              }
              GenStack<char> newDelimiter(delimiterStack.size * 2);
              GenStack<int> newLine(lineStack.size*2);
              for(int i = 0; i < newDelimiter.size; ++i){
                newDelimiter.push(tmpD[i]);
                newLine.push(tmpL[i]);
              }
              delimiterStack = newDelimiter;
              lineStack = newLine;
            }
          }
            break;
          case ']':
            try {
              if(delimiterStack.peek() == '['){
                delimiterStack.pop();
                lineStack.pop();
              }
            } catch (StackException s){ //Only occurs if stack is empty, in which case, we push the value as an unattached delimiter
              try{
                delimiterStack.push(line.at(i));
                lineStack.push(count);
              } catch (StackException s){
                char tmpD [delimiterStack.size];
                int tmpL [lineStack.size];
                for(int i = 0; i < delimiterStack.size; ++i){
                  tmpD[i] = delimiterStack.pop();
                  tmpL[i] = lineStack.pop();
                }
                GenStack<char> newDelimiter(delimiterStack.size * 2);
                GenStack<int> newLine(lineStack.size*2);
                for(int i = 0; i < newDelimiter.size; ++i){
                  newDelimiter.push(tmpD[i]);
                  newLine.push(tmpL[i]);
                }
                delimiterStack = newDelimiter;
                lineStack = newLine;
              }
            }
            break;
          default:
            //Value other than delimiter, so don't need to do anythindg
            break;
        }
      }
      ++count;
    }
  }
  sourceFile.close();
  if(delimiterStack.isEmpty()){ //if the stack has any remaining values after completing iteration, will report the top of the stack as a missing delimiter
    cout << "No missing delimiters!" << endl;
  } else {
    switch(delimiterStack.peek()){
      case '(':
        cout << "Missing an accompanying \")\" to the \"(\" on Line " << lineStack.peek();
        break;
      case ')':
        cout << "Missing an accompanying \"(\" to the \")\" on Line " << lineStack.peek();
        break;
      case '{':
        cout << "Missing an accompanying \"}\" to the \"{\" on Line " << lineStack.peek();
        break;
      case '}':
        cout << "Missing an accompanying \"{\" to the \"}\" on Line " << lineStack.peek();
        break;
      case '[':
        cout << "Missing an accompanying \"(\" to the \")\" on Line " << lineStack.peek();
        break;
      case ']':
        cout << "Missing an accompanying \"[\" to the \"]\" on Line " << lineStack.peek();
        break;
      default:
        break;
    }
  }
  return 0;
}
