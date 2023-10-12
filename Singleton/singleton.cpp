#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

class Singleton{
    private:
        static Singleton* singletonInstance;
        static int counter;
        static mutex mtx;
        Singleton(){
            counter++;
            cout << "New instance created, Instance number: " << counter << endl;
        }
    public: 

        static Singleton* getInstance(){
            /*
                Double lock as we will only lock the threads when
                we encounter a NULL instance. Otherwise no need for lock. 
            */ 
            if(singletonInstance == NULL) {
                mtx.lock();
                if(singletonInstance == NULL){
                        singletonInstance = new Singleton();
                    }
                mtx.unlock();
            }
            return singletonInstance;
        }
        static void destroyInstance() {
            if (singletonInstance != nullptr) {
                delete singletonInstance;
                singletonInstance = nullptr;
            }
        }

        static int getCounter() {
            return counter;
        }
};

Singleton* Singleton::singletonInstance = nullptr;
int Singleton::counter = 0;
mutex Singleton::mtx;

void first(){
    Singleton* instance1 = Singleton::getInstance();
    return;
}
void second(){
    Singleton* instance2 = Singleton::getInstance();
    return;
}

int main() {
    
    thread t1(first);
    thread t2(second);

    
    t1.join();
    t2.join();

    // Destroy the instance when done
    Singleton::destroyInstance();

    return 0;
};





