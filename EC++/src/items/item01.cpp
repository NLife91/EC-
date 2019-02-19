/** Item 1: View C++ as a federation of languages. */

#include <stdio.h>
#include <iostream>
#include <list>

#include "item.h"

class Item01 : public Item
{
	virtual void itemExe() override
	{

	}
};

class TempClass
{
public:
	int GetInteger() { return integer; }
	void SetInteger(int newInt) { integer = newInt; }

private:
	int integer;
};

template<typename T>
class TemplateClass
{
public:
	T value;
};

void item01()
{
	/** C */
	printf("Hello World! %d \n", 1);

	/** C++ */ 
	TempClass temp{ }; 
	temp.SetInteger(2);
	std::cout << "Hello World! " << temp.GetInteger() << std::endl;

	/** Template C++ */
	TemplateClass<TempClass> templateTemp{ };
	templateTemp.value.SetInteger(3);
	std::cout << "Hello World! " << templateTemp.value.GetInteger() << std::endl;

	/** STL */
	std::list<int> tempList{ 4 };
	std::cout << "Hello World! " << tempList.front() << std::endl;
}
