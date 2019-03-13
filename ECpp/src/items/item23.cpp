/** Item 23: Prefer non-member non-friend functions to memeber functions. */

class WebBrowser
{
public:
	void clearCache();
	void clearHistory();
	void removeCookies();

	// member function
	void clearEverything()
	{
		clearCache();
		clearHistory();
		removeCookies();
	}
};

// Non-member non-friend function
void clearBrowser(WebBrowser& wb)
{
	wb.clearCache();
	wb.clearHistory();
	wb.removeCookies();
}

/** non-member non-friend function is more encapsulated and 
    greater packaging flexibility it yiels fewer compliation dependencies and an increase extensibility */

/** member function can use private member data and function, so member function less encapsulated. */

/** non-member non-friend function can be static function in other class or function in namespace. */

// "webbrowser.h"
namespace WebBrowerStuff
{
	class WebBrowser
	{
	public:
		void clearCache();
		void clearHistory();
		void removeCookies();
	};

	void clearBrowser(WebBrowser& wb); // convenience function.
}

// "webbrowserbookmarks.h"
namespace WebBrowserStuff
{
	// bookmark-related convenience functions.
}

// "webbrowsercookies.h"
namespace WebBrowserStuff
{
	// cookie-related convenience functions.
}
