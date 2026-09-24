#include<iostream>
using namespace std;
class Combatant{
public:
    char name[30];
    int health;
    int attack;
    Combatant(char n[] , int h , int a){
        int i = 0;

        while(n[i] != '\0'){
            name[i] = n[i];
            i++;
        }

        name[i] = '\0';
        health = h;
        attack = a;
    }
};

class Node{
public:
    Combatant* data;
    Node* next;
    Node* prev;

    Node(Combatant* c){
        data = c;
        next = NULL;
        prev = NULL;
    }
};

class Team{
public:
    Node* head;
    Node* tail;
    Team(){
        head = NULL;
        tail = NULL;
    }

    void insert(Combatant* c){
        Node* n = new Node(c);

        if(head == NULL){
            head = tail = n;
        }
        else{
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    Node* get(int pos){
        Node* temp = head;

        for(int i = 1 ; i<pos && temp != NULL ; i++){
            temp = temp->next;
        }
        return temp;
    }

    void remove(Node* del){

        if(del == NULL){
            return;}

        elseif(del == head){
            head =head->next;
        }
        elseif(del == tail){
            tail= tail->prev;
        }

        elseif(del->prev != NULL){
            del->prev->next = del->next;}

        elseif(del->next != NULL){
            del->next->prev = del->prev;}

        delete del->data;
        delete del;
    }

    bool empty(){
        return head == NULL; }

    int total_health(){
        int total = 0;
        Node* temp = head;

        while(temp != NULL){
            total += temp->data->health;
            temp = temp->next;
        }

        return total;
    }

    void display_names(){

        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data->name<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){

            cout<<temp->data->name<<" HP: "<<temp->data->health<<" Attack: "<<temp->data->attack<<endl;
            temp = temp->next;
        }
    }
};

