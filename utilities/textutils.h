#ifndef _TEXTUTILS_H_
#define _TEXTUTILS_H_

#include <iostream>
#include <string>

#define WHITESPACE " \t\f\r\n"

class TextUtils
{
public:
	//static const char *WHITESPACE = " \t\f\r\n";

	TextUtils() {}

	TextUtils(const std::string &s)
		: s_(s) {}

	const char *c_str();

	std::string::size_type size() const { return s_.size(); }

	// to std c++ string
	std::string toString() const { return s_; }

	// Return a copy of string converted to uppercase.
	TextUtils upper() const;

	// Return a copy of the string S converted to lowercase.
	TextUtils lower() const;

	/* Return a copy of the string S with leading and trailing whitespace removed.
     * If chars is given and not None, remove characters in chars instead. */
	TextUtils strip(const char *chars = WHITESPACE) const;

	/* Return a copy of the string S with trailing whitespace removed.
     * If chars is given and not None, remove characters in chars instead. */
	TextUtils rstrip(const char *chars = WHITESPACE) const;

	/* Return a copy of the string S with leading whitespace removed.
     * If chars is given and not None, remove characters in chars instead. */
	TextUtils lstrip(const char *chars = WHITESPACE) const;

private:
	std::string s_;
};


#endif

