#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

class Point {
public:
    Point(){
        x = y = z = 0;
    }
    Point(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    friend ostream& operator<< (ostream& os, const Point& point);
    friend istream& operator>> (istream& is, Point& point);
    /*void Print() {
        cout << "x= " << x << " y=" << y << " z=" << z << endl;
    }*/
private:
    int x;
    int y;
    int z;
};

ostream& operator<< (ostream& os, const Point& point) {
    os << point.x << " " << point.y << " " << point.z;
    return os;
};
istream& operator>> (istream& is, Point& point) {
    is >> point.x >> point.y >> point.z;
    return is;
};

//exception
class MyException : public exception {
public:
    MyException(const char *msg, int dateState):exception(msg) {
        this->dateState = dateState;
    }
    int GetdateState() {
        return dateState;
    }
private:
    int dateState;
};

//бросание разных исключений
void Foo(int value) {
    if (value < 0) {
        //throw exception("Число меньше 0!!!");
        throw "Число меньше 0!!!";
    }if (value == 0) {
        throw exception("Число равно 0!!!");
    }if (value == 1) {
        throw MyException("Число равно 1", value);
    }
    else {
        cout << "Переменная= " << value << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    string nameFile = "FirstFile.tx";
    /*ofstream fout;
    fout.open(nameFile, ofstream::app);
    if (!fout.is_open()) {
        cout << "Ошибка чтения файла" << endl;
    }
    else {
        int a;
        cin >> a;
        fout << a << "\n";
    }
    fout.close();

    //считываем данные из файла
    ifstream fin;
    fin.open(nameFile);
    if (!fin.is_open()) {
        cout << "Ошибка чтения файла" << endl;
    }
    else {
       
        string str;
        cout << "Файл открыт" << endl;
        // char ch;
        // while (fin.get(ch)) {
        //  cout << ch;
        // }
        cout << endl << endl;
        while (!fin.eof()) {
            str = "";
            getline(fin,str);
            cout << str << endl;
        }
    }
    fin.close();
*/
    /*
    Point point(5, 10, 15);
    point.Print();

    ofstream fout;
    fout.open(nameFile, ofstream::app);
    if (!fout.is_open()) {
        cout << "Ошибка чтения файла" << endl;
    }
    else {
        fout.write((char*)&point, sizeof(Point));
    }
    fout.close();

    ifstream fin;
    fin.open(nameFile);
    if (!fin.is_open()) {
        cout << "Ошибка чтения файла" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
        Point pnt;
        while (fin.read((char*)&pnt, sizeof(Point))) {
            pnt.Print();
        }
        
    }
    fin.close();

    Point p(11, 12, 13);
    cout << p;

    fstream fs;
    fs.open(nameFile, fstream::in | fstream::out | fstream::app);
    string msg;
    if (!fs.is_open()) {
        cout << "Ошибка чтения файла" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
        cout << "Введите 1 для записи сообщения в файл" << endl;
        cout << "Введите 2 для считываний сообщений из файла" << endl;
        int a;
        link:
        cin >> a;
        switch (a) {
        case 1:
            cout << "Введите ваше сообщение: ";
            SetConsoleCP(1251);
            cin >> msg;
            fs << msg << "\n";
            SetConsoleCP(866);
            break;
        case 2:
            cout << "Чтение данных из файла: "<<endl;
            while (!fs.eof()) {
                msg = "";
                fs >> msg;
                cout << msg << endl;
            }
            break;
        default:
            goto link;
        }
    }
    fs.close();

Point point;
fstream fs;
fs.open(nameFile, fstream::in | fstream::out | fstream::app);
string msg;

if (!fs.is_open()) {
    cout << "Ошибка чтения файла" << endl;
}
else {
    cout << "Файл открыт" << endl;
   // fs << point << "\n";
    while (!fs.eof()) {
        Point p;
        fs >> p;
        cout << p << endl;
    }
   
}
fs.close(); 
*/

/*ifstream fin;
fin.exceptions(ifstream::badbit | ifstream::failbit); //специфика ifstream
try
{
    cout << "Попытка открыть файл" << endl;
    fin.open(nameFile);
    cout << "файл успешно открыт." << endl;
}
catch (const ifstream::failure & ex) {
    cout << ex.what() << endl;
    cout << ex.code() << endl;
    cout << "Ошибка открытия файла" << endl;
}
    */

int number;
cout << "Write number" << endl;
cin >>number;
try {
    Foo(number);
}
catch (MyException &ex) {
    cout << "Состояние данных "<<ex.GetdateState() << endl;
    cout << "Блок 1: Мы поймали " << ex.what() << endl;
}
catch (exception &ex) {
    cout << "Блок 2: Мы поймали " << ex.what() << endl;
}
catch (const char* ex) {
    cout << "Блок 3: Мы поймали " << ex << endl;
}
catch (...) {
    cout << "Блок 4: Что-то не так" << endl;
}

    return 0;
}

