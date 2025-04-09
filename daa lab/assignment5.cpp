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
            char choice;
            int loc;
            hashing temp;
            fstream f;
            f.open("student.txt", ios::binary | ios::out);
            do{
                cout << "Enter details\n";
                cout << "Roll No.: ";
                cin >> rec.rollno;
                cout << "Name: ";
                cin >> rec.name;
                cout << "Marks: ";
                cin >> rec.marks;
                loc = rec.rollno % 10;
                if(h[loc].rollno == -1){
                    h[loc].rollno = rec.rollno;
                    h[loc].pos = relt;
                    f.write((char*)&rec, s);
                    relt++;
                }
                else{
                    for(int i = 1; i < 10; i++){
                        loc = (loc + 1) % 10;
                        if(h[loc].rollno == -1){
                            h[loc].rollno = rec.rollno;
                            h[loc].pos = relt;
                            f.write((char*)&rec, s);
                            relt++;
                            break;
                        }
                    }
                }
                cout << "Do you want to continue? ";
                cin >> choice;
            } while(choice == 'Y' || choice == 'y');
            f.close();
        }

        void createWithReplacement(){
            char choice;
            int nloc, loc;
            hashing temp;
            fstream f;
            f.open("student.txt", ios::binary | ios::out);
            do{
                cout << "Enter details\n";
                cout << "Roll No.: ";
                cin >> rec.rollno;
                cout << "Name: ";
                cin >> rec.name;
                cout << "Marks: ";
                cin >> rec.marks;
                loc = rec.rollno % 10;
                if(h[loc].rollno == -1){
                    h[loc].rollno = rec.rollno;
                    h[loc].pos = relt;
                    f.write((char*)&rec, s);
                    relt++;
                }
                else{
                    temp.rollno = rec.rollno;
                    temp.pos = relt;
                    f.write((char*)&rec,s);
                    relt++;
                    if(loc != (h[loc].rollno % 10)){
                        temp.rollno = h[loc].rollno;
                        temp.pos = h[loc].pos;
                        h[loc].rollno = rec.rollno;
                        h[loc].pos = relt - 1;
                    }
                    nloc = (loc + 1) % 10;
                    while(nloc != loc){
                        if(h[nloc].rollno == -1){
                            h[nloc].rollno = temp.rollno;
                            h[nloc].pos = temp.pos;
                            break;
                        }
                        nloc = (nloc + 1) % 10;
                    }
                }
                cout << "Do you want to continue? ";
                cin >> choice;
            } while(choice == 'Y' || choice == 'y');
            f.close();
        } 

        void retrive(){
            fstream f;
            f.open("student.txt", ios::binary | ios::in);
            cout << "Enter the rollno you want to retieve: ";
            cin >> rec.rollno;
            int loc = rec.rollno % 10;
            int i;
            for(int i = 1; i < 10; i++){
                if(h[loc].rollno == rec.rollno){
                    int p = h[loc].pos * s;
                    f.seekg(p, ios::beg);
                    f.read((char*)&rec, s);
                    display();
                    break;
                }
                else{
                    loc = (loc + 1) % 10;
                }
            }
            if(i > 10) cout << "Record does not exist\n";
            f.close();
        }

        void display(){
            cout << rec.rollno << "\t\t\t" << rec.name << "\t\t" << rec.marks << endl;
        }

        void displayAll(){
            cout << "Hash table\n";
            cout << "Roll No.\tPosition\n";
            for(int i = 0; i < 10; i++){
                cout << h[i].rollno << "\t\t" << h[i].pos << endl;
            }
            fstream f;
            f.open("student.txt", ios::binary | ios::in);
            cout << "Roll No.\t\tName\t\tMarks\n";
            for(int i = 0; i < 10; i++){
                if(h[i].rollno != -1){
                    int p = h[i].pos * s;
                    f.seekg(p, ios::beg);
                    f.read((char*)&rec, s);
                    display();
                }
            }
            f.close();
        }
};

int main(){
    int ch;
    student s;
    while(1){
        cout << "1. Create by chaining without replacement\n2. Create by chaining with replacement\n";
        cout << "3. Retrive\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
            case 1:
                s.createWithoutReplacement();
                break;
            case 2:
                s.createWithReplacement();
                break;
            case 3:
                s.retrive();
                break;
            case 4:
                s.displayAll();
                break;
            case 5:
                cout << "Thank You!";
                return 0;
        }
    }
}