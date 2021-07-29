#ifndef TRAVELER_H
#define TRAVELER_H 
#include <string>
#include <iostream>
class Traveler{
    private:
        std::string name;
    public:
        Traveler(std::string n) : name(n) {
            std::cout << "In constructor Traveler!\n";
        };
        Traveler(const Traveler& traveler ){
            name = traveler.name + "-Copy";
            std::cout << "In copy constructor Traveler!\n";
        };
        Traveler& operator=(const Traveler& traveler){
            name = traveler.name + "-Atribuition";
            std::cout << "In atribuition Traveler!\n";
            return *this;
        }
        void print() const { 
            std::cout << "Traveler name: "<< name << std::endl;
        }
};
#endif //TRAVELER_H