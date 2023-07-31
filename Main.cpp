#include "SuperSimpleCppParser.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	SuperSimpleCppParser parser;
	parser.ParseCLP(argc, argv);
	int t= parser.CLP.get("t", 0).asInt();
	string v = parser.CLP.get("v", "default").asString();

	if (parser.CLP.get("dump", false).asBool())
		parser.PrintCLP();
}