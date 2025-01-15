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


        int visited[20] = {0};
        void dfs(){
            int start;
            for(int i = 0; i < n; i++){
                cout << "Enter startig vertex: ";
                cin >> start;
                dfs(start);
            }
        }
        void dfs(int n){
            gNode *temp = head[n];
            cout << n;
            visited[n] = 1;
            while(temp->next != nullptr){
                if(!visited[temp->id]){
                    dfs(temp->id);
                }
            }            
        }
};

int main(){
    graph g;
    g.accept();
    g.display();
    g.dfs();
    return 0;
}
