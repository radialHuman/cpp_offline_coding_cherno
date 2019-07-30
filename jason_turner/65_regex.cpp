//https://www.youtube.com/watch?v=IOxKjqC1Ozo

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

/*
 *
 */

void dump_regex_match(const std::cmatch& m)
{
    std::cout << "Matches\n";
    for(std::size_t i=0; i< m.size(); ++i)
    {
        std::cout << i << " :" << m.str(i) << "\n";
    }

}

int main()
{
    std::regex regex(R"((\d+): \[([^\]]+)\] (.*))"); // creating a pattern
    // for a string like : 123: [Error] something about the error
    std::cmatch match;
    std::regex_match("123: [Error] something about the error",match,regex);
    // to display the match list
    dump_regex_match(match);
}

/*
 * OUTPUT
Matches
0 :123: [Error] something about the error
1 :123
2 :Error
3 :something about the error
 */