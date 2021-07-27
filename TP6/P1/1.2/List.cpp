#include "List.h"

// construtor default 
template<class T> 
List<T>::List(){
    head = 0; 
    tail = head;
}

// Destrutor
template<class T> 
List<T>::~List(){
    if (!empty())
    {
        Node<T> *it;
        it = head;
        head = head->next;
        while(head != 0)
        {
            delete(it);
            it = head;
            head = head->next;
        }
        delete(it);
    }
}

// construtor de copia
template<class T> 
List<T>::List(const List& L){
    *this = L;
}

//--------------------- Metodos que manipulam a Lista ------------------------//

// retorna true, caso a lista nao contenha nenhum elemento 
template<class T> 
bool List<T>::empty() const{
    return (head == 0);
}

// retorna apontador para a primeira posicao da lista
template<class T> 
Node<T>* List<T>::begin(){
    Node<T> *it; 
    it = head;
    return it;
}

// retorna apontador para a ultima posicao da lista
template<class T> 
Node<T>* List<T>::end(){
    Node<T> *it; 
    it = tail;
    return it;
}

// retorna o tamanho da lista
template<class T>
int List<T>::size(){
    int temp = 0;
    Node<T> *it;
    for (it = begin(); it != 0; it = it->next, temp++);
    return temp;
}    


// insere elemento no inicio da lista 
template<class T> 
void List<T>::push_front(const T& x){
    if (empty())
        push_back(x);
    else {
        Node<T> *it;
        it = new Node<T>(x);
        it->next = head;
        head->prev = it;
        head = head->prev;
    }
}

// insere elemento no final da lista 
template<class T> 
void List<T>::push_back(const T &x){
    if (empty()){
        tail = new Node<T>(x);
        head = tail;
    }
    else{
        Node<T>* it;
        tail->next = new Node<T>(x);
        it = tail;
        tail = tail->next;
        tail->prev = it;
    }
}


// apaga todos os nohs da lista 
template<class T> 
void List<T>::clear(){
    Node<T> *it;
    if (!empty()){
        it = head;
        while(it != 0)
            it = erase(it);
    }
    head = 0; tail = 0;
}

// remove o no da lista apontado por it e retorna um link 
// que aponta para o primeiro no restante apos o elemento removido, ou zero, 
// caso este elemento nao exista 
template<class T> 
Node<T>* List<T>::erase(Node<T> *it){
    if ( (!empty()) && (it != 0) ){
        if (tail == head){
            delete(tail);
            head = 0; tail = 0;
            return head;
        }
        else{
            Node<T> *temp1, *temp2;
            temp1 = it->prev;
            temp2 = it->next;
            if (it == head){
                temp2->prev = temp1;
                head = temp2;
            }
            else if (it == tail) {
                temp1->next = temp2;
                tail = temp1;
            }
            else{
                temp2->prev = temp1;
                temp1->next = temp2;
            }
            delete(it);
            return temp2;
        }
    }
    else
        throw std::runtime_error("Impossivel remover o elemento da Lista.");
}



// remove os elementos de valor igual a T existentes na lista O(n)
template<class T> 
void List<T>::erase(const T &value){
    if (!empty()){
        Node<T> *it;
        it = head;
        while(it != 0){
            if (*(it->item) ==  value)
                it = erase(it);
            else
                it = it->next;
        }
    }
    else
        throw std::runtime_error("Lista Vazia! Impossivel remover o elemento da Lista.");
}

// sobrecarga do operador de atribuição
template<class T> 
List<T>& List<T>::operator=(const List<T> &L){
    if (this == &L) return *this;
    clear();
    Node<T> *it = L.head;
    while (it != 0){
        push_back( *(it->item) );
        it = it->next;
    }
    return *this;
}

// sobrecarga do operador de Fluxo << (impressao na tela)
template<class T> 
std::ostream& operator<<(std::ostream& saida, List<T>& L){
    Node<T> *it;
    std::cout<<" = ";
    for (it = L.head; it != 0; it = it->get_next())
        saida << it->get_item() << " -> ";
    std::cout << std::endl;
    return saida; 
}