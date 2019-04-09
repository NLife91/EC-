/** Item 10: Have assignment operators return a reference to *this. */

int convention()
{
	int x, y, z;
	x = y = z = 15;
	x = (y = (z = 10));
}

class Widget
{
public:
	Widget& operator=(const Widget& rhs)
	{
		return *this;
	}

	Widget& operator+=(const Widget& rhs) // -=, *=
	{
		return *this;
	}

	Widget& operator=(int rhs)
	{
		return *this;
	}
};

/** Things to Remember
	 * Have assignment operators return a reference to *this.
*/
