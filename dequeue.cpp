#include <iostream>
using namespace std;

class Stack {
   protected:
      int top=-1;
      int MAX = 1000;
      int stack[1000];
   
   public:
      void push(int val) {
        if(top>=MAX-1)
            cout<<"Stack Overflow"<<endl; 
        else {
            top++;
            stack[top]=val;
        }
      }

      int pop() {
        if(top<=-1) {
            cout<<"Stack Underflow"<<endl;
            return 0;
        } else {
            cout<<"The popped element is "<< stack[top] <<endl;
            return stack[top];
            top--;
        }
      }

      void display() {
        if(top>=0) {
            cout<<"Stack elements are:";
            for(int i=top; i>=0; i--)
                cout<<stack[i]<<" ";
                cout<<endl;
        } else
            cout<<"Stack is empty";
      }

      int get(int i) {
          return stack[i];
      }

      int getMax() {
          return MAX;
      }

      int getTop() {
          return top;
      }

      int getSize() {
          return (top + 1);
      }

      int isEmpty() {
          if(top<=-1) return 1;
          return 0;
      }
};

class Dequeue {
   protected:
    Stack FirstStack;
    Stack EndStack;
   
   public:
      void addFirst(int val) {
        if(FirstStack.getTop()>=FirstStack.getMax()-1)
            cout<<"Stack Overflow"<<endl; 
        else {
            FirstStack.push(val);
        }
      }

      void addEnd(int val) {
        if(EndStack.getTop()>=EndStack.getMax()-1)
            cout<<"Stack Overflow"<<endl; 
        else {
            EndStack.push(val);
        }
      }

      int delFirst() {
        if (FirstStack.isEmpty()) {
            while (!EndStack.isEmpty()) {
                FirstStack.push(EndStack.pop());
            }
            return FirstStack.pop();
        }
        return FirstStack.pop();
      }

      int delEnd() {
        if (EndStack.isEmpty()) {
            while (!FirstStack.isEmpty()) {
                EndStack.push(FirstStack.pop());
            }
            return EndStack.pop();
        }
        return EndStack.pop();
      }

      int get(int i) {
        if (i < EndStack.getSize()) {
            int result = EndStack.get(EndStack.getSize() - i - 1);
            cout<<result;
            return result;
        } else {
            int result = FirstStack.get(i - EndStack.getSize());
            cout<<result;
            return result;
        }
      }

      void display() {
        for(int i=0; i<(EndStack.getSize() + FirstStack.getSize()); i++) {
            if (EndStack.getSize() > i) {
                cout<<EndStack.get(EndStack.getSize() - i - 1)<<" ";
            } else  {
                cout<<FirstStack.get(i - EndStack.getSize())<<" ";
            }
        }
        cout<<endl;
      }
};

int main(void) {
   Dequeue x;
 
   x.addFirst(1);
   x.addFirst(2);
   x.addFirst(3);
   x.addFirst(4);
   x.addEnd(5);
   x.addEnd(6);
   x.addEnd(7);

   x.display();
   
   return 0;
}
