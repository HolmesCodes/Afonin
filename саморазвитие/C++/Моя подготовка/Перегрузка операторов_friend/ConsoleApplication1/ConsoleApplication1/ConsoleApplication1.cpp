#include "Header.h"

using namespace std;

class TestClass; 
class Point { //хранение координат в 2у мерном пространстве
public:
    Point(int valueA, int valueB, string nameName) {
        a = valueA;
        b = valueB;
        name = nameName;
    }
    Point() {
        a = 0;
        b = 0;
        cout << this << " constuctor" << endl;
    }
    Point(int valueA, int valueB) {
        a = valueA;
        b = valueB;
    }


    ~Point() {
    cout << endl << "Сработал деструктор" << this;
    delete[] data;
    }
    
    int* data;
    Point(int size) {
        this->Size = size;
        this->data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = i;
        }
        cout << "Вызвался конструктор " << this << endl;
    }
    Point(const Point &other) {

        this->Size = other.Size;
        cout << "Вызвался конструктор копирования" << this << endl;
        this->data = new int[other.Size];
        for (int i = 0; i < other.Size; i++) {
            this->data[i] = other.data[i];
        }
    }



    void Print() {
        cout << endl<< "a="<<a<<" b="<<b<< endl;
    }



    Point operator =(const Point& other) {
        Point temp2;
        this->a = other.a;
        this->b = other.b;
        temp2.a = this->a;
        temp2.b = this->b;
        return temp2;
    }
    bool operator ==(const Point & other) {
        return this->a == other.a && this->b == other.b;
    }
    bool operator !=(const Point& other) {
        return !(this->a == other.a && this->b == other.b);
    }
    Point operator +(const Point &other) {
        Point temp;
        temp.a = this->a + other.a;
        temp.b = this->b + other.b;
        return temp;
    }
    Point& operator ++() { //инкремент префиксный
        this->a++;
        this->b++;
        return *this;
    }
    Point& operator ++(int value) { //инкремент постфиксный
        Point temp(*this);
        this->a++;
        this->b++;
        return temp;
    }
    Point& operator --() { //декримент префиксный
        this->a--;
        this->b--;
        return *this;
    }
    Point& operator --(int value) { //декримент постфиксный
        Point temp(*this);
        this->a--;
        this->b--;
        return temp;
    }
    
    friend void changeA(Point& value, TestClass& value2);

private:
    int a;
    int b;
    int Size;
    string name;
};
void Foo(Point value) {
    cout << "Вывелась функция Foo" << endl;
}
Point Foo2() {
    cout << "Вывелась функция Foo2" << endl;
    Point temp(1);
    return temp;
}
class TestClass
{
public:
    int& operator [](int index){
        return arr[index];
    }
    friend void changeA(Point& value, TestClass& value2);


private:
    int arr[5]{ 1,2,3,4,5 };
    int data = 0;
};
void changeA(Point & value, TestClass &value2) {
    value.a = -1;
    value2.data = 100;
}



class Apple;
class Human;





class Human
{
public:
    void TakeApple(Apple& apple); 
    
};

class Apple
{
    friend Human;
public:
    static int Count;

    Apple(int weight2, string color2) {
        weight = weight2;
        color = color2;
        Count++;
        id = Count;
    }

    int GetId() {
        return id;
    }
private:
    int weight;
    string color;
    int id;
};

int Apple::Count = 0;





int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /*Point first(1, 2, "hahaha");
    Point second;
    Point third(3);
    Point a;*/

   /*Foo(a);
    Foo2();
   Point a(10);
   Point b(a);
    Point a(5, 1);
    Point b(5, 1);

    bool result = a == b;
    cout<<result;
    bool result1 = a != b;
    cout << result1;
    Point first(1,2);
    Point second(2,3);
    Point therd = first + second;
    therd.Print();
    ++first;
    second++;
    Point fourd;
    fourd = first;
    fourd.Print();
    fourd = second;
    fourd.Print();

    TestClass a;
    cout << a[1] << endl;
    a[1] = 100;
    cout << a[1] << endl;

    Point a(1,2);
    TestClass test;
    a.Print();
    changeA(a,test);
    a.Print();

    Test mytest;
    mytest.PrintMessage();*/

    Apple apple(150, "red");
    Human human;
    human.TakeApple(apple);

    //cout<<apple.Count << endl;
    cout << Apple::Count << endl;

    return 0;
}
void Human::TakeApple(Apple& apple) {
    cout << "TakeApple!!! Weight:" << apple.weight << " color:" << apple.color << endl;
    
}