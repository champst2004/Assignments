#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class gNode{
    int id;
    string name;
    gNode *next;
    public:
        gNode(){
            id = -1;
            name = "Default";
            next = nullptr;
        }
        friend class graph;
};

class graph{
    gNode *head[20];
    int n;
    public:
        graph(){
            cout << "Enter no. of vertices: ";
            cin >> n;
            for(int i = 0; i < n; i++){
                head[i] = new gNode;
                cout << "Enter name of user " << i + 1 << ": ";
                cin >> head[i]->name;
                head[i]->id = i;
                head[i]->next = nullptr;
            }
        }
        void accept(){
            for(int i = 0; i < n; i++){
                gNode *temp = head[i];
                char choice;
                do{
                    int id;
                    string name;
                    cout << "Enter friend of " << head[i]->name << " : ";
                    cin >> name;
                    cout << "Enter friend's ID: ";
                    cin >> id;
                    if(temp->id == id) cout << "Self loop not allowed\n";
                    else{
                        gNode *curr = new gNode;
                        curr->id = id;
                        curr->name = name;
                        curr->next = nullptr;
                        temp->next = curr;
                        temp = temp->next;
                    }
                    cout << "Would you like to continue (Y/y): ";
                    cin >> choice;
                } while(choice == 'Y' || choice == 'y');
            }
        }
        void display(){
            for(int i = 0; i < n; i++){
                gNode *temp = head[i];
                cout << head[i]->name << "'s friends are: ";
                temp = temp->next;
                while(temp != nullptr){
                    cout << temp->name << "[" << temp->id << "] ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }

        int visited[20];

        void dfsR(){
            for(int i = 0; i < n; i++) visited[i] = 0;
            int start;
            cout << "Enter starting vertex ID: ";
            cin >> start;
            // for(int i = 0; i < 20; i++) cout << visited[i];
            // cout << endl;
            dfsR(start);
        }

        void dfsR(int v){
            cout << head[v]->name << "[" << v << "]\n";
            visited[v] = 1;
            gNode *temp = head[v]->next;
            while(temp != nullptr){
                if(!visited[temp->id]) dfsR(temp->id);
                temp = temp->next;
            }
        }

        void dfsNR(){
            for(int i = 0; i < n; i++) visited[i] = 0;
            int start;
            cout << "Enter starting vertex ID: ";
            cin >> start;

            queue<int> q;
            q.push(start);
            visited[start] = 1;

            while(!q.empty()){
                int current = q.front();
                q.pop();
                cout << head[current]->name << "[" << current << "]\n";

            }
        }

};

int main(){
    graph g;
    int ch;
    while(1){
        cout << "1. Accept ";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
            
        }
    }
    return 0;
}
