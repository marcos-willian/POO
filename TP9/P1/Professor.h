#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <string>

class Professor{
        std::string nome;
        virtual std::ostream& opeOutStream(std::ostream& out) const = 0;
    public:
        Professor(std::string n) : nome(n) {};
        std::string getName() const {return nome;};
        virtual double getSalario() const = 0;
        virtual ~Professor() {};
        friend std::ostream& operator<<(std::ostream& out, const Professor& prof){ return prof.opeOutStream(out);};
};

#endif