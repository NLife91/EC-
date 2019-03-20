/** Item 27: Minimize casting. */

#include <memory>
#include <vector>

// Old-style casts.
void oldStyle()
{
	int x = 1;

	double y = (double)x; // (T) expression

	double z = double(x); // T(expression)
}

// C++-style casts.
class Base { public : virtual ~Base() = default; };
class Derived : public Base { public : Derived() = default; };

struct Struct1 { int a; };

void cppStyle()
{
	// const_cast<T>(expression)
	// cast away the constness
	const int a = 1;
	int* b = const_cast<int*>(&a);

	// dynamic_cast<T>(expression)
	// safe downcasting.
	Base* c = new Base();
	Derived* d = dynamic_cast<Derived*>(c);

	// reinterpret_cast
	// low-level cast.
	Struct1 e;
	e.a = 20;
	int* f = reinterpret_cast<int*>(&e);

	// static_cast
	// force implicit conversions
	Derived* g = new Derived();
	Base* h = static_cast<Base*>(g);
	Derived* i = static_cast<Derived*>(h);
}

class Window
{
public:
	virtual void onResize() {}
};

class SpecialWindow : public Window
{
public:
	virtual void onResize() override 
	{
		// wrong
		static_cast<Window>(*this).onResize(); // create temp Window object and temp object's onResize calls.

		// correct
		Window::onResize();
	}
};

// Avoid dynamic_casts
class Window1 
{ 
	virtual ~Window1() = default; 
};

class SPWindow1 : public Window1
{
public:
	void blink();
};

typedef std::vector<std::shared_ptr<Window1>> VPW;

void bad()
{
	VPW winPtrs;

	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter)
	{
		if (SPWindow1* psw = dynamic_cast<SPWindow1*>(iter->get()))
		{
			psw->blink();
		}
	}
}

// use type-safe container.
typedef std::vector<std::shared_ptr<SPWindow1>> VPSW;

void good1()
{
	VPSW winPtrs;

	for (VPSW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter)
	{
		(*iter)->blink();
	}
}

// use virtual function.
class Window2 
{ 
public: 
	virtual void blink() {} 
};

class SPWindow2 : public Window2 
{ 
public: 
	virtual void blink() override {} 
};

typedef std::vector<std::shared_ptr<Window2>> VPW;

void good2()
{
	VPW winPtrs;

	for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter)
	{
		(*iter)->blink();
	}
}
