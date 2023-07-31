#include "SuperSimpleCppParser.h"
#include <iostream>

using namespace std;

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

// We convert the command line into a json object
void SuperSimpleCppParser::ParseCLP(int argc, char** argv)
{
	string lastParam;
	for (int i = 1; i < argc; i++)
	{
		string v = argv[i];
		if (v.find("-") == 0 || v.find("/") == 0)
		{
			lastParam = v.substr(1);
			CLP[lastParam] = true;
		}
		else
		{
			if (lastParam.length() > 0)
			{
				CLP[lastParam] = v;
				if (is_number(v))
					CLP[lastParam] = stoi(v);
				lastParam = "";
			}
		}
	}
}

void SuperSimpleCppParser::PrintCLP()
{
	cout << CLP.toStyledString() << endl;
}
