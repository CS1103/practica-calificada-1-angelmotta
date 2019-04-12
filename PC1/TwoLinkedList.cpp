#include "TwoLinkedList.h"
#include <iostream>

void UTEC::TwoLinkedList::push_back1(int value){
    Node* temp = new Node(value);
    if(!is_merge()){    //Sino estan unidos
        //std::cout << "Aun no estan unidos" << std::endl;
        if(tail1 == nullptr){
            head1 = temp;
            tail1 = temp;
        } else{
            tail1->next = temp;
            tail1 = temp;
        }
    }
    else{
        //std::cout << "Ya estan unidos...al final de tail" << std::endl;
        tail->next = temp;
        tail = temp;
    }
}

void UTEC::TwoLinkedList::push_back2(int value){
    Node* temp = new Node(value);
    if(tail2 == nullptr){
        head2 = temp;
        tail2 = temp;
    } else{
        tail2->next = temp;
        tail2 = temp;
    }
}

std::string UTEC::TwoLinkedList::getlist(int lista){
    std::string valores="";
    if(lista == 1){
        Node* actual = head1;
        while(actual != nullptr) {
            valores += std::to_string(actual->value) + " ";
            actual = actual->next;
        }
        //std::cout << valores << std::endl;
        return valores;
    }
    else if(lista == 2){
        Node* actual = head2;
        while(actual != nullptr) {
            valores += std::to_string(actual->value) + " ";
            actual = actual->next;
        }
        return valores;
    }
    else if(lista == 0){
        return valores;
    }
}

std::string UTEC::TwoLinkedList::merge(int value){
    std::string mensaje = "";
    if(tail == nullptr){
        Node* temp = new Node(value);
        tail1->next = temp;
        tail2->next = temp;
        tail = temp;            // Sea crea la cola tail
        mensaje = "Operación Exitosa";
    }
    else{   // tail No es nullptr entonces ya existe una cola
        mensaje = "Operación duplicada";
    }
    return mensaje;
}

bool UTEC::TwoLinkedList::is_merge() {
    bool ismerge;
    if(tail == nullptr){
        ismerge = false;
    }
    else{
        ismerge = true;
    }
    return ismerge;
}