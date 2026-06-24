#include <iostream>
#include <cstring>
using namespace std;



class MyString
{
public:
	MyString(const char *str) {
		length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0;i < length;i++) {
			this->str[i] = str[i];
		}
		this->str[length] = '\0';

	};
	MyString() {
		str = nullptr;
		length = 0;
	};
	MyString(const MyString &other) { //конструктор копирования. без него при копировании 
		//данные будут лежатбь в одной ячейке и не удалятся деструктром
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0;i < length;i++) {
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	};
	MyString& operator =(const MyString &other) {
		if (this->str != nullptr) {
			delete[] str;
		}
		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0;i < length;i++) {
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';

		return *this;
	}

	MyString operator + (const MyString &other) {
		MyString newstr;
		int thisLenght = strlen(this->str);
		int otherLenght = strlen(other.str);
		newstr.length = thisLenght + otherLenght;
		newstr.str = new char[thisLenght+otherLenght+1];

		int i = 0;
		for (;i < thisLenght;i++) {
			newstr.str[i] = this->str[i];
		}
		for (int j = 0;j < otherLenght;j++,i++) {
			newstr.str[i] = other.str[j];
		}
		newstr.str[thisLenght + otherLenght] = '\0';
		return newstr;
	}
	bool operator == (const MyString& other) {
		if (this->length != other.length) {
			return false;
		}
		for (int i = 0; i < this->length;i++) {
			if (this->str[i] != other.str[i]) {
				return false;
			}
		}
		return true;
	}
	bool operator != (const MyString& other) {
		return !(this->operator==(other));
	}
	char &operator [](int index) {
		return this->str[index];
	}
	int Length() {

		return length;
	}

	~MyString() {
		delete[] this->str;
	};
	void Print() {
		cout << str << endl;
	}
	MyString(MyString &&other) { 
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	};

private:
	char *str;
	int length;
};




int main() {



	MyString str("Hello");
	MyString str2("World!");
	MyString result = str + str2;
	result.Print();
	str = str2;
	str.Print();
	str2.Print();
	/*cout << str.Length() << endl;
	cout<<str2.Length()<<endl;

	bool equel = str == str2;
	bool equel2 = str != str2;
	cout << equel <<endl<< equel2<<endl;

	str[0] = 'Q';
	cout << str[0] << endl;
	str.Print();
    */


	return 0;
}