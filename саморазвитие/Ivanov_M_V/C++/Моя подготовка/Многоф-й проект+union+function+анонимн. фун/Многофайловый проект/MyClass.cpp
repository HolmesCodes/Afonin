#include "MyClass.h"
namespace Print {
MyClass::MyClass() {}
MyClass::~MyClass() {}

	void MyClass::PrintMessage(const char str[])
	{
		std::cout << str << std::endl;
	}
	void MyClass::Msg()
	{
		std::cout << "Msg!" << std::endl;
	}
	void MyClass::Lampda()
	{
		auto fo = [this]() {
			this->Msg();
		};
		fo();
	}
}
