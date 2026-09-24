#include<iostream>
using namespace std;
class Node{
public:
    char command;
    int old_position;
    Node* next;
    Node(char c , int p){
        command = c;
        old_position = p;
        next = NULL;
    }
};

class Stack{
public:
    Node* top;
    Stack(){
        top = NULL;
    }
    void push(char c , int old_position){
        Node* n = new Node(c , old_position);
        n->next = top;
        top = n;
    }
    bool empty(){
        if(top == NULL){
            return true;
        }
        return false;
    }
    int pop(){

        if(top == NULL){
            return -1;
        }
        Node* temp = top;
        int position = temp->old_position;
        top = top->next;
        delete temp;
        return position;
    }

    void display(){
        Node* temp = top;
        while(temp != NULL){
            cout<<temp->command<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){

    Stack s;
    int n;
    cout<<"enter number of commands: ";
    cin>>n;

    int position = 0;
    int movements = 0;
    int undo = 0;

    for(int i = 0 ; i<n ; i++){
        char command;
        cin>>command;

        if(command == 'R'){
            int old = position;
            position++;
            s.push('R' , old);
            movements++;
        }

        else if(command == 'L'){
            if(position >0){
                int old= position;
                position--;
                s.push('L' , old);

                movements++;
            }
        }

        else if(command == 'J'){

            int old = position;

            position += 2;
            s.push('J' , old);
            movements++;
        }

        else if(command == 'B'){
            if(!s.empty()){

                position = s.pop();
                undo++;
            }
        }
    }

    cout<<"final position: "<<position<<endl;

    s.display();
}
