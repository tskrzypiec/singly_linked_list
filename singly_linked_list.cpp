#include <iostream>

using namespace std;


struct list_element  // tworzymy strukture elementów listy
{
    list_element * next_element; // wskaźnik na następny element listy
    int liczba;
};

// wyświetl zawartość listy

void show(list_element * p)
{
    unsigned i;
    cout<<"Liczby które mamy to: "<<endl;

    for(i = 1; p; p = p->next_element)                                  // nową wartość zmiennej to adres następnego elementu listy (przechowywany w polu next bieżącego elementu)
        cout << "Liczba  " << i++ << " to: " << p->liczba << endl;     // w ostatnim elemencie listy w polu next przechowywany jest adres 0
    cout << endl;

}

// dodaj element na początek listy

void push_front(list_element * & head, int ile)
{
    list_element * p;

    p = new list_element; // tworzymy dynamicznie w pamięci nowy element listy
    (*p).liczba = ile;    // wprowadzamy wartość dla pola liczba
    p->next_element = head; // w polu next_element umieszczamy adres przechowywany przez zmienną head, następnym elementem stanie się obecny pierwszy element listy
    head = p;  // w zmiennej head umieszczamy adres nowego elementu, początkiem listy staje się nowo utworzony element
}

// usuń element

void pop_front(list_element * & head)
{
    list_element * p = head; // zapamiętujemy pierwszy element

    if(p)  // zakończ jeśli lista jest pusta
    {
        head = p->next_element; // w zmiennej head umieszczamy zawartość next_element usuwanego elementu, lista rozpocznie się od następnego elementu
        delete p; // usuwamy z pamięci
    }
}

void delete_element(list_element *&head, list_element *e)
{
    list_element * p;

    if(head == e) pop_front(head);
    else
    {
        p = head;
        while(p->next_element != e) p = p->next_element;
        p->next_element = e->next_element;
        delete e;
    }
}


int main()
{
    list_element * start = NULL; // ustawiamy wskaźnik na NUll
    list_element * e;

    show(start);
    cout<<"push x 3"<<endl<<endl;
    push_front(start,1);
    push_front(start,2);
    push_front(start,3);
    show(start);
    cout<<"Teraz pop x 1"<<endl;
    pop_front(start);
    show(start);
    cout<<"pop"<<endl;
    pop_front(start);
    show(start);
    cout<<"Push"<<endl;
    push_front(start,3);
    show(start);
    cout<<"Push"<<endl;
    push_front(start,2);
    show(start);
    cout<<" Usuń liczbę 1 "<<endl;
    delete_element(start, start->next_element->next_element); // usuwamy liczbę 1
    show(start);


    return 0;
}