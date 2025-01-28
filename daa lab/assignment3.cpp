#include <iostream>
using namespace std;

class graph{
    int cities;
    int cost[10][10];
    public:
        graph(){
            cout << "Enter no. of cities: ";
            cin >> cities;
            for(int i = 0; i < cities; i++){
                for(int j = 0; j < cities; j++){
                    cost[i][j] = 999; 
                }
            }
        }

        void accept(){
            for(int i = 0; i < cities; i++){
                for(int j = 0; j < cities; j++){
                    cout << "Cost [" << i << "][" << j << "]: ";
                    cin >> cost[i][j]; 
                }
            }
        }

        void display(){
            cout <<  "The adjacency matrix is: \n";
            for(int i = 0; i < cities; i++){
                for(int j = 0; j < cities; j++){
                    cout << cost[i][j] << "\t";
                }
                cout << endl;
            }
        }

        void primsAlgorithm(){

        }
};

int main(){
    graph g;
    int ch;
    while(1){
        cout << "1. Accept matrix\n2. Display matrix\n3. Find MST\n4. Exit\n";
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
                g.primsAlgorithm();
                break;
            case 4:
                cout << "Thank You!";
                return 0;
        }
    }
}