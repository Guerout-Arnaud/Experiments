#include <iostream>
#include <regex>

int main(int argc, char **argv)
{
    if (!argv[1]) {
        std::cout << "Usage: " << argv[0] << " string_to_test" << std::endl;
        return (-1);
    }

    // std::string str("geeksforgeeks");
    // std::regex reg("(geeks)(.*)");

    std::string str = argv[1];
    std::regex reg("^.*lib(.*?)\\.so$");

    std::smatch match;

    if (std::regex_search(str, match, reg)) {

        std::cout << "match.size(): " << match.size() << std::endl;

        std::cout << "Text contains a .so file'\n";
        std::cout << "Whole match : " << match.str(0) << std::endl;
        std::cout << "First capturing group is '" << match.str(1)
             << "' which is captured at index " << match.position(1)
             << std::endl;
        // std::cout << "Second capturing group is '" << match.str(2)
        //      << "' which is captured at index " << match.position(2)
        //      << std::endl;


    }

    auto words_begin =
        std::sregex_iterator(str.begin(), str.end(), reg);
    auto words_end = std::sregex_iterator();

    std::cout << "Found "
              << std::distance(words_begin, words_end)
              << " word\n";


    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();

        std::cout << "  " << match_str << '\n';
        // if (match_str.size() > N) {
        // }
    }

    return 0;
}