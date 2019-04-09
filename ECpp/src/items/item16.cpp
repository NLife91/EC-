/** Item 16: Use the same form in corresponding uses of new and delete. */

#include <string>

void corresponding()
{
	std::string* stringPtr1 = new std::string; // an Object
	std::string* stringPtr2 = new std::string[100]; // Array of Objects

	delete stringPtr1; // an Object
	delete[] stringPtr2; // Array of Objects
}

/** Things to Remember
	 * If you use [] in a new expression, you must use [] in the corresponding delete expression. If
       you don't use [] in a new expression, you mustn't use [] in the corresponding delete
       expression.
*/