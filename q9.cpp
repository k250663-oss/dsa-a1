#include<iostream>
using namespace std;
class Patient{
public:
    int id;
    int severity;
};
class Queue{
public:
    Patient arr[100];
    int front;
    int rear;
    Queue(){
        front = 0;
        rear = -1;
    }
    void enqueue(int id , int severity){

        rear++;
        arr[rear].id = id;
        arr[rear].severity = severity;
    }
    Patient dequeue(){

        Patient temp = arr[front];
        front++;
        return temp;
    }

    bool empty(){
        if(front > rear){
            return true;
        }

        return false; }
    int size(){
        return rear - front + 1;
    }
};
class EmergencyRoom{
public:
    Queue critical;
    Queue serious;
    Queue normal;

    int order[100];
    int treated;

    EmergencyRoom(){
        treated = 0;
    }

    void arrive(int id , int severity){
        if(severity == 1){
            critical.enqueue(id , severity);
        }
        else if(severity == 2){
            serious.enqueue(id , severity);
        }
        else{
            normal.enqueue(id , severity);
        }
    }
    void treat(){
        Patient p;
        if(!critical.empty()){
            p = critical.dequeue();
        }
        else if(!serious.empty()){
            p = serious.dequeue();
        }
        else if(!normal.empty()){
            p = normal.dequeue();
        }
        else{
            cout<<"no patients"<<endl;
            return;
        }

        order[treated] = p.id;

        treated++;

        cout<<"patient "<<p.id<<" treated"<<endl;
    }

    void display(){
        cout<<"treatment order: ";
        for(int i = 0 ; i<treated ; i++){
            cout<<order[i]<<" ";
        }

        cout<<endl;

        cout<<"total treated: "<<treated<<endl;

        cout<<"remaining: "<<critical.size() +serious.size() +normal.size()<<endl;
    }
};

int main(){

    EmergencyRoom e;

    int n;
    cout<<"enter number of operations: ";
    cin>>n;

    for(int i = 0 ; i<n ; i++){
        char c;
        cin>>c;
        if(c == 'A'){
            int id , severity;

            cin>>id>>severity;

            e.arrive(id , severity);
        }

        else if(c == 'T'){

            e.treat();
        }
    }

    e.display();
}
