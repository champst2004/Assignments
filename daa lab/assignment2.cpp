#include <iostream>
using namespace std;

class gNode{
    int id;
    string name;
    gNode *next;
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
                cout << "Enter name of user " << i + 1;
                cin >> head[i]->name;
                cout << "Enter ID of user " << i + 1;
                cin >> head[i]->id;
                head[i]->next = nullptr;
            }
        }
        
};

int main(){
    
    return 0;
}