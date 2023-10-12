#include <algorithm>
#include <iostream>
#include <list>
#include <string>
using namespace std;

class FileSystem {
    protected:
        string name = "";

    public:
        virtual void print() = 0;
};

class File : public FileSystem {
    public:
        File(string name) {
            this->name = name;
        }

        void print() override {
            cout << "File: " << name << endl;
        }
};

class Directory : public FileSystem {
    vector<FileSystem*> children; 
    public:
        Directory(string name) {
            this->name = name;
        }

        void addChild(FileSystem* child){
            children.push_back(child);
        }

        void print() override {
            cout << "Directory: " << name << endl;
            cout << "Children: " << endl;
            for(int i=0; i<children.size(); i++){
                cout << "   " << i+1 << ". ";
                children[i]->print();
                cout << endl;
            }
        }
};

int main() {

  File *f1 = new File("abc.pdf");
  File *f2 = new File("game.exe");
  File *f3 = new File("book.pdf");
  File *f4 = new File("code.cpp");


  Directory *d1 = new Directory("Study");
  Directory *d2 = new Directory("Games");

  d1->addChild(f1);
  d1->addChild(f3);
  d1->addChild(d2);

  d2->addChild(f2);
  d2->addChild(f4);

  d1->print();

  
  delete f1;
  delete f2;
  delete f3;
  delete f4;
  delete d1;
  delete d2;

  return 0;
}