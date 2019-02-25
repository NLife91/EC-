/** Item 11: Handle assignment to self in operator= */

/** Problem of self assignment */
class Bitmap
{};

class Widget1
{
public:
	Widget1()
	{
		pb = new Bitmap();
	}

	Widget1& operator=(const Widget1& rhs)
	{
		delete pb;
		pb = new Bitmap(*rhs.pb);

		return *this;
	}

private:
	Bitmap* pb;
};

void same()
{
	Widget1 w;
	w = w; // error *rhs.pb 
}

/** Solve 1: Identity test */
class Widget2
{
	Widget2& operator=(const Widget2& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		delete pb;
		pb = new Bitmap(*rhs.pb); // can exception 

		return *this;
	}

private:
	Bitmap* pb;
};

/** Solve 2 : value copy */
class Widget3
{
	Widget3& operator=(const Widget3& rhs)
	{
		Bitmap* pOrig = pb;
		pb = new Bitmap(*rhs.pb);
		delete pOrig;

		return *this;
	}

private:
	Bitmap* pb;
};

/** Solve 3: Copy and swap */
class Widget4
{
	Widget4& operator=(const Widget4& rhs)
	{
		Widget4 temp(rhs);

		swap(temp);

		return *this;
	}

	void swap(Widget4& rhs)
	{
		this->pb = rhs.pb;
	}

private:
	Bitmap* pb;
};