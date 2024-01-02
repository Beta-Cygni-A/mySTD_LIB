#ifndef HEADONLY_H
#define HEADONLY_H

#include <iostream>
#include <string_view>

class Functest //for testing inline class member functions
{
private: 
	int m_a {};

public:
	Functest(int a)
		: m_a { a }
	{}
	
	template <typename... Q1>

	inline void print(const Q1&... args);

};

	template <typename... Q1>

	inline void Functest::print(const Q1&... args)
	{	        
		((std::cout << [&args]() { return ((args == "nLN") ? "\n" : (args == "nSP") ? " " : args);}() << ""), ...);
	}

namespace mySTD // for implementing features wanted and knockoffs of features currently unavailable to me
{
	template <typename... Q1>

	inline void printAln(const Q1&... args)
	{
	        ((std::cout << args << " "), ...);
	}

	template <typename... Q1>

	inline void printNln(const Q1&... args)
	{
	        ((std::cout << args << "\n"), ...);
	}

/*
	inline auto checkArgs(const auto& args)
	{
		return ((args == "\n") ? "\n" : (args == "") ? " " : args);
	}
*/
	template <typename... Q1>

	inline void prinT(const Q1&... args)
	{	        
		((std::cout << [&args]() { return ((args == "\n") ? "\n" : (args == "") ? " " : args);}() << ""), ...);

//		((std::cout << checkArgs(args) << ""), ...);
	}
};

#endif
