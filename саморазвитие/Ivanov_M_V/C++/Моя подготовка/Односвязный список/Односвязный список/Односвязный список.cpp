#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List {
public:
    List();
    ~List();
    void RandomListNumbers(int index); //заполнение List случайными числами
    void ListOutput(); //вывод List
    void SizeOfList(); //вывод кол-ва эл-ов
    void removeAt(int index); //удаление по индексу
    void pop_back(); //удаление последнего эл-та
    void Insert(T value, int index); //вставка символа
    void push_back(T data); //вставка в конец значения
    void pop_front(); //удаление 1-го эл-та
    void Clear(); //очистка всего списка
    void push_front(T data); //вставка в начало
    int GetSize() { return Size; } //кол-во эл-ов в листе
    T& operator [](const int index); //перегрузка, с пом кот возвращается число под индексом
private:


    template<typename T>
    class Node {
    public:
        Node* pNext;
        T data;
        Node(T data=T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
       }
    };

    Node<T>*head; //указывает на первый элемент списка
    int Size; //кол-во элементов в списке
};
int main()
{
    setlocale(LC_ALL, "ru");

    List<int> lst;

    int numbersCount;
    cout << "Введите кол-во эл-ов: ";
    cin >> numbersCount;

    lst.RandomListNumbers(numbersCount);
    lst.ListOutput();
    lst.pop_front();
    lst.ListOutput();
    lst.Clear();
    lst.SizeOfList();
    lst.RandomListNumbers(numbersCount);
    lst.ListOutput();
    lst.push_front(7);
    lst.ListOutput();
    lst.Insert(10, 2);
    lst.ListOutput();
    lst.removeAt(1);
    lst.ListOutput();
    lst.pop_back();
    lst.ListOutput();
    return 0;
}

//реализация
template<typename T>
List<T>::List() {
    Size = 0;
    head = nullptr;
};
template<typename T>
List<T>::~List() {
    cout << endl << "Вызвался деструктор!";
    Clear();
}
template<typename T>
void List<T>::RandomListNumbers(int index)
{
    for (int i = 0; i < index; i++)
    {
        push_back(rand() % 10);
    }
}
template<typename T>
void List<T>::ListOutput()
{
    cout << endl;
    Node <T> *current = head;
    for (int i = 0; i < Size; i++)
    {
        cout << current->data << "\t";
        current = current->pNext;
    }
}
template<typename T>
void List<T>::SizeOfList()
{
    cout << endl<<"В списке " << Size << " элементов";
}
template<typename T>
void List<T>::removeAt(int index)
{
    if (index == 0) {
        pop_front();
    }
    else {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }
        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
};
template<typename T>
void List<T>::Insert(T data, int index)
{
    if (index == 0) {
        push_front(data);
    }
    else {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1;i++) {
            previous = previous->pNext;
        }
        Node<T>* newNode = new Node<T>(data, previous->pNext);
        previous->pNext = newNode;
        Size++;
    }
    
}
template<typename T>
void List<T>::push_back(T data) {
    if (head==nullptr) {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}
template<typename T>
void List<T>::pop_front()
{
    cout << endl<<"Удаление 1 эл-та:";
        Node<T> *temp = head;
        head = head->pNext;
        delete temp;
        Size--;
}
template<typename T>
void List<T>::Clear()
{
    cout << endl<<"Выполняется очистка всего списка...";
    while (Size) {
        pop_front();
    }
}
template<typename T>
void List<T>::pop_back()
{
    removeAt(Size - 1);
}
template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data,head); //head в скобках - это еще старый head
    Size++;

}
template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
};