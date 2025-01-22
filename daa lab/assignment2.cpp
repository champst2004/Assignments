#include <iostream>
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

class stack{
    int stack[20];
    int top = -1;
    friend class graph;
    public:
        void push(int v){
            stack[++top] = v;
        }
        int pop(){
            return stack[top--];
        }
        bool isEmpty(){
            return top == -1;
        }
};

class queue{
    int queue[20];
    int front = -1;
    int rear = -1;
    friend class graph;
    public:
        void enq(int v){
            queue[++rear] = v;
        }
        int dq(){
            return queue[++front];
        }
        bool isEmpty(){
            return front == rear;
        }
};

class graph{
    gNode *head[20];
    int n;
    public:
        int visited[20];
        graph(){
            cout << "Enter no. of vertices: ";
            cin >> n;
            for(int i = 0; i < n; i++){
                head[i] = new gNode;
                cout << "Enter name of user " << i << ": ";
                cin >> head[i]->name;
                head[i]->id = i;
                head[i]->next = nullptr;
            }
        }
        void accept(){
            for(int i = 0; i < n; i++){
                gNode *temp = head[i];
                cout << head[i]->name << " [ID = " << head[i]->id << "]";
                cout << endl;
            }
            for(int i = 0; i < n; i++){
                gNode *temp = head[i];
                char choice;
                do{
                    int ID;
                    cout << "Enter ID of " << head[i]->name << "'s friend: ";
                    cin >> ID;
                    if(ID == i) cout << "Self loop not allowed\n";
                    else{
                        gNode *curr = new gNode;
                        curr->id = ID;
                        curr->name = head[ID]->name;
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

        void dfsR(int v){
            cout << head[v]->name << "[" << v << "]\n";
            visited[v] = 1;
            gNode *temp = head[v]->next;
            while(temp != nullptr){
                int w = temp->id;
                if(!visited[temp->id]) dfsR(temp->id);
                temp = temp->next;
            }
        }

        void dfsR(){
            for(int i = 0; i < 20; i++) visited[i] = 0;
            int start;
            cout << "Enter starting vertex ID: ";
            cin >> start;
            dfsR(start);
        }

        void dfsNR(){
            for(int i = 0; i < n; i++) visited[i] = 0;
            int start;
            cout << "Enter starting vertex ID: ";
            cin >> start;

            stack s;
            s.push(start);
            visited[start] = 1;

            do {
                int curr = s.pop();
                cout << head[curr]->name << "[" << curr << "]\n";
                gNode *temp = head[curr]->next;
                while(temp != nullptr){
                    if(!visited[temp->id]){
                        s.push(temp->id);
                        visited[temp->id] = 1;
                    }
                    temp = temp->next;
                }
            } while(!s.isEmpty());
        }

        void bfs(){
            for(int i = 0; i < n; i++) visited[i] = 0;
            int start;
            cout << "Enter starting vertex ID: ";
            cin >> start;

            queue q;
            q.enq(start);
            visited[start] = 1;

            do {
                int curr = q.dq();
                cout << head[curr]->name << "[" << curr << "]\n";
                gNode *temp = head[curr]->next;
                while(temp != nullptr){
                    if(!visited[temp->id]){
                        q.enq(temp->id);
                        visited[temp->id] = 1;
                    }
                    temp = temp->next;
                }
            } while(!q.isEmpty());

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