#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <queue>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	//map и multimap - хранят древо пар значений (ключ+значение - любых типов данных)
	/*//map-только уникальные, а multimap-дублирующие - аналогия с set и multiset

	//p.first и p.second - ключ и значение

	map<int, string> MyMap;

	map<string, int> MyMap2;

	//4 одинаковых варианта заполнения

	pair<int, string> p(1, "телефон"); // 1,телефон

	MyMap.insert(p); // / \ .

	MyMap.insert(make_pair(2, "самсунг")); // -1,чзхтел 2,самсунг

	MyMap.insert(pair<int, string>(3, "iphone")); // / \ .

	MyMap.emplace(-1, "чзхтел"); // 3,iphone

	MyMap.emplace(4, "ксяоми"); // / \

	//сортировка идет по ключу // 4,ксяоми .

	//поиск по ключу. тип возвращаемого значения - итератор

	auto it = MyMap.find(1);

	//if (it != MyMap.end()) {};

	cout << it->second << endl;

	try {

	MyMap.at(20) = "телефоооончик";

	}

	catch (exception &ex) {

	cout << "Ошибка: " << ex.what() << endl;

	}

	cout << MyMap[3] << endl; // перегружены []

	cout << "Второй map: " << endl;

	MyMap2.emplace("Миша",1);

	MyMap2.emplace("Мaша", 2);

	MyMap2.emplace("Ваня", -4);

	cout << MyMap2["Ваня"];

	multimap <string, int> multimap;

	multimap.emplace("Петя", 69);

	multimap.emplace("Петя", 69);

	multimap.emplace("Миша", 10);

	*/
	//адаптеры контейнеров - не самостоятельные контейнеры:
	//stack
	/*
	stack<int> st;
	st.push(1); //push - копирует объект и переносит копию в колллекцию
	st.emplace(5); //напрямую перемещает объект
	st.emplace(2);
	st.emplace(3);
	st.emplace(4);
	while (!st.empty()) {
	cout << st.top() << endl;
	st.pop();
	}
	//основой стэка является дэк => мы можем обратиться к определенным элементам, но через метод.
	//stack-лишь оболочка deque.
	auto a = st._Get_container();
	cout << endl<<a[2] << endl;
	//чтобы поменять контейнер - в начале указать его
	stack<int,list<int>> st2;
	auto b = st2._Get_container();
	*/
	//queue + priority_queue
	/* //присутствуют только те методы, которые не нарушают принцип очереди
	//не все контейнеру могут быть в основе кадаптивных контейнеров
	queue<int> q;
	queue<int, list<int>> q2;
	priority_queue<int> q3;
	q.emplace(1);
	q.emplace(2);
	q.emplace(3);
	auto a = q._Get_container();
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
		cout << "осталось столько элементов:" << q.size() << endl;
	}
	q3.push(1);
	q3.push(24);
	q3.push(3);
	q3.push(41);
	while (!q3.empty()) {
		cout << q3.top();
		q3.pop();
		cout << "осталось столько элементов:" << q3.size() << endl;
	}
	*/
	//
	return 0;
}