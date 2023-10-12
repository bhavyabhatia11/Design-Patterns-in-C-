#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

// observer Interface
class Subscriber {
    public:
        string name;
        virtual void update() = 0;
};

// Observable Interface 
class StockObservable{
    public:
        string name = "Stock";
        virtual void add(Subscriber* s) = 0;
        virtual void remove(Subscriber* s) = 0;
        virtual void notify() = 0;
        virtual void setStockCount(int newStockAdded) = 0;
        virtual int getStockCount() = 0;
        virtual string getName() = 0;
};

// Observable Concrete Class
class IphoneObservable : public StockObservable {
    vector<Subscriber*> subscribers;
    int stockCount = 0;
    string name = "Iphone";

    public:
    void add(Subscriber* s) {
        subscribers.push_back(s);
        cout << "Subscriber " << s->name << " is added!" << endl;
    }

    void remove(Subscriber* s) {
        // Find and erase the subscriber
        for (auto it = subscribers.begin(); it != subscribers.end(); ++it) {
            if (*it == s) {
                subscribers.erase(it);
                cout << "Subscriber " << s->name << " is removed!" << endl;
                break;
            }
        }
    }

    void notify() {
        for (int i = 0; i < subscribers.size(); i++) {
            subscribers[i]->update();
        }
    }

    void setStockCount(int newStock) {
        if (stockCount != 0) {
            notify();
        }
        stockCount = newStock;
    }

    int getStockCount() {
        return stockCount;
    }

    string getName() {
        return name;
    }
}; 

// observer concrete class
class MobileSubscriber : public Subscriber {
    string phoneNum;
    string name;
    StockObservable* productStock;
    public: 
        MobileSubscriber(string name, string phoneNum, StockObservable* productStock){
            this->name = name;
            this->phoneNum = phoneNum;
            this->productStock = productStock;
        }

        void update(){
            cout << "Hey, " << productStock->getName() << "is back in stock." <<  productStock->getStockCount() << "units left!" << endl;
        }
};

class EmailSubscriber : public Subscriber {
    string email;
    string name;
    StockObservable* productStock;
    public: 
        EmailSubscriber(string name, string email, StockObservable* productStock){
            this->name = name;
            this->email = email;
            this->productStock = productStock;
        }

        void update(){
            cout << "Hey, " << productStock->getName() << "is back in stock." <<  productStock->getStockCount() << "units left!" << endl;
        }
         
};

int main(){

    StockObservable* Iphone = new IphoneObservable();

    Subscriber* u1 = new MobileSubscriber("Bhavya", "730035007", Iphone);
    Subscriber* u2 = new MobileSubscriber("Sahil", "730036007", Iphone);
    Subscriber* u3 = new EmailSubscriber("Sunil", "sunil@gmail.com", Iphone);
    Subscriber* u4 = new EmailSubscriber("Komal", "komal@gmail.com", Iphone);
    
    Iphone->setStockCount(30);

    Iphone->setStockCount(0);

    Iphone->setStockCount(24);

    Iphone->setStockCount(45);

    delete u1;
    delete u2;
    delete u3;
    delete u4;
    delete Iphone;

    return 0;
}