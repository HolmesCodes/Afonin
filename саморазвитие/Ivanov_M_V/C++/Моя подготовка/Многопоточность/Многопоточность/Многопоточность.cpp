#include <iostream>
#include <thread> //для работы с потоками
#include <chrono> //для работы со временем
#include "SimpleTimer.h"
using namespace std;

//вывод id потока
void DoWork() {
    for (size_t i = 0; i < 10;i++) {
        cout << "ID потока = " << this_thread::get_id() << "\tDoWork id: " <<i<< endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
} 
//сложные процессы вычитания с искусственным замедлением
void FooSumThread(int a,int b) {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "FooSumThread started"<<endl;
    this_thread::sleep_for(chrono::seconds(10));
    cout << "a+b=" << a + b << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "FooSumThread stopped" << endl;
}
//передача параметов в функцию
void DoWork2(int &a) {
    cout << "DoWork2 started" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    a *= 2;
    cout << "DoWork2 stopped" << endl;
    this_thread::sleep_for(chrono::seconds(10));
    cout << "Текущий поток: "<< this_thread::get_id() << endl;
}
int Sum(int a, int b) {
    cout << "Sum started" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Sum stopped" << endl;
    this_thread::sleep_for(chrono::seconds(7));
    cout << "Текущий поток: " << this_thread::get_id() << endl;
    return a + b;
}
class MyClass {
public:
    void DoWork3() {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока " << this_thread::get_id() << " - DoWork STARTED!" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "ID потока " << this_thread::get_id() << " - DoWork ENDED!" << endl;
    }
    void DoWork4(int a) {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока " << this_thread::get_id() << " - DoWork2 STARTED!" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "a=" << a << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "ID потока " << this_thread::get_id() << " - DoWork2 ENDED!" << endl;
    }
    int Sum(int a, int b) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "ID потока " << this_thread::get_id() << " - Sum STARTED!" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "ID потока " << this_thread::get_id() << " - Sum ENDED!" << endl;
        return a + b;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    //первая работа с потоками и библиотекой chrono
    /*thread th(DoWork);
    thread th2(DoWork);
    //th.detach(); //разорвать между объектом и потоком. поток работает пока основной поток тоже работает, иначе завершается
    for (size_t i = 0; i < 10;i++) {
        cout << "ID потока = " << this_thread::get_id() << "\tmain" << endl;//возвращает id текущего потока
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    th.join();//дожидается выполнения задачи в отдельном потоке
    th2.join();*/
    //передача параметров в поток        
    /*thread th(FooSumThread, 10, 20); //можног также сразу передать параметры

    for (size_t i = 0; true;i++) {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i<<endl;//возвращает id текущего потока
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    th.join();*/
    //трудности с передачей парамтеров
    /*int q = 5;
    thread th2(DoWork2, std::ref(q)); //без функции "ref" не работает. Она создает класс, позволяющий работать с потоком
    
    for (size_t i = 0; i<10;i++) {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i << endl;//возвращает id текущего потока
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    
    th2.join();
    cout << q; */
    //использование лямбда-функции
    /*int result;
    thread t([&result]() {result = Sum(2, 5);});//лямбда функция требуется так как в поток нельзя просто передать переменные

        for (size_t i = 0; i < 10;i++) {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i << endl;//возвращает id текущего потока
        this_thread::sleep_for(chrono::milliseconds(500));
        }

    t.join();
    cout << "result = "<<result << endl;
    */
    //измерение времени выполнения кода (chrono)
    /*//можно написать всю реализацию в main:

    auto start = chrono::high_resolution_clock::now();
    int result;
    //thread t([&result]() {result = Sum(2, 5);});
    result = Sum(2, 5);
    for (size_t i = 0; i < 10;i++) {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(250));
    }
    //t.join();
    cout << "result = " << result << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << "Duration: " << duration.count() << "s"<<endl;

    //но лучше всю реализацию вынести в отдельный класс

    SimpleTimer s;
    int result;
    thread t([&result]() {result = Sum(2, 5);});
    for (size_t i = 0; i < 10;i++) {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(250));
    }
    t.join();
    cout << "result = " << result << endl;*/
    //пупупу
    MyClass m;
    //int result; 
    //thread t([&]() { result = m.Sum(2, 5);});
    //thread t([&]() {m.Sum(2, 5);});
    thread t(&MyClass::DoWork4,m,1);
    for (size_t i = 0; i <= 10; i++)
    {
        cout << "ID потока " << this_thread::get_id() << " - Main Thread!" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
    t.join();
    //cout << "result = " << result << endl;
    return 0;
}

