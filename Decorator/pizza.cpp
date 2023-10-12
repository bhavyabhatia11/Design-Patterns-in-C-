#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// abstract base pizza
class BasePizza{
    public: 
        virtual int cost() = 0;
};

//Concrete base pizzas
class VegDelight: public BasePizza{
    public: 
        int cost() {
            cout << "VegDelight: Rs 120 ->";
            return 120;
        }
};

class Farmhouse: public BasePizza{
    public: 
        int cost() {
            cout << "Farmhouse: Rs 100 ->";
            return 100;
        }
};

class Margherita: public BasePizza{
    public: 
        int cost() {
            cout << "Margherita: Rs 80 ->";
            return 80;
        }
};

// Abstract Decorator
class ToppingDecorator: public BasePizza{

};

// Concrete Decorator
class ExtraCheese : public ToppingDecorator{
    BasePizza* pizza;
    public:
        ExtraCheese(BasePizza* pizza){
            this->pizza = pizza;
        }
        int cost(){
            cout << "ExtraCheese: Rs 10 ->";
            return this->pizza->cost() + 10;
        }
};

class ExtraJalepenoes : public ToppingDecorator{
    BasePizza* pizza;
        public:
            ExtraJalepenoes(BasePizza* pizza){
                this->pizza = pizza;
            }
            int cost(){
                cout << "ExtraJalepenoes: Rs 5 ->";
                return this->pizza->cost() + 5;
            }
};

class ExtraOlives : public ToppingDecorator{
    BasePizza* pizza;
    public:
        ExtraOlives(BasePizza* pizza){
            this->pizza = pizza;
        }
        int cost(){
            cout << "ExtraOlives: Rs 15 ->";
            return this->pizza->cost() + 15;
        }
};

class CheeseBurst : public ToppingDecorator{
    BasePizza* pizza;
    public:
        CheeseBurst(BasePizza* pizza){
            this->pizza = pizza;
        }
        int cost(){
            cout << "CheeseBurst: Rs 50 ->";
            return this->pizza->cost() + 50;
        }
};


int main(){
    BasePizza* pizzaForU1 = new ExtraCheese(new ExtraJalepenoes( new CheeseBurst( new Farmhouse())));
    BasePizza* pizzaForU2 = new ExtraCheese(new ExtraCheese(new ExtraCheese( new Margherita())));
    BasePizza* pizzaForU3 = new ExtraJalepenoes(new ExtraOlives( new VegDelight()));

    cout << "Bill for U1: " << pizzaForU1->cost() << endl;
    cout << "Bill for U2: " << pizzaForU2->cost() << endl;
    cout << "Bill for U3: " << pizzaForU3->cost() << endl;

    delete pizzaForU1;
    delete pizzaForU2;
    delete pizzaForU3;

    return 0;
}