#ifndef BTRAVELER_H
#define BTRAVELER_H
#include <iostream>
#include <string>
#include "Traveler.h"
#include "Pager.h"

class BusinessTraveler : public Traveler {
    private:
        Pager pager;
    public:
        BusinessTraveler (std::string name = "1") : Traveler(name), pager(name) { 
            std::cout << "In constructor BusinessTraveler!\n";
        }
        BusinessTraveler ( const BusinessTraveler& business) : Traveler(business), pager(business.pager) {
            std::cout << "In copy constructor BusinessTraveler!\n";
        }
        BusinessTraveler& operator=(const BusinessTraveler& business) {
            std::cout << "In atribuition BusinessTraveler!\n";
            pager =  business.pager;
            Traveler::operator=(business);
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& os, const BusinessTraveler& business);
};
std::ostream& operator<<(std::ostream& os, const BusinessTraveler& business){
    business.print();
    business.pager.print();
    return os;
}


#endif //BTRAVELER_H