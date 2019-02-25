/** Store newed objects in smart pointers in standalone statements. */

#include <iostream>

class Widget {};

int priority();

void processWidget(std::shared_ptr<Widget> pw, int priority);

void leakResource()
{
	// can leak Resource.
	processWidget(std::shared_ptr<Widget>(new Widget), priority());

	// leak scenario.
	// 1. Execute new Widget
	// 2. Call priority() -> exception
	// 3. Call shared_ptr constructor -> dont called.

	std::shared_ptr<Widget> pw(new Widget);

	processWidget(pw, priority());
}
