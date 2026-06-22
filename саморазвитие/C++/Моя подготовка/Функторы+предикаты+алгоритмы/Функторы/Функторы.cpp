#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

//класс с функтором
class MyFunctor
{
public:
    int operator ()(int a, int b) {
        std::cout << "я функтор!" << endl;
        //cout<<"count=" <<count<<endl;
        //count++;
        return a + b;
    };
private:
    int count = 0;
};
//предикат
bool GreaterThanZero(int a) {
    return a > 0;
}
bool LessThanZero(int a) {
    return a < 0;
}

class Person {
public:
    Person (string name, double score){
        this->name = name;
        this->score = score;
    }
    bool operator() (const Person &p) {
        return p.score > 30;
    }
    string name;
    double score;
};

int main()
{
    setlocale(LC_ALL, "ru");
    vector<Person> people{
        Person("Mikhail", 19),
        Person("Miron", 18),
        Person("Ura", 40),
        Person("Sasha", 18),
        Person("Egor", 80),
    };
    //функтор - фун-я у кот. перегружен оператор ()
    /*MyFunctor mf;
    cout<<mf(1,2);*/
    //предикатор-функтор или функция возвращающие bool
    /*
    //cout << GreaterThanZero(-1) << endl;
    vector<int> v = { 1,-2, -55, 9, -3, 8 };
    int result = count_if(v.begin(), v.end(), GreaterThanZero);
    std::cout << result << endl;
    int PersRes = count_if(people.begin(), people.end(), people.front());
    std::cout << PersRes << endl;
    */
    //алгоритм сортировки
    /*vector<int> v = {1,9,2,8,3,7,4,6,5};
    sort(v.begin(), v.end());
    for (auto& el : v) {
        cout << el << endl;
    }
    cout << endl;
    sort(v.begin(), v.end(), [](int a, int b) {return a>b;});
        for (auto& el : v) {
            cout << el << endl;
        }
        
        const int SIZE = 7;
        int arr[SIZE] = { 9,4,8,2,7,4,1 };
        for (auto& el : arr) {
            cout << el << endl;
        }
        sort(arr, arr+SIZE);
        for (auto& el : arr) {
            cout << el << endl;
        }
        //сортировка по имени
        sort(people.begin(), people.end(), [](const Person& p1, const Person& p2) {
            bool result = p1.name < p2.name;
            return result;
            });
        for (auto el : people) {
            cout << "Name: " << el.name << " баллы: " << el.score << endl;
        }*/
    //алгоритмы поиска
    /* //find-для проверки на равенство
    vector<int> v = {1,9,2,8,3,7,4,6,5};
    auto res = find(v.begin(), v.end(), 7);
    if (res != v.end()) {
        cout << "good" << endl;
    }
    else {
        cout << "no" << endl;
    }
    //find_if, find_if_not
    auto res2 = find_if(v.begin(), v.end(), [](int a) {return a%2==0;}); //проверка на наличие четных чисел
    if (res2 != v.end()) {
        cout << "good" << endl;
    }
    else {
        cout << "no" << endl;
    }

    auto res3 = find_if(people.begin(), people.end(), [](const Person &p) {return p.name=="Miron" && p.score==18;});
    if (res3 != people.end()) {
        cout << "good" << endl;
    }
    else {
        cout << "no" << endl;
    }
    */
    //выборка данных по условию
    /*
    vector<Person> result;
    cout << "Всего эл-ов: " << result.size() << endl;

    //back_inserter(result) - функция в скобках кот. пишется контейнер куда перекопируются данные
    //copy(people.begin(), people.end(), back_inserter(result)); 

    copy_if(people.begin(), people.end(), back_inserter(result), [](const Person&p) {return p.score<70;});
    for (auto el : result) {
        cout << "Name: " << el.name << " баллы: " << el.score << endl;
    }
    cout << "Всего эл-ов: " << result.size() << endl;
*/
    //удаление элемента
    /*
    vector<int> v = { 1,9,2,1,4,8,3,7,4,6,5 };
    auto res =remove(v.begin(), v.end(), 1); //все 1 перемещаются назад вектора
    v.erase(res, v.end()); //тут все что после уже стирается
    for (auto el : v) {
        cout << el << endl;
    }
    cout << endl;

    people.erase(remove_if(people.begin(), people.end(), [](const Person& p) {return p.score < 40;}),people.end());
        for (auto el : people) {
            cout << "Name: " << el.name << " баллы: " << el.score << endl;
        }
        */
    //поиск максимального эл-та в коллекции
    /*
    list<int> lst = { 2,2,3,4,5,6,7,8,10,11,12,11 };
    vector<int> v = { 1,9,2,1,4,8,3,7,4,6,5 };

    //auto resoult = max_element(v.begin(), v.end());
    auto resoult = max_element(lst.begin(), lst.end());
    cout << *resoult << endl;

    const int SIZE = 6;
    int arr[SIZE] = { 1,2,3,4,5,6 };
    auto resoult2 = max_element(arr, arr+SIZE);
    cout << *resoult2 << endl;
    */
    //поиск минимального эл-та в коллекции
    /*
list<int> lst = { 2,2,3,4,5,6,7,8,10,11,12,11 };
vector<int> v = { 1,9,2,1,4,8,3,7,4,6,5 };

//auto resoult = min_element(v.begin(), v.end());
auto resoult = min_element(lst.begin(), lst.end());
cout << *resoult << endl;

const int SIZE = 6;
int arr[SIZE] = { 1,2,3,4,5,6 };
auto resoult2 = min_element(arr, arr + SIZE);
cout << *resoult2 << endl; 

auto resoult3 = minmax_element(v.begin(), v.end());
cout << *resoult3.first << "\t"<< * resoult3.second << endl;
*/
    return 0;
}
