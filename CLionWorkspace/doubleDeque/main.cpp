#include <deque>
#include <iostream>
using namespace std;

int main(){
    double values[] = {1, 2, 3, 4, 5, 6, 7,};
    deque<double> doubleDeque(values, values + 7);
    cout << "Initial contents in doubleDeque: ";
    for (int i = 0; i < doubleDeque.size(); i++) cout << doubleDeque[i] << " ";
    
    doubleDeque.assign(4, 11.5);
    cout << endl << "After assign: ";
    for (int i = 0; i < doubleDeque.size(); i++) cout << doubleDeque[i] << " ";
    
    doubleDeque.at(0) = 22.4;
    cout << endl << "After at(): ";
    for (int i = 0; i < doubleDeque.size(); i++) cout << doubleDeque[i] << " ";
    
    deque<double>::iterator itr = doubleDeque.begin();
    doubleDeque.insert(itr + 1, 555);
    
    itr = doubleDeque.begin();
    doubleDeque.insert(itr + 1, 666);
    
    cout << endl << "After insert: ";
    for (int i = 0; i < doubleDeque.size(); i++) cout << doubleDeque[i] << " ";
    
    doubleDeque.erase(itr+2, itr+4);
    cout << endl << "After erase: ";
    for (int i = 0; i < doubleDeque.size(); i++) cout <<doubleDeque[i] << " ";
    
    doubleDeque.clear();
    cout << endl << "After clear: ";
    cout << "Size is " << doubleDeque.size() << endl;\
    cout << "Is empty? " << (doubleDeque.empty() ? "true" : "false") << endl;
    
    doubleDeque.push_front(10.10);
    //push in front
    doubleDeque.push_front(20.22);
    doubleDeque.push_back(30.33);
    //push in back
    cout << "After push_front: ";
    for (int i = 0; i < doubleDeque.size(); i++) cout << doubleDeque[i] << " ";
    
    doubleDeque.pop_front();
    //pop on front
    doubleDeque.pop_back();
    cout << endl << "After pop: ";
    for (int i = 0; i < doubleDeque.size(); i++) cout << doubleDeque[i] << " ";
    return 0;
}