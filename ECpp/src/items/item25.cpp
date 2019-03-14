/** Item 25: Consider support for a non-throwing swap. */

#include <vector>

// pimpl idiom (pointer to implementation)
class WidgetImpl
{
private:
	int a, b, c;
	std::vector<double> v;
};

class Widget
{
public:
	Widget() = default;

	Widget(const Widget& rhs);

	Widget& operator=(const Widget& rhs)
	{
		*pImpl = *(rhs.pImpl);
	}

	void swap(Widget& other)
	{
		using std::swap;

		swap(pImpl, other.pImpl);
	}

private:
	WidgetImpl* pImpl;
};

void Test()
{
	Widget a, b;
	
	std::swap(a, b); // 3 copy Widget and 3 copy WidgetImpl
}

/** total template specialization. */
namespace std
{
	template<>
	void swap<Widget>(Widget& a, Widget& b)
	{
		a.swap(b);
	}
}

/** if template class. */

template<typename T>
class TWidgetImpl {};

template<typename T>
class TWidget { void swap(TWidget<T>& other); };

// error. std doesn't allow for function parially specialize.
namespace std
{
	template<typename T>
	void swap<TWidget<T>>(TWidget<T>& a, TWidget<T> b) 
	{
		a.swap(b);
	}  
}

/** use non-member function */
// undefinded.
namespace std
{
	template<typename T>
	void swap(TWidget<T>& a, TWidget<T>& b)
	{
		a.swap(b);
	}
}

// The name lookup rules. argument-dependent lookup or Koenig lookup.
namespace WidgetStuff
{
	template<typename T>
	class TWidget2 { void swap(TWidget2<T>& other); };

	template<typename T>
	void swap(TWidget2<T>& a, TWidget2<T>& b)
	{
		a.swap(b);
	}
}

template<typename T>
void doSomething(T& obj1, T& obj2)
{
	using std::swap;

	swap(obj1, obj2);
	std::swap(obj1, obj2); // wrong
}

/** 1. using std::swap when efficiency for your class. */
/** 2. when not efficient. */
	// a. Offer a public swap member function it should never throw an exception.
	// b. Offer a non-member swap in the same namespace as your class.
	// c. specialize std::swap for your class.

/** 3. if calling swap, be sure to include a using. and call swap without any namespace. */

/** member swap function never throw exceptions. */
