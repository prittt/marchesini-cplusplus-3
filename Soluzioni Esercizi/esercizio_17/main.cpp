// #include <string>
// #include <vector>
// #include <iostream>

// class Tokenizer {
// public: 
//     Tokenizer(const std::string& input, const std::string& delimiters = "")
//         : input_string_(input), token_delimiters_(delimiters) {
//             if (token_delimiters_ == "") {
//                 token_delimiters_ = " \t\n\v\f\r";
//             }
//         }

//     class iterator : public std::iterator<std::input_iterator_tag, Tokenizer>{
//     public:
//         iterator(const std::string& input, const std::string& delimiters, size_t pos) 
//             : input_string_(input), token_delimiters_(delimiters), current_pos_(pos) {
//              FindNextToken();   
//         }

//         iterator& operator++() {
//             FindNextToken();
//             return *this;
//         }

//         std::string operator*() {
//             return current_token_;
//         }

//         bool operator!=(const iterator& other) {
//             return current_pos_ != other.current_pos_;
//         }

//     private:
//         void FindNextToken() {
//             size_t start = input_string_.find_first_not_of(token_delimiters_, current_pos_);

//             if (start == std::string::npos) {
//                 current_pos_ = input_string_.length();
//                 return;
//             }

//             size_t end = input_string_.find_first_of(token_delimiters_, start);
//             current_token_ = input_string_.substr(start, end - start);
//             current_pos_ = end;
//         }

//         std::string input_string_;
//         std::string token_delimiters_;
//         size_t current_pos_ = 0;
//         std::string current_token_;
//     };

//     iterator begin() const {
//         return iterator(input_string_, token_delimiters_, 0);
//     }
//     iterator end() const {
//         return iterator(input_string_, token_delimiters_, input_string_.length());
//     }

// private:
//     std::string input_string_;
//     std::string token_delimiters_;
// };

// int main(){
//     using namespace std;
//     Tokenizer tokenizer("  Ciao   Mamma!");

//     for (Tokenizer::iterator it = tokenizer.begin(); it != tokenizer.end(); ++it){
//         std::cout << *it << std::endl;
//     }

//     for (const std::string& token : tokenizer) {
//         std::cout << token << std::endl;
//     }

// }