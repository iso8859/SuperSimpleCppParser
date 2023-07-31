#pragma once
// Use vcpkg to install jsoncpp
// .\vcpkg.exe install jsoncpp:x64-windows-static

#include <json/json.h>
#include <string>

class SuperSimpleCppParser
{
public:
	Json::Value CLP;
	void ParseCLP(int argc, char** argv);
	void PrintCLP();
};
