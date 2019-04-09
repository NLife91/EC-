/** Item 24: Declare non-member functions when type conversions should apply to all parameters. */

class Rational
{
public:
	// non-explicit. implicit.
	Rational(int numberator = 0, int denominator = 0);

	int numberator() const;
	int denominator() const;

	const Rational operator*(const Rational& rhs) const;
};

void Test()
{
	Rational oneEighth(1, 8);
	Rational oneHalf(1, 2);

	Rational result = oneHalf * oneEighth; // fine.
	
	result = result * oneEighth; // fine.

	result = oneHalf * 2; // fine.
	
	result = 2 * oneHalf; // error.

	result = oneHalf.operator*(2); // fine.

	result = 2.operator*(oneHalf); // error.

	result = operator*(2, oneHalf); // error.

	// result = oneHalf.operator*(2);
	const Rational temp(2);
	result = oneHalf * temp;
}

class Rational2 : public Rational
{
public:
	Rational2(int numberator = 0, int denominator = 0)
		: Rational(numberator, denominator)
	{}
};

const Rational2 operator*(const Rational2& lhs, const Rational2& rhs)
{
	return Rational2(lhs.numberator() * rhs.numberator(), lhs.denominator() * rhs.denominator());
}

void Test2()
{
	Rational2 oneFourth(1, 4);
	Rational2 result;

	result = oneFourth * 2; // fine.
	result = 2 * oneFourth; // fine.
}

/** Things to Remember
	 * If you need type conversions on all parameters to a function (including the one pointed to by the
       this pointer), the function must be a non-member.
*/
