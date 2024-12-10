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
        delete temp;
    }else{
        cout << "Nothing to serve." << endl;
    }
}

template <typename Queue>
void showQueue(const Queue& q, const string& boothName) {
    cout << boothName << "queue: ";
    for (const auto& customer : q){
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

    serveCoffeeCustomer(coffeeHead, coffeeTail);
    if (rand() % 2 == 0) addToCoffeeBooth(coffeeHead, coffeeTail);

    if (!muffinLine.empty()){
        cout << "Serving: " << muffinLine.front().name << " " << "Order: " << muffinLine.front().order << endl;
        muffinLine.pop_front();
    }else{
        cout << "No one to serve" << endl;
    }
    if (rand() % 2 == 0) muffinLine.push_back({getName(), getMuffin()});

     if (!braceletLine.empty()){
        cout << "Serving: " << braceletLine.front().name << " " << "Order: " << braceletLine.front().order << endl;
        braceletLine.erase(braceletLine.begin());
    }else{
        cout << "No one to serve" << endl;
    }
    if (rand() % 2 == 0) braceletLine.push_back({getName(), getBracelet()});

    if(!gameLine.empty()){
        Customer servedCustomer = gameLine.top();
        gameLine.pop();
        cout << "Serving: " << servedCustomer.name << endl << " ordered " << servedCustomer.order << endl;
    }else{
        cout << "No one to serve" << endl;
    }
    if (rand() % 2 == 0) gameLine.push({getName(), getGame()});

    showQueue(muffinLine, "Muffin Line");
    showQueue(braceletLine, "Bracelet line");
    cout << "Game line: " << gameLine.size() << endl;
    }
    return 0;
 }