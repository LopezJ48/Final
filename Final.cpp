#include <iostream>
#include <ctime>
#include <deque>
#include <vector>
#include <stack>

using namespace std;

struct CoffeeBooth {
    string name;
    string CoffeOrder;
    CoffeeBooth* next;
};
struct Customer{
    string name;
    string order;
};

string getName(){
string names[] = {"Blaine","Brian","Devin","Chris","Cole"};
    return names[rand() % 6];
}
