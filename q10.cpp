#include<iostream>
using namespace std;
class Player{
public:
    int id;
    int energy;
    char history[100];
    int top;
    bool active;
    Player(){
        id = 0;
        energy = 100;
        top = -1;
        active = true;
    }

    void push(char c){
        top++;
        history[top] = c;
    }

    bool empty(){
        if(top == -1){
            return true;
        }

        return false;
    }

    char pop(){

        char c = history[top];
        top--;
        return c;
    }
};

class Game{
public:

    Player players[100];

    int n;
    int eliminated[100];
    int eliminated_count;

    int front;

    void input(){

        cout<<"enter number of players: ";
        cin>>n;

        for(int i = 0 ; i<n ; i++){

            cout<<"enter player id: ";
            cin>>players[i].id;

            players[i].energy = 100;
            players[i].top = -1;
            players[i].active = true;
        }

        front = 0;
        eliminated_count = 0;
    }
    void command(int index , char c){

        Player& p = players[index];

        if(c == 'F'){

            p.energy -= 10;
            p.push('F');
        }

        else if(c == 'B'){
            p.push('B');
        }

        else if(c == 'T'){

            p.energy += 20;
            p.push('T');
        }

        else if(c == 'U'){
            if(!p.empty()){

                char old = p.pop();
                if(old == 'F'){
                    p.energy += 10;
                }

                else if(old == 'T'){
                    p.energy -= 20;
                }}
        }

        if(p.energy <= 0){
            p.active = false;
            eliminated[eliminated_count]
                = p.id;

            eliminated_count++;
        }
    }

    void play(){

        int commands;

        cout<<"enter number of commands: ";
        cin>>commands;

        for(int i = 0 ; i<commands ; i++){
            int checked = 0;
            while(checked < n &&
                  players[front].active == false){

                front++;
                if(front == n){
                    front = 0;
                }
                checked++;
            }
            if(checked == n){
                break;
            }
            char c;

            cout<<"player "<<players[front].id<<" command: ";

            cin>>c;
            command(front , c);

            front++;
            if(front == n){
                front = 0;
            }
        }
    }

    void display(){

        cout<<endl;
        cout<<"elimination order: ";
        for(int i = 0 ; i<eliminated_count ; i++){
            cout<<eliminated[i]<<" ";
        }

        cout<<endl;

        for(int i = 0 ; i<n ; i++){

            if(players[i].active){

                cout<<"ID: "<<players[i].id<<" Energy: "<<players[i].energy<<" Undo actions: "<<players[i].top + 1<<endl;
            }
        }
    }
};

int main(){

    Game g;
    g.input();
    g.play();
    g.display();
}
