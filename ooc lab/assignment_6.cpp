#include <iostream>
#include <fstream>
using namespace std;

static int upperCase, letter, digits, spaces, vowels;
void check(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        upperCase++;
    }
    if(ch >= '0' && ch <= '9'){
        digits++;
    }
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        vowels++;
    }
    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
        vowels++;
    }
    if(ch == ' '){
        spaces++;
    }
}

int main(){
    ifstream inp("book.txt");
    ofstream out("dest.txt");
    while(!inp.eof()){
        check(inp.get());
        letter++;
    }
    out << "The no. of Uppercase letters are " << upperCase << endl;
    out << "The no. of letters are " << letter << endl;
    out << "The no. of digits letters are " << digits << endl;
    out << "The no. of spaces letters are " << spaces << endl;
    out << "The no. of vowels letters are " << vowels << endl;
    inp.close();
    out.close();
    return 0;
}