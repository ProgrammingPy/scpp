#include <cctype>
#include "textutils.h"

//whitespace characters
//static const char *whitespace = " \t\f\r\n";

// to c style string
const char* TextUtils::c_str() 
{
	return s_.c_str();
}


//Return a copy of string converted to uppercase.
TextUtils TextUtils::upper() const
{
	TextUtils text;

	for (size_t cnt = 0; cnt < s_.size(); cnt++)
		text.s_.push_back(std::toupper(s_[cnt]));

	return text;
}

// Return a copy of the string S converted to lowercase.
TextUtils TextUtils::lower() const
{
	TextUtils text;

	for (size_t cnt = 0; cnt < s_.size(); cnt++)
		text.s_.push_back(std::tolower(s_[cnt]));

	return text;
}


/* Return a copy of the string S with trailing whitespace removed.
 * If chars is given and not None, remove characters in chars instead. */
TextUtils TextUtils::rstrip(const char *chars) const
{
	TextUtils text(s_);

	size_t start = text.s_.find_last_not_of(chars);
	if (start != std::string::npos) {
		text.s_.erase(start + 1);
	}

	return text;
}


/* Return a copy of the string S with leading whitespace removed.
 * If chars is given and not None, remove characters in chars instead. */
TextUtils TextUtils::lstrip(const char *chars) const
{
	TextUtils text(s_);

	size_t start = text.s_.find_first_not_of(chars);
	if (start != std::string::npos) {
		text.s_.erase(0, start);
	}

	return text;
}

/* Return a copy of the string S with leading and trailing whitespace removed.
 * If chars is given and not None, remove characters in chars instead. */
TextUtils TextUtils::strip(const char *chars) const
{
	TextUtils text(s_);

	//delete leading characters 
	TextUtils stemp = text.lstrip(chars);

	//delete trailing
	return stemp.rstrip(chars);
}