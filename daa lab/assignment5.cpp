#include <iostream>
#include <fstream>
using namespace std;

class record{
    int rollno, marks;
    string name;
    friend class student;
};

class hashing{
    int rollno, pos;
    public:
        hashing(){
            rollno = -1;
            pos = -1;
        }
        friend class student;
};

class student{
    record rec;
    hashing h[10];
    int s, relt;
    public:
        student(){
            s = sizeof(record);
            for(int i = 0; i < 10; i++){
                h[i].rollno = -1;
                h[i].pos = -1;
            }
            relt = 0;
        }

        void createWithoutReplacement(){

        }

        void createWithReplacement(){

        }

        void modify(){

        }

        void retrive(){

        }

        void del(){

        }

        void display(){

        }

        void displayAll(){

        }
};

int main(){
    int ch;
    student s;
    while(1){
        cout << "1. Create by chaining without replacement\n2. Create by chaining with replacement\n";
        cout << "3. Retrive\n4. Modify\n5. Delete\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                cout << "Thank You!";
                return 0;
        }
    }
}