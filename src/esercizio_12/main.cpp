#include "rimuovi_singoli_spazi.h"
#include <iostream>

int main() {
    std::string test1 = " a b c ";
    std::string test2 = "  a  b  c  ";
    std::string test3 = "  abc   def ghi   jkl    mno pqr  s ";
    
    std::cout << "Test: \"" << test1 << "\"" << std::endl;
    std::cout << "RimuoviSingoliSpazi01: \"" << RimuoviSingoliSpazi01(test1) << "\"" << std::endl;
    std::cout << "RimuoviSingoliSpazi02: \"" << RimuoviSingoliSpazi02(test1) << "\"" << std::endl;
    std::cout << "RimuoviSingoliSpazi03: \"" << RimuoviSingoliSpazi03(test1) << "\"" << std::endl;
    std::cout << "RimuoviSingoliSpazi04 (find_if_not): \"" << RimuoviSingoliSpazi04(test1) << "\"" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test2 << "\"" << std::endl;
    std::cout << "RimuoviSingoliSpazi01: \"" << RimuoviSingoliSpazi01(test2) << "\"" << std::endl;
    std::cout << "RimuoviSingoliSpazi02: \"" << RimuoviSingoliSpazi02(test2) << "\"" << std::endl;
    std::cout << "RimuoviSingoliSpazi03: \"" << RimuoviSingoliSpazi03(test2) << "\"" << std::endl;
    std::cout << "RimuoviSingoliSpazi04 (find_if_not): \"" << RimuoviSingoliSpazi04(test2) << "\"" << std::endl;

    std::cout << std::endl;
    
    std::cout << "Test: \"" << test3 << "\"" << std::endl;
    std::cout << "RimuoviSingoliSpazi01: \"" << RimuoviSingoliSpazi01(test3) << "\"" << std::endl;
    std::cout << "RimuoviSingoliSpazi02: \"" << RimuoviSingoliSpazi02(test3) << "\"" << std::endl;
    std::cout << "RimuoviSingoliSpazi03: \"" << RimuoviSingoliSpazi03(test3) << "\"" << std::endl;
    std::cout << "Expected: \"  abc   defghi   jkl    mnopqr  s\"" << std::endl;
        std::cout << "RimuoviSingoliSpazi04 (find_if_not): \"" << RimuoviSingoliSpazi04(test3) << "\"" << std::endl;

    return 0;
}
