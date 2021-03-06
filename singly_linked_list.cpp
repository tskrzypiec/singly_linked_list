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

// dodaj element na koniec listy

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

void find_and_delete(list_element *&head, int v)
{
    list_element *p_find_element = head;

    while (p_find_element && p_find_element->liczba != v) p_find_element = p_find_element->next_element; // szukamy adresu poszukiwanej liczby

    list_element *p;

    if (head == p_find_element) pop_front(head); // usuwamy określoną liczbę
    else {
        p = head;
        while (p->next_element != p_find_element) p = p->next_element;
        p->next_element = p_find_element->next_element;
        delete p_find_element;
    }
}


int main()
{
    list_element * start = NULL; // ustawiamy wskaźnik na NUll


    cout<<"Lista jest pusta, dodaj coś"<<endl<<endl;
    cout<<"push x 3"<<endl<<endl;
    push_front(start,1);
    push_front(start,2);
    push_front(start,3);
    show(start);
    cout<<"Teraz coś zabierz z listy"<<endl<<endl;
    cout<<"pop"<<endl<<endl;
    pop_front(start);
    show(start);
    cout<<"pop"<<endl<<endl;
    pop_front(start);
    show(start);
    cout<<"push"<<endl<<endl;
    push_front(start,3);
    show(start);
    cout<<"push"<<endl<<endl;
    push_front(start,2);
    show(start);
    cout<<"Skasuj z listy liczbę 1 "<<endl<<endl;
    find_and_delete(start, 1);
    show(start);

    return 0;
}