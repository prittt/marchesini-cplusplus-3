#include "formato.h"
#include <iostream>

int main() {
    std::string test1 = "10/07/2015";
    std::string test2 = "10-7-15";
    std::string test3 = "10.07.2015";
    std::string test4 = "01/12/2024";
    std::string test5 = "1/1/2024";
    std::string test6 = "32/13/2024";
    
    std::cout << "Test: \"" << test1 << "\"" << std::endl;
    std::cout << "VerificaFormatoData01: " << (VerificaFormatoData01(test1) ? "true" : "false") << std::endl;
    std::cout << "VerificaFormatoData02: " << (VerificaFormatoData02(test1) ? "true" : "false") << std::endl;
    std::cout << "VerificaFormatoData03: " << (VerificaFormatoData03(test1) ? "true" : "false") << std::endl;
    std::cout << "VerificaFormatoData04: " << (VerificaFormatoData04(test1) ? "true" : "false") << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test2 << "\"" << std::endl;
    std::cout << "VerificaFormatoData01: " << (VerificaFormatoData01(test2) ? "true" : "false") << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test3 << "\"" << std::endl;
    std::cout << "VerificaFormatoData01: " << (VerificaFormatoData01(test3) ? "true" : "false") << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test4 << "\"" << std::endl;
    std::cout << "VerificaFormatoData01: " << (VerificaFormatoData01(test4) ? "true" : "false") << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test5 << "\" (wrong length)" << std::endl;
    std::cout << "VerificaFormatoData01: " << (VerificaFormatoData01(test5) ? "true" : "false") << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test: \"" << test6 << "\" (valid format, invalid values)" << std::endl;
    std::cout << "VerificaFormatoData01: " << (VerificaFormatoData01(test6) ? "true" : "false") << std::endl;
    
    return 0;
}
