/** Item 20: Prefer pass-by-reference-to-const to pass-by-value. */

#include <iostream>
#include <string>

class Person
{
public:
	Person();
	virtual ~Person();

private:
	std::string name;
	std::string address;
};

class Student : public Person
{
public:
	Student();
	~Student();

private:
	std::string schoolName;
	std::string schoolAddress;
};

bool validateStudent(Student s)
{
	// Call Student constructor
	// Call Person constructor
	// Call string constructor
	// Call string constructor
	// Call string constructor
	// Call string constructor
	// 6 constructors called.

	// ...

	// Call string destructor
	// Call string destructor
	// Call string destructor
	// Call string destructor
	// Call Person destructor
	// Call Student destructor
	// 6 destructor called.
}

bool validateStudent2(const Student& s)
{
	// constructor and destructor haven't called.
}

/** Slicing problem. */

class Window
{
public:
	std::string name() const
	{
		return "Windows";
	}

	virtual void display() const
	{
		std::cout << "Window display()" << std::endl;
	}
};

class WindowWithScrollBars : public Window
{
public:
	virtual void display() const override
	{
		std::cout << "WindowWithScrollBars display()" << std::endl;
	}
};

void printNameAndDisplay(Window w)
{
	// slicing WidowWithScrollBars parts.
	std::cout << w.name();
	w.display();
}

void printNameAndDisplay2(const Window& w)
{
	std::cout << w.name();
	w.display();
}

/** pass-by-value. */

// built-in types. int, double...
// STL iterator. std::list<>::iterator.
// function object types.

/** Things to Remember
	 * Prefer pass-by-reference-to-const over pass-by-value. It's typically more efficient and it avoids the
       slicing problem.
       
	 * The rule doesn't apply to built-in types and STL iterator and function object types. For them, pass-
       by-value is usually appropriate.
*/
