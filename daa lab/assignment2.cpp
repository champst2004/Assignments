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

            stack<int> s;
            s.push(start);
            visited[start] = 1;

            do {
                int current = s.top();
                s.pop();
                cout << head[current]->name << "[" << current << "]\n";
                gNode *temp = head[current]->next;
                while(temp != nullptr){
                    if(!visited[temp->id]){
                        s.push(temp->id);
                        visited[temp->id] = 1;
                    }
                    temp = temp->next;
                }
            } while(!s.empty());
        }

        void bfs(){
            for(int i = 0; i < n; i++) visited[i] = 0;
            int start;
            cout << "Enter starting vertex ID: ";
            cin >> start;
            
            queue<int> q;
            q.push(start);
            visited[start] = 1;

           do {
                int current = q.front();
                q.pop();
                cout << head[current]->name << "[" << current << "]\n";
                gNode *temp = head[current]->next;
                while(temp != nullptr){
                    if(!visited[temp->id]){
                        q.push(temp->id);
                        visited[temp->id] = 1;
                    }
                    temp = temp ->next;
                }
            } while(!q.empty());
        }
};

int main(){
    graph g;
    int ch;
    while(1){
        cout << "1. Accept friends\n2. Display network\n3. DFS (Recusrive)\n4. DFS (Non Recusrive)\n5. BFS\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
            case 1:
                g.accept();
                break;
            case 2:
                g.display();
                break;
            case 3:
                g.dfsR();
                break;
            case 4:
                g.dfsNR();
                break;
            case 5:
                g.bfs();
                break;
            case 6:
                cout << "Thank You!";
                return 0;
        }
    }
}