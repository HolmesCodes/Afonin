#include <iostream>
#include "Windows.h"
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <set>

using namespace std;
//библиотека стандартых шаблонов STL
//итераторы - сущности, кот нужны для взаимодействия эл-ов в контейнерах. +- умные указатели
/*list - реализация двусвязного списка - контейнера.
  В list нет перегрузки [] => нет возможности обращаться к объекту напрямую
*/
void conclusion(vector<int>myVector) {
	//for (int i = 0; i < myVector.size(); i++) {}
	cout << "VECTOR:" << endl;
	for (auto index : myVector) {
		cout << index << "\t";
	}
}
void conclusion(list<int>myList) {
	//for (int i = 0; i < myVector.size(); i++) {}
	cout << "LIST:" << endl;
	for (auto index : myList) {
		cout << index << "\t";
	}
}
//++i - префиксный инкремент используется в цикле для более быстрой работы компилятора
//так как при постфикснойм инкременте или декременте компьютер создает доп. переменную и хранит ее в памяти
template <typename T>
void PrintList(const list<T>& lst) {
	for (auto i = lst.begin(); i != lst.end(); ++i) {
		cout << *i << endl;
	}
}
template <typename T>
void PrintList(const forward_list<T>& lst) {
	for (auto i = lst.begin(); i != lst.end(); ++i) {
		cout << *i << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	//vector - обертка для динамического массива
	/*cout << "Vector" << endl;
	vector<int> myVector = {1,2,3,4,5,6,7,8,9,10};
	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);

	myVector.at(1) = 101; //at-никогда не даст получить НЕ свои данные! Но н медленнее, чем []
	myVector[0] = 100;
	try {
		cout <<myVector.at(20) << endl;
	}
	catch (const out_of_range & ex) {
		cout << "Обращеие к несуществующему эл-ту. Ошибка: "<<ex.what() << endl;
	}

	//myVector.clear(); //все эл-ты удалить
	myVector.pop_back(); //удаление последнего эл-та

	conclusion(myVector); //вывод эл-ов vector

	cout << endl<<"Кол-во эл-ов size " << myVector.size()<<endl;//размер vector
	cout<<"Кол-во эл-ов capacity "<<myVector.capacity()<<endl; //кол-во памяти которое выделено уже под vector

	myVector.reserve(100);//выделяем для capacity 100 эл-ов
	cout << "Кол-во эл-ов capacity " << myVector.capacity()<<endl;
	myVector.shrink_to_fit(); //метод для обрезки неиспользованной памяти под size
	cout << "Кол-во эл-ов capacity " << myVector.capacity()<<endl;
	cout << myVector.empty()<<endl; //false -эл-ты есть
	myVector.clear();
	cout << myVector.empty() << endl; //trur - эл-ты есть
	myVector.resize(20,448); //обнуление вектора, выделение 20 эл-ов и присвоение им всем 448
	conclusion(myVector);
	*/
	/*int arr[] = {1,2,3};
	cout << arr[1]<<endl;
	cout << "Арифметика указателей "<< * (arr + 1) << endl;*/
	//iterator - обертка для перебора коллекции
	/*vector<int> myVector2 = {1,2,3,4,5,6,7,8,9,10};
	vector<int>::iterator it; // vector<int>::   - это тип данных итератора
	it = myVector2.begin(); //begin() в рез работы возвращ итератор на первый элемент
	cout << *it << endl;
	*it = 1000;
	cout << *it << endl;
	it++; //передвигаемся по индексам эл-ов в vector
	cout << *it << endl;
	it += 2;
	it--;
	cout << *it << endl;

	for (vector<int>::iterator it2 = myVector2.begin(); it2 != myVector2.end(); it2++) { //добавить <const_iterator> после "vector<int>::" чтобы не было возможности изменить it2
		cout << *it2 << endl;
	}
	cout << "reverse_iterator:" << endl;
	for (vector<int>::reverse_iterator it2 = myVector2.rbegin(); it2 != myVector2.rend(); it2++) {
		//добавить <reverse_iterator> после "vector<int>::" чтобы не было возможности изменить it2 + "rbegin" + "rend"
		cout << *it2 << endl;
	}
	vector<int>::iterator it = myVector2.begin();
	cout << *it << endl;
	advance(it, 3); //cout<<*(it+3)<<endl;  - сдвиг
	cout << *it << endl;

	for (vector<int>::iterator it2 = myVector2.begin(); it2 != myVector2.end(); it2++) {
		cout << *it2 << endl;
	}

	vector<int>::iterator it = myVector2.begin();
	vector<int>::iterator itErase = myVector2.begin();
	itErase += 2;
	cout << " erase " << endl;
	myVector2.erase(itErase);
	itErase = myVector2.begin();
	myVector2.erase(itErase+7, itErase + 9); //удаление диапазона значений
	for (vector<int>::iterator it2 = myVector2.begin(); it2 != myVector2.end(); it2++) {
		cout << *it2 << endl;
	}

	cout << " insert " << endl;
	myVector2.insert(it, 999); //после вставки итератор становится недействительным и требуется ему заного дать значение
	it = myVector2.begin();
	advance(it, 4);
	myVector2.insert(it, 444);
	for (vector<int>::iterator it2 = myVector2.begin(); it2 != myVector2.end(); it2++) {
		cout << *it2 << endl;
	}
	*/
	//list - полносвязный список
	/*list<int> myList = {1,2,3};
	myList.push_back(0);
	myList.push_front(4);
	/*list<int>::iterator it = myList.begin(); //-можно и так
	auto it = myList.begin();
	conclusion(myList);
	for (auto i = myList.begin(); i != myList.end(); i++) {
		cout << *i << endl;
	}
	PrintList(myList);
	 
	myList.sort(); //сортировка list
	cout << "sort:" << endl;
	PrintList(myList);

	myList.pop_back();  //удаление последнего эл-та
	cout << "pop_back:" << endl;
	PrintList(myList);

	myList.push_back(4);
	myList.push_front(4);
	myList.push_front(4);
	myList.push_front(4);
	cout << "добавление эл-ов" << endl;
	PrintList(myList);

	myList.unique(); //удаление дубликатов, которые находятся рядом друг с другом
	cout << "unique:" << endl;
	PrintList(myList);

	auto it = myList.begin();
	it = myList.insert(it, 11); // insert возвращает итератор на вставленный элемент
	cout << "insert:" << endl;
	PrintList(myList);

	it = myList.begin();
	advance(it, 5); // передвижение итератора на 10 позиций вперед
	myList.insert(it, 22); // вставляем другое значение для наглядности
	cout << "advance:" << endl;
	PrintList(myList);
	*/
	//forward_list - укороченный односвязный list
	/*//реализация односвязного списка //контейнер меньше list
	forward_list<int> fl = {4,5,6};
fl.push_front(1);
fl.push_front(2);
fl.push_front(3);
forward_list<int>::iterator it = fl.begin();
fl.insert_after(it, 2);
PrintList(fl);
//it--; декремент в forward_list не работает так как элементы в списке не хранят предыдущее значение
it = fl.begin();
it++;
fl.erase_after(it);
PrintList(fl);
//before_begin-присвоить итератору и всавить после него. это типо ДО первого числа в списке
*/
	//array - массив из четкого кол-ва объектов при объявлении
	/*array<int, 10> arr = {1,2,3,4,5,6,7,8,9,10}; //нельзя добавлять или удалять эл-ты
	try {
		cout << arr.at(120) << endl; //обращение к элементу массива и проверка на существование этого эл-та. типо []
	}
	catch (const exception &ex) {
		cout << ex.what() << endl;
	}
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
	arr.fill(-1); //заполнение массива -1 на всех позициях
	//arr.back() и arr.front() - доступ к последнему и первому эл-ам
	*/
	//перегрузка операторов сравнения для всех контейнеров
    /*array<int, 4> arr = {1,94,77,9};
array<int, 4> arr2 = { 1,94,77,9 };
bool result = arr == arr2; 
//bool result = arr > arr2;
//bool result = arr <= arr2;
cout << result << endl;*/
	//deque - двусторонняя очередь 
	/* //компромисс между list и vector - выделение по неболшим отрезочкам в разных местах памяти
deque<int> dq = { 1,2,3,4,5 };
deque<int>::iterator it;
	*/
	//SET|MULTISET
	/* 
	//set-бинарное дерево. Упорядоченное множество
set<int> Myset;
Myset.insert(5);//                    5
//								     / \                                    .
Myset.insert(1);//	(1<5)	        1   7
Myset.insert(7);//  (7>5)          / \ / \                                   .
Myset.insert(4);// (4<5)+(4>1)   -1  4 6
Myset.insert(-1);//(-1,5)+(-1<1)
Myset.insert(6);//(5>6)+(6<7)
cout << "Myset1: " << endl;
for (auto &el : Myset) {
	cout << el << endl; //вывод: от меньшего к большему
}

cout << "Myset2: " << endl;
set<int> Myset2 = { 1,100,2,200,3,300 };
for (auto& el : Myset2) {
	cout << el << endl; //также сам упорядочил
}

Myset.insert(10);
Myset.insert(10); //не добавятся копии элементов
Myset.insert(10); //не добавятся копии элементов
Myset.erase(10); //удаление числа 10

cout << "Myset3: " << endl;
set<int> Myset3;
for (int i = 0;i < 20;++i) {
	Myset3.insert(rand() % 10); //попали только уникальные значения несмотря на 20 проходов цикла
}
for (auto& el : Myset3) {
	cout << el << endl;
}

//auto it = Myset.find(10); //поиск числа в скобках по set и возврат итератора, указывающего на это число

int value;
cout << "введите число для его поиска в set в Myset2: ";
cin >> value;
if (Myset2.find(value) != Myset2.end()) {
	cout << endl << "число " << value << " найдено" << endl;
}else {
	cout << "число " << value << " НЕ найдено" << endl;
}

auto result = Myset.insert(1000); //число+bool (смог осуществить вставку или нет)

//multiset - позволяет добавить несколько одинаковых элементов
multiset<int> MyMultiset = { 34,4,9,1,34,50,100,3,71 };
cout << "MyMultiset: " << endl;
for (auto& el : MyMultiset) {
	cout << el << endl;
}

auto it1 = MyMultiset.lower_bound(34); //возврат первого в списке числа 34
auto it2 = MyMultiset.upper_bound(34); //ввывод следующего элемента после 34
auto it2 = MyMultiset.equal_range(34); //возвращает диапазон чискл от upper_bound до lower_bound
*/
return 0;
}
