/** Item 15: Provide access to raw resources in resource-managing classes. */

#include <iostream>

/** Explicit conversion. */
class Investment
{
public:
	bool isTaxFree() const;
};

Investment* createInvestment();

void explicitConversion()
{
	std::shared_ptr<Investment> pi1(createInvestment());

	// explicit conversion.
	Investment* pInv = pi1.get(); 

	// access resource with ->, *(dereference) operator.
	bool taxable1 = !(pi1->isTaxFree());
	bool taxable2 = !((*pi1).isTaxFree());
}

/** Implicit conversion. */
class FontHandle {};

FontHandle getFont();

void releaseFont(FontHandle fh);

class Font
{
public:
	explicit Font(FontHandle fh)
		: f(fh)
	{}

	~Font() 
	{
		releaseFont(f);
	}

	// implicit conversion.
	operator FontHandle() const
	{
		return f;
	}

private:
	FontHandle f;
};

void changeFontSize(FontHandle f, int newSize);

void implicitConversion()
{
	Font f(getFont());
	int newFontSize;

	FontHandle f2 = f; // meant to copy a Font, but copy FontHandle

	changeFontSize(f, newFontSize);
}
