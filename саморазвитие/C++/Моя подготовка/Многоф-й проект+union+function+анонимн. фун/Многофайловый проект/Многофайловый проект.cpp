#include <iostream>
#include "Sum.h"
#include "MyClass.h"
#include "foo.h"
#include <functional>
#include <vector>
using namespace std;

//union - позволяет хранить данные в одной и той же области данных
union MyUnion { //выделил больше всего места под  самую большую переменную
    short int a;
    int b;
    float c;
};
//std::function - полиморфная обертка для функции
void Bar(int el) {
    if (el % 2 == 0)
        cout << "Bar: "<<el << "\t";
}
void baR(int el) {
    if (el < 3 || el >7)
        cout << "baR: "<< el << "\t";
}
void DoWork(vector<int>& vc, function<void(int)> f) {
    for (auto el : vc) {
        f(el);
    }
}
void DoWork2(vector<int>& vc, vector<function<void(int)>> funkvector) {
    for (auto el : vc) {
        for (auto &fel : funkvector) {
            fel(el);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    //многофайловый проект
    /*int res = Sum(1, 2);
    cout << res << endl;

    Print::MyClass myclass; //также можно подключить пространство имен с пом. using
    myclass.PrintMessage("Hello!");

    foo2(); //foo2 вызывает внутри помимо методов еще и foo
    */
    //union
    /*MyUnion my;
    my.a = 5;
    my.b = 40000; //происходит перезапись в памяти и 'a' заполнилась мусором
    my.c = 3.14; //дробное число также сохраняется по-особенному
    */
    //std::function
    /*
    function<void()> f; //+- указатель на функцию //важна сигнатура при создании объекта (<void()>) - тип возвращаем. знач и параметры
    f = foo2;
    f();
    function<int(int,int)> fInt;
    fInt = Sum;
    int res= fInt(1,2);
    cout << "res=" << res << endl;

    vector<int> vc = { 1,2,3,4,5,6,7,8,9,10 };
    DoWork(vc,baR);
    
    vector<int> vc2 = { 1,2,3,4,5,6,7,8,9,10 };
    vector<function<void(int)>> fvector;
    fvector.emplace_back(Bar);
    fvector.emplace_back(baR);
    DoWork2(vc2, fvector);*/
    //лямбда-функция - анонимная функция
    /*vector<int> vc = {10,9,8,7,6,5,4,3,2,1};
    function<void(int)> f;
    DoWork(vc, [](int a) { cout << "Вызов анонимной функции! " << a << endl;});

    int p = 5;
    auto l = [&p]() {
        p = 10;
        return p;
        };
    l();

    auto w = l();*/
    /*
    int a = 55, b=10;
    //[a]-только для чтения(без изменения ее)
    //[&a]-можно ее изменять
    //[=]-захват всех переменных вокруг по значению
    //[&]-захват всех переменных не только для считывания, но и для изменений
    //[=]()muteble - данные в функции присваиваются, но переменные не меняются
    //[&a,b]()muteble - изменения отразятся на ф, а на b нет
    //[this] - для работы функции с классом
    auto f1 = [&]() { 
        cout << "a=" << a << " b=" << b << endl;
        a = b = 12;
        cout << "a=" << a << " b=" << b << endl;

        //return 0; - ничего возвращать пока не нужно
    };
    f1(); //вызываем лямбда-функцию

    Print::MyClass m;
    m.Lampda();

    auto f2 = []() ->float //->int - сразу указываем тип возвращаемого значения
    {
            return 29; //приведтся к типу float
    };
    f2();
    */
    return 0;
}
