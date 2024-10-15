//PRN: 1032233447
//Name: Shivank Tripathi
#include <iostream>
using namespace std;
#define max 20

template <class T>
class bubble{
   public:
       T arr[max];
       int n;
       void getData(){
           cout << "Enter no of elements: ";
           cin >> n;

           for(int i = 0; i < n; i++){
               cout << "Element " << i + 1 << ": ";
               cin >> arr[i];
           }
       }
       void sort(){
           for(int i = 0; i < n; i++){
               for(int j = 0; j < n - 1; j++){
                   if(arr[j] > arr[j + 1]){
                       swap(arr[j], arr[j + 1]);
                   }
               }
           }
       }
       void display(){
           cout << "Sorted Array: ";
           for(int i = 0; i < n; i++){
               cout << arr[i] << "  ";
           }
           cout << endl;
       }
};

int main(){
   cout << "Sorting integer array" << endl;

   bubble <int> a;
   a.getData();
   a.sort();
   a.display();
  
   cout << "Sorting float array" << endl;
   bubble <float> b;
   b.getData();
   b.sort();
   b.display();

   return 0;  
}
