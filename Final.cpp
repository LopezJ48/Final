#include <iostream>
#include <ctime>
#include <deque>
#include <vector>
#include <stack>

using namespace std;

struct CoffeeBooth {
    string name;
    string drinks;
    CoffeeBooth* next;
};
struct Customer{
    string name;
    string order;
};

string getName(){
string names[] = {"Blaine","Brian","Devin","Chris","Cole"};
    return names[rand() % 5];
}
string getDrinks(){
string names[] = {"Black","Cream","Expresso","Smoothie","Frappe"};
    return names[rand() % 5];
}
string getMuffin(){
string names[] = {"Muffin","Blueberry","Chocolate","Plain","Mix"};
    return names[rand() % 5];
}
string getBracelet(){
string names[] = {"Red","Blue","Black","green","Cyan"};
    return names[rand() % 5];
}
string getGame() {
    string games[] = {"Eldin Ring", "Minecraft","Cod","Counter Strike", "GTA 6"};
    return games[rand() % 5];
}

void addToCoffeeBooth (CoffeeBooth* & head, CoffeeBooth* & tail) {
    CoffeeBooth* newCustomer = new CoffeeBooth{getName(),getDrinks(), nullptr};
    if(!head) {
        head = tail = newCustomer;
    }
        else {
            tail ->next = newCustomer;
            tail = newCustomer;
        }
    }

void serveCoffeeCustomer(CoffeeBooth* & head, CoffeeBooth* & tail){
    if(head) {
        CoffeeBooth* temp = head;
        cout << "Serving: " << temp ->name << "Order: " << temp ->drinks << endl;
        head = head ->next;
        if (!head) tail = nullptr;
    }else{
        cout << "Nothing to serve." << endl;
    }
}

template <typename queue>
void showQueue(queue& q, string& boothName) {
    cout << boothName << "queue: ";
    for (auto& customer : q){
        cout << customer.name << "Ordered: " << customer.order << "\n";
    }
    cout << endl;
}
 int main () {
    srand(static_cast<unsigned>(time(nullptr)));

    CoffeeBooth* coffeeHead = nullptr;
    CoffeeBooth* coffeeTail = nullptr;
    for (int i = 0; i < 3; ++i) addToCoffeeBooth(coffeeHead, coffeeTail);

    deque<Customer> muffinLine;
    for (int i = 0; i < 3; ++i)muffinLine.push_back({getName(), getMuffin()});

    vector<Customer> braceletLine;
    for (int i = 0; i < 3; ++i)braceletLine.push_back({getName(),getBracelet()});
    stack<Customer> gameLine;
    for (int i = 0; i < 3; ++i)gameLine.push({getName(), getGame()});

    for (int round = 1; round <= 10; ++round){
        cout << "Round: " << round << endl;
    }

    serveCoffeeCustomer(coffeeHead, coffeeTail);
    

    showQueue(muffinLine, "Muffin line");
    showQueue(braceletLine, "braclete line");
 }