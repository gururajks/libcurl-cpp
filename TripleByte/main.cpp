#include "pch.h"
#include <thread>
#include <vector>
#include "CurlWrapper.h"
#include <mutex>
#include <regex>

#include <iostream>
#include <string>
#include <curl/curl.h>
using namespace std;


// This is just checking that your compiler can handle this syntax (some compilers get confused by the ">>")
std::vector<std::vector<int>> syntax_test_vector;

void crawl_url(std::string uri) {
    CurlResult result = CurlWrapper::request(uri);

    std::cout << result.response_body << std::endl;
}

/*
 * This checks that your compiler can handle regexes
 */
void checkRegexSupport() {
    try {
        std::regex_match("123",std::regex("^(0|[1-9][0-9]*)$"));
    } catch (std::regex_error& e) {
        std::cout << "This project requires regex support." << std::endl
                  << "GCC users need version 4.9.0 or later." << std::endl
                  << "CLang users need 3.3 or later." << std::endl;
        exit(1);
    }
}

int main()
{
    checkRegexSupport();

    std::cout << "If this project compiles and runs, you're ready for the Triplebyte interview!" << std::endl;

    std::thread t (&crawl_url, "https://www.google.com");

    t.join();

    return 0;
}