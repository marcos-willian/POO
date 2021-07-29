#ifndef PAGER_H
#define PAGER_H 
#include <string>
#include <iostream>
class Pager{
    private:
        std::string name;
    public:
        Pager(std::string n) : name(n) {
            std::cout << "In constructor Pager!\n";
        };
        Pager(const Pager& pager ){
            name = pager.name + "-Copy";
            std::cout << "In copy constructor Pager!\n";
        };
        Pager& operator=(const Pager& pager){
            name = pager.name + "-Atribuition";
            std::cout << "In atribuition Pager!\n";
            return *this;
        }
        void print() const { 
            std::cout << "Pager name: "<< name << std::endl;
        }
};
#endif //PAGER_H