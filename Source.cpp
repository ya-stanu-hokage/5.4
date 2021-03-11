#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <iomanip>
#include <sstream>

int main(int argc, char** argv)
{
	std::string data = "2002:02:21 1010:02:01 1010:02:32 1100:13:22 123:02:13 2021:03:09 12:01:10 8:15:12 00:00:00 23:59:59 14:00:00 24:00:00 25:00:00";

	std::stringstream ss_1(data);
	std::stringstream ss_2(data);

	std::regex pattern_date(R"(^[0-9]{4}:(([0][0-9])|([1][0-2])):(([0-2][0-9])|([3][0-1]))$)");
	std::regex pattern_time(R"(^(([0-1][0-9])|([2][0-4]))(:[0-5][0-9]){2}$)");

	std::cout << "Date:" << std::endl;
	for (std::string s; std::getline(ss_1, s, ' '); )
	{
		std::smatch matches;
		if (std::regex_search(s, matches, pattern_date))
			std::cout << matches[0] << std::endl;
	}

	std::cout << std::endl << "Time:" << std::endl;
	for (std::string s; std::getline(ss_2, s, ' '); )
	{
		std::smatch matches;
		if (std::regex_search(s, matches, pattern_time))
			std::cout << matches[0] << std::endl;
	}

	return 0;
}