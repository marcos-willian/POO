#ifndef LIST_H_
#define LIST_H_
#include <iostream>


/* essas declaracoes sao necessarias */
template <class T>
class List;

template <class T> 
std::ostream& operator<<(std::ostream&, List<T>&);

// classe Node: Noh da Lista duplamente encadeada
template <class T>
class Node{
    friend class List<T>;
    private:
        T *item;
        Node<T> *next;
        Node<T> *prev;
    public:
        Node<T>() { next = 0; prev = 0; }
        Node<T>(const T &x) { item = new T(x); next = 0; prev = 0; }
        Node<T>* get_next() { return next; }
        Node<T>* get_prev() { return prev; }
        T get_item() { return *item; }       
};

// Classe List: Lista Duplamente Encadeada
template <class T> 
class List {
    public:
        // construtores e destrutor
        List<T>();
        List<T>(const List& L);
        ~List<T>();
    
        // sobrecarga do operador de atribuicao
        List<T>& operator=(const List<T> &L);
        
        // Friend Function can access private members of the List class
        friend std::ostream& operator<< <>(std::ostream&, List&);
    
        // metodos que manipulam a lista
        bool empty() const;
        Node<T>* begin();
        Node<T>* end();
        void push_front(const T &x);
        void push_back(const T &x);
        Node<T>* erase(Node<T> *it);
        void erase(const T& value);
        void clear();
        int size();
        
    private:
        Node<T> *head;
        Node<T> *tail; 
};

#endif /*LIST_H_*/