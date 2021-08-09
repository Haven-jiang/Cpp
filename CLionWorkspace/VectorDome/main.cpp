#include <iostream>
#include <vector>
using namespace std;

int main() {
    double values[] = {1, 2, 3, 4, 5, 6, 7};
    //Creat a new vector, using between iterator [ben, end) elements to initialization this vector
    vector<double> doubleVector {values, values+7};
    cout << "Initial contents in doubleVector: ";
    for (double i : doubleVector){
        cout << i << "\t";
    }

    //Function assign(n, elem) in sequential container can push number n values in this container
    doubleVector.assign(4, 11.5);

    cout << endl << "After the assign function, doubleVector: ";
    for(double i : doubleVector) cout << i << "\t";

    //Function at(index) in vector/deque can return a value in location(index)
    doubleVector.at(0) = 22.4;
    cout << endl << "After the at function, doubleVector: ";
    for(double i : doubleVector) cout << i << "\t";

    //Define a iterator, using it pointed vector's first values
    auto itr = doubleVector.begin();
    doubleVector.insert(itr+1, 555);
    itr = doubleVector.begin();
    
    doubleVector.erase(itr + 2, itr + 4);
    
    cout << endl << "After the erase function, doubleVector: ";
    for (double i : doubleVector){
        cout << i << "\t";
    }
    
    doubleVector.clear();
    cout << endl << "Size is " << doubleVector.size() << endl;
    cout << "Is empty? " << (doubleVector.empty() ? "true" : "false") << endl;
    
    return 0;
}