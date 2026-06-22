#include <iostream>
#include <string>
#include "Windows.h"
#include <memory> //библиотека для исп умных указателей
using namespace std;

//шаблоный класс
template <typename T1, typename T2> //template-шаблонный класс //typename - будут использоваться обобщенные типы данных //Т-название обобщенного типа данных
class MyClass
{
public:
    MyClass(T1& value, T2& value2) {
        this->value = value;
        this->value2 = value2;
    }
    void DataTipeSize() {
        cout << "value " << sizeof(value) << endl;
        cout << "value2 " << sizeof(value2) << endl;
    }
    T1 Foo() { return value; }
    T2 Foo2() { return value2; }
private:
    T1 value;
    T2 value2;
};
class Point {
public:
    Point() {
        x = y = z = 0;
    }
    Point(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    friend ostream& operator<< (ostream& os, const Point& point);
    friend istream& operator>> (istream& is, Point& point);
private:
    int x;
    int y;
    int z;
};
ostream& operator<< (ostream &os, const Point &point) {  // ostream - поток вывода
    os << point.x<< point.y<< point.z;
    return os;
}
istream& operator>> (istream& is, Point& point) {  // ostream - поток вывода
    is >> point.x >> point.y >> point.z;
    return is;
}
//специализация шаблонов
template <typename T>
class Printer {
public:
    void Print (T value) {
        cout << value << endl;
    }
private:
};
template<>
class Printer<string>
{
public:
    void Print(string value) {
        cout <<"______"<< value << "______" << endl;
    }
};
//struct
struct MyStruct {
    //по умолчанию все поля и объекты public
    //при наследовании все поля по умолчанию public
    int a = 10;
};
class MyClassStr {
    //по умолчанию все поля и объекты private
    //при наследовании все поля по умолчанию private
    int a = 10;
};
struct MyStruct2 : MyStruct { //наследование без указания модификатора доступа
    void foo() {
        cout << a << endl;
    }
};
class MyClassStr2 : MyClassStr { //наследование без указания модификатора доступа
    void foo() {
        //cout << a << endl; 
        //без указания public в начале нет доступа к "a"
    }
};
//умные указатели - сами очищают память когда выходят из области видимости
template <typename T>
class SmartPointer { //автоматизации работы с указателем
public:
    SmartPointer(T *ptr){
        this->ptr = ptr;
        cout << "Constructor" << endl;
    }
    ~SmartPointer() {
        delete ptr;
        cout << "Destructor" << endl;
    }

    T& operator *() {
        return *ptr;
    }
private:
    T* ptr;
};

int main()
{
    setlocale(LC_ALL, "ru");
    /*
    int a=5;
    int b = 5;
    MyClass <int,int> myclass(a,b); //<int> - указываем тип данных
    myclass.DataTipeSize();
    cout << endl;
    Point point;
    MyClass <Point,int> myclass2(point,a);
    myclass2.DataTipeSize();
    cout<<endl<<myclass2.Foo();
    cout << endl << myclass2.Foo2()<<endl;
    cin >> point;
    myclass2 = MyClass<Point, int>(point, a);
    cout << endl << myclass2.Foo();

    Printer <int> P;
    P.Print(67);
    Printer <string> S;
    S.Print("Hello world!!!");

    MyClassStr myclassctr;
    MyStruct mystruct;
    MyStruct2 mystruct2;
    mystruct.a = 11;
    mystruct2.foo();

    SmartPointer<int> pointer = new int(5);
    cout << *pointer << endl;
    SmartPointer <int> pointer2 = pointer;

    auto_ptr<int> ap1(new int(5));
    auto_ptr<int> ap2(ap1); //auto_ptr - ap2 принимает значение ap1, a ap1 очищает свои

    unique_ptr<int> ap3(new int(5));
    //unique_ptr<int> ap4(ap3); //нельзя обоим указателям указывать на одну память
    unique_ptr<int> ap4;
    ap4 = move(ap3);
    ap3.swap(ap4);
    int* p = ap3.get();

    shared_ptr<int> p1(new int(5)); //несколько дин указателей в одно место памяти
    shared_ptr<int> p2(p1);
*/

    int SIZE;
    cin >> SIZE;
    /*вариант 1
    int* arr = new int(SIZE);
    shared_ptr<int[]> ptr(arr); */
    //вариант 2
    shared_ptr<int[]> ptr(new int[SIZE]{1, 2, 3, 4, 5}); //shared_ptr<int[]> - не забыть [] где int для работы с массивом
    for (int i = 0; i < SIZE; i++)
    {
        ptr[i] = rand() % 10;
        cout << ptr[i] << endl;
        
    }

    return 0;
}