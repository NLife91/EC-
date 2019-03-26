/** Item 28: Avoid returning "handles" to object internals. */

#include <iostream>

class Point
{
public:
	Point(int x, int y);

	void setX(int newVal);
	void setY(int newVal);
};

struct RectData
{
	Point ulhc;
	Point lrhc;
};

class Rectangle
{
public:
	Rectangle(const Point& p1, const Point& p2)
		: pData(new RectData{p1, p2})
	{}

	Point& upperLeft() const { return pData->ulhc; }  // avoid
	Point& lowerRight() const { return pData->lrhc; } // avoid

private:
	std::shared_ptr<RectData> pData;
};

void avoid()
{
	Point coord1(0, 0);
	Point coord2(100, 100);

	const Rectangle rec(coord1, coord2);

	rec.upperLeft().setX(50); // wrong
}

// First, a data member is only as encapsulated as the most accessible function returning a reference to it.
// Second, if a const member function returns a reference to data associated with an object that is stored outside
// the object itself, thecaller of the function can modify that data.

// References, pointers, and iterators are all handles.
// Interanls are data member and member functions.

// Solution
class Rectangle2
{
public:
	Rectangle2(const Point& p1, const Point& p2)
		: pData(new RectData{p1, p2})
	{}

	const Point& upperLeft() const { return pData->ulhc; }
	const Point& lowerRight() const { return pData->lrhc; }

private:
	std::shared_ptr<RectData> pData;
};

void solution()
{
	Point coord1(0, 0);
	Point coord2(100, 100);

	const Rectangle2 rec(coord1, coord2);

	rec.upperLeft().setX(50); // error
}

// Dangling handle problem

class GUIObject {};

const Rectangle2 boundingBox(const GUIObject& obj);

void dangling()
{
	GUIObject* pgo;

	const Point* pUpperLeft = &(boundingBox(*pgo).upperLeft());
	// 1. boundingBox(*pgo) return temp Rectangle2 object
	// 2. pUpperLeft gets a temp Rectangle2 object's upperLeft address.
	// 3. At the end of the statement, temp is deleted.
	// 4. pUpperLeft has a wrong address.
}
