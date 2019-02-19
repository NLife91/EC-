/** Item 3: Use const whenever possible. */
#include <iostream>
#include <vector>
#include <string>

/** pointer and data with const */
char greeting[] = "Hello";

char* p1 = greeting;				// non-const pointer, non-const data
const char* p2 = greeting;			// non-const pointer, const data
char *const p3 = greeting;			// const pointer, non-const data
const char *const p4 = greeting;	// const pointer, const data

/** parameter type */
void f1(const int* pw); // f1 == f2
void f2(int const* pw);

/** STL iterator */
void stlTest()
{
	std::vector<int> vec{ 1 };

	const std::vector<int>::iterator iter = vec.begin(); // T *const
	*iter = 3;
	//++iter; // error

	std::vector<int>::const_iterator cIter = vec.begin(); // const T*
	//*cIter = 10; // error
	++cIter;
}

/** functio const */
class Rational {};
const Rational operator*(const Rational& lhs, const Rational& rhs);

/** const member function */
class TextBlock
{
public:
	TextBlock(std::string newStr)
		: text(newStr)
	{
	}

	// const member function
	const char& operator[](std::size_t position) const
	{
		return text[position];
	}

	// non-const member function
	char& operator[](std::size_t position)
	{
		return text[position];
	}

private:
	std::string text;
};

void cmfTest()
{
	TextBlock tb("Hello");
	std::cout << tb[0]; // non-const operator[]

	const TextBlock ctb("World");
	std::cout << ctb[0]; // const operator[]
}

/** bitwise(physical) constness and logical constness */

// bitwise constness - it doesn't modify any of the bits inside the object.
class CTextBlock1
{
public:
	char& operator[](std::size_t position) const // bitwise const but pText can modify outside.
	{											 // must const add to front of return type.
		return pText[position];
	}

private:
	char* pText;
};

// logical constness - can modify some of the bits but client cannot detect.
class CTextBlock2
{
public:
	std::size_t length() const
	{
		if (!lengthIsValid)
		{
			textLength = std::strlen(pText);
			lengthIsValid = true;
		}
	}

private:
	char *pText;
	mutable std::size_t textLength; // can modify in const and non-const member function
	mutable bool lengthIsValid;
};

/** Avoiding Duplication in const and non-const member function */
// call const member function with cast in non-const member function;
class Block
{
public:
	const char& operator[](std::size_t position) const
	{
		return text[position];
	}

	char& operator[](std::size_t position)
	{
		return const_cast<char&>( static_cast<const Block&>(*this)[position] );
	}

private:
	std::string text;
};
