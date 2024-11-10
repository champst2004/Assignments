#include <iostream>
#include <fstream>

using namespace std;

int uppCase = 0;
int letter = 0;
int digit = 0;
int whSpace = 0;
int vowel = 0;

void count(char a){
	if ( a >= 'A' && a <= 'Z' ){
		uppCase++;
	}
	if ( (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') ){
		letter++;
	}
	if ( a >= '0' && a <= '9' ){
		digit++;
	}
	if ( a == ' ' ){
		whSpace++;
	}
	if ( a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' ){
		vowel++;
	}
}

int main(){
	ifstream file("book.txt");
	while(!file.eof()){
		count(file.get());
	}
	file.close();
	
	ofstream hehe("dest.txt");
	hehe << "The number of Upper case characters is : " << uppCase << endl;
	hehe << "The number Letters is : " << letter << endl;
	hehe << "The number of digits is : " << digit << endl;
	hehe << "The number of White spaces is : " << whSpace << endl;
	hehe << "The number of vowels is : " << vowel << endl;
	hehe.close();
	return 0;
}
