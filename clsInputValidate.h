#pragma once
#include "clsDate.h"
class clsInputValidate
{
public:
	template <typename T> static bool IsNumberBetween(T number, T from, T to)
	{
    	return number >= from && number <= to;
	}
	

	static bool IsDateBetween(clsDate date, clsDate date1, clsDate date2)
	{
		if (date.CompareDates(date1) == clsDate::Equal || date.CompareDates(date2) == clsDate::Equal)
		{
			return true;
		}

		if (date1.IsDateBefore(date2))
		{
			return date.CompareDates(date1) == clsDate::After && date.CompareDates(date2) == clsDate::Before;
		}
		else
		{
			return date.CompareDates(date2) == clsDate::After && date.CompareDates(date1) == clsDate::Before;
		}

	}

	static string ReadString()
	{
		string  str = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, str);
		return str;
	}

	static string ReadString(string message)
	{
		string  str = "";
		cout << message;
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, str);
		return str;
	}

	template <typename T> static T ReadNumber(string errorMessage = "Invalid Number, Enter again\n")
	{
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
		}
		return Number;
	}

	template <typename T> static T ReadNumberBetween(T from, T to, string errorMessage = "Number is not within range, Enter again:\n")
	{
		T number = ReadNumber<T>();
		while (!IsNumberBetween(number, from, to))
		{
			cout << errorMessage;
			number = ReadIntNumber();
		}
		return number;
	}

};

