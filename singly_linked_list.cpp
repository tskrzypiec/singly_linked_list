#include <iostream>

using namespace std;


struct list_element  // tworzymy strukture elementów listy
{
    list_element * next_element; // wskaźnik na następny element listy
    int liczba;
};

// wyświetlamy zawartość elementów listy

void show(list_element * p)
{
    unsigned i;
    cout<<"Liczby które mamy to: "<<endl;

    for(i = 1; p; p = p->next_element)                                  //W pętli przetwarzamy element wskazywany przez tą zmienną, po czym za nową wartość
        cout << "Liczba  " << i++ << " to: " << p->liczba << endl;
    cout << endl;                                                                  // zmiennej przyjmuje się adres następnego elementu listy.
                                                                        //Adres ten jest przechowywany w polu next elementu bieżącego.
                                                                        //Listę przechodzimy do momentu, aż zmienna wskazująca przyjmie wartość 0.
                                                                        // Stanie się tak po wyjściu z ostatniego elementu listy, w którego polu next przechowywany jest adres 0.
}

// dodajemy element na początek listy

void push_front(list_element * & head, int ile)
{
    list_element * p;

    p = new list_element; //tworzymy dynamicznie w pamięci nowy element listy
    (*p).liczba = ile;   //wprowadzamy wartość dla pola liczba // mozna stralka p=> liczba = ile;
    p->next_element = head; // W polu next_element umieszczamy adres przechowywany przez zmienną head. W ten sposób następnikiem nowego elementu stanie się obecny pierwszy element listy.
    head = p;  //w zmiennej head umieszczamy adres nowego elementu. Po tej operacji początkiem listy staje się nowo utworzony element.
}

// Procedura usuwa pierwszy element
//---------------------------------
void pop_front(list_element * & head)
{
    list_element * p = head; //zapamiętujemy pierwszy element

    if(p)  //zakończ jeśli lista jest pusta
    {
        head = p->next_element; // w zmiennej head umieszczamy zawartość pola next usuwanego elementu. W ten sposób początek listy rozpocznie się w następniku, a usuwany element zostanie wyłączony z listy.
        delete p; //usuwamy z pamięci
    }
}

//---------------
// Program główny
//---------------

int main()
{
    list_element * L = NULL;

    push_front(L,1);
    push_front(L,8);
    push_front(L,9);
    show(L);
    pop_front(L);
    show(L);
    pop_front(L);
    show(L);
    push_front(L,8);
    show(L);
    push_front(L,9);
    show(L);

    return 0;
}