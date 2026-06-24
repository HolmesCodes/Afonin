#include <iostream>
#include "Windows.h"
#include <string>
using namespace std;

//enum
enum RunsomEnum {
	first,
	second,
	therd
};
enum Speed {
	MIN = 150,
	RECOMEND = 600,
	MAX = 800
};
class PC
{
public:
	enum PC_State {
		OFF,
		ON,
		SLEEP
	};
	PC_State GetState() { return State; }
	void SetState(PC_State State) { this->State = State; }

private:
	PC_State State;
};
//пространства имен
namespace FirstNS {
	void Foo() {
		cout << "Foo FirstNS" << endl;
	}
}
namespace SecondNS {
	void Foo() {
		cout << "Foo SecondNS" << endl;
	}
}
namespace SecondNS {
	void Foo2() {
		cout << "Foo2 SecondNS" << endl;
	}
}
namespace therdNS {
	namespace SecondNS {
		void Foo() {
			cout << "Foo therdNS" << endl;
		}
	}
}
using namespace SecondNS; //конкретное подключение namespace во всем коде. Не должно быть конфликтов оъектов, функций и тд с другими!!!

int main()
{
    setlocale(LC_ALL, "rus");
	/*PC pc;
	pc.SetState(PC::PC_State::ON);
	if (pc.GetState() == PC::PC_State::ON) {
		cout << "Комп работает!" << endl;
	}

	Speed speed = Speed::MAX;
	cout << speed << endl;
*/

	FirstNS::Foo();
	SecondNS::Foo();
	SecondNS::Foo2();
	therdNS::SecondNS::Foo();
	std::cout << "STD"<<std::endl;
	Foo();
	return 0;
}
