#include<iostream>
using namespace std;
class Node{
public:
    int id;
    char name[30];
    int orders;
    Node* next;
    Node(int i , char n[] , int o){
        id = i;
        orders = o;
        int j = 0;
        while(n[j] != '\0'){
            name[j] = n[j];
            j++;
        }
        name[j] = '\0';
        next = NULL;
    }
};
class circ_linked_list{
public:
    Node* head;
    Node* tail;
    circ_linked_list(){
        head = NULL;
        tail = NULL;
    }
    int count(){
        if(head == NULL){
            return 0;
        }
        int count = 0;
        Node* temp = head;
        do{
            count++;
            temp=temp->next;
        }
        while(temp != head);
        return count;
    }
    void insert_at_b(int id , char name[] , int orders){
        Node* n = new Node(id , name , orders);
        if(head == NULL){
            head = tail = n;
            tail->next = head;
        }
        else{
            n->next = head;
            head = n;
            tail->next = head;
        }
    }
    void insert_at_e(int id , char name[] , int orders){
        Node* n = new Node(id , name , orders);
        if(head == NULL){
            head = tail= n;
            tail->next = head;
        }
        else{
            tail->next =n;
            tail = n;
            tail->next =head;
        }
    }
    void insert_at(int pos , int id , char name[] , int orders){
        if(pos < 0 || pos > count()){
            cout<<"invalid"<< endl;
            return;
        }
        if(pos == 0){
            insert_at_b(id , name , orders);
            return;
        }
        if(pos == count()){
            insert_at_e(id , name , orders);
            return;
        }
        Node* n =new Node(id , name , orders);
        Node* temp =head;
        for(int i = 0 ; i<pos-1 ; i++){
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next= n;
    }

    void delete_beginning(){
        if(head ==NULL){
            cout<<"empty"<<endl;
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = head;
            head =head->next;
            tail->next = head;
            delete temp;
        }
    }
    void delete_end(){
        if(head == NULL){
            cout<<"empty"<<endl;
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = head;}
    void delete_at(int pos){
        if(pos < 0 || pos >= count()){
            cout<<"invalid"<<endl;
            return;
        }
        if(pos == 0){
            delete_beginning();
            return;
        }
        if(pos == count()-1){
            delete_end();
            return;
        }
        Node* temp = head;

        for(int i=0 ; i<pos-1 ; i++){
            temp= temp->next;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
    void search(int id){
        if(head == NULL){
            cout<<"list is empty"<<endl;
            return;
        }
        Node* temp = head;

        do{
            if(temp->id == id){
                cout<<"rider found"<<endl;
                cout<<"name:"<<temp->name<<endl;
                cout<<"orders:"<<temp->orders<<endl;
                return;
            }
            temp = temp->next;
        }
        while(temp != head);
        cout<<"rider not found"<<endl;
    }
    void update(int id , int orders){
        if(head == NULL){
            return;
        }
        Node* temp = head;

        do{
            if(temp->id == id){
                temp->orders = orders;
                cout<<"updated"<<endl;
                return;
            }
            temp = temp->next;
        }
        while(temp != head);
        cout<<"rider not found"<<endl;
    }
    void display(){
        if(head == NULL){
            cout<<"list is empty"<<endl;
            return;
        }
        Node* temp = head;
        do{
            cout<<temp->id<<" "<<temp->name<<" "<<temp->orders<<endl;
            temp= temp->next;
        }
        while(temp != head);
    }
    void traverse(int id){

        Node* temp = head;

        if(head == NULL){
            return;
        }
        do{
            if(temp->id == id){
                Node* start= temp;
                do{
                    cout<<temp->name<<" ";
                    temp = temp->next;
                }
                while(temp != start);
                cout<<endl;
                return;
            }
            temp = temp->next;
        }
        while(temp != head);
        cout<<"rider not found"<<endl;
    }
};

int main(){

    circ_linked_list riders;

    char n1[] = "Ali";
    char n2[] = "Ahmed";
    char n3[] = "Sara";

    riders.insert_end(1 , n1 , 5);
    riders.insert_end(2 , n2 , 3);
    riders.insert_beginning(3 , n3 , 7);
    riders.display();
    cout<<"total riders: "<<riders.count()<<endl;
    riders.search(2);
    riders.update(2 , 10);
    riders.display();
}
