// #include <string>
// #include <iostream>
// #include <iterator>

// class Tokenizer {
// public:
//     // Forward iterator class
//     class iterator {
//     public:
//         // Iterator traits (required for STL compatibility)
//         using iterator_category = std::forward_iterator_tag;
//         using value_type = std::string;
//         using difference_type = std::ptrdiff_t;
//         using pointer = std::string*;
//         using reference = std::string&;

//         // Costruttore
//         iterator(const std::string& input, const std::string& delimiters, size_t pos)
//             : input_string_(input), token_delimiters_(delimiters), current_pos_(pos) {
//             FindNextToken();
//         }

//         // Pre-incremento (++it)
//         iterator& operator++() {
//             FindNextToken();
//             return *this;
//         }

//         // Post-incremento (it++)
//         iterator operator++(int) {
//             iterator temp = *this;
//             FindNextToken();
//             return temp;
//         }

//         // Dereferenziazione
//         const std::string& operator*() const {
//             return current_token_;
//         }

//         // Operatore freccia
//         const std::string* operator->() const {
//             return &current_token_;
//         }

//         // Confronto di uguaglianza
//         bool operator==(const iterator& other) const {
//             return current_pos_ == other.current_pos_;
//         }

//         // Confronto di diversità
//         bool operator!=(const iterator& other) const {
//             return !(*this == other);
//         }

//     private:
//         void FindNextToken() {
//             // Trova l'inizio del prossimo token
//             size_t start = input_string_.find_first_not_of(token_delimiters_, current_pos_);
            
//             if (start == std::string::npos) {
//                 // Non ci sono più token - imposta posizione alla fine
//                 current_pos_ = input_string_.length();
//                 current_token_.clear();
//                 return;
//             }
            
//             // Trova la fine del token
//             size_t end = input_string_.find_first_of(token_delimiters_, start);
            
//             if (end == std::string::npos) {
//                 // Il token va fino alla fine della stringa
//                 current_token_ = input_string_.substr(start);
//                 current_pos_ = input_string_.length();
//             } else {
//                 // Il token ha una fine definita
//                 current_token_ = input_string_.substr(start, end - start);
//                 current_pos_ = end;
//             }
//         }

//         const std::string& input_string_;
//         std::string token_delimiters_;
//         size_t current_pos_;
//         std::string current_token_;
//     };

// private:
//     std::string input_string_;
//     std::string token_delimiters_;

// public:
//     // Costruttore
//     Tokenizer(const std::string& input, const std::string& delimiters = "")
//         : input_string_(input), token_delimiters_(delimiters) {
//         if (token_delimiters_.empty()) {
//             token_delimiters_ = " \t\n\v\f\r";
//         }
//     }

//     // Iteratori per range-based for e STL algorithms
//     iterator begin() const {
//         return iterator(input_string_, token_delimiters_, 0);
//     }

//     iterator end() const {
//         return iterator(input_string_, token_delimiters_, input_string_.length());
//     }

//     // Metodi opzionali per compatibilità
//     iterator cbegin() const { return begin(); }
//     iterator cend() const { return end(); }
// };

// int main() {
//     using namespace std;

//     // Test 1: Range-based for loop
//     cout << "=== Test 1: Range-based for loop ===" << endl;
//     Tokenizer tokenizer1("  Ciao   Mamma   guarda!");
    
//     for (const auto& token : tokenizer1) {
//         cout << "'" << token << "'" << endl;
//     }
//     cout << endl;

//     // Test 2: Iteratori espliciti
//     cout << "=== Test 2: Iteratori espliciti ===" << endl;
//     Tokenizer tokenizer2("apple,banana;orange:grape", ",;:");
    
//     for (auto it = tokenizer2.begin(); it != tokenizer2.end(); ++it) {
//         cout << "Token: '" << *it << "' (length: " << it->length() << ")" << endl;
//     }
//     cout << endl;

//     // Test 3: Post-incremento
//     cout << "=== Test 3: Post-incremento ===" << endl;
//     Tokenizer tokenizer3("one two three");
    
//     auto it = tokenizer3.begin();
//     if (it != tokenizer3.end()) {
//         cout << "First token: '" << *it << "'" << endl;
//         auto old_it = it++;  // Post-incremento
//         cout << "After post-increment:" << endl;
//         cout << "  Old iterator still points to: '" << *old_it << "'" << endl;
//         if (it != tokenizer3.end()) {
//             cout << "  New iterator points to: '" << *it << "'" << endl;
//         }
//     }
//     cout << endl;

//     // Test 4: STL algorithm compatibility
//     cout << "=== Test 4: STL algorithms ===" << endl;
//     Tokenizer tokenizer4("alpha beta gamma delta");
    
//     // Conta i token
//     size_t count = std::distance(tokenizer4.begin(), tokenizer4.end());
//     cout << "Numero di token: " << count << endl;

//     // Trova il primo token che inizia con 'g'
//     auto found = std::find_if(tokenizer4.begin(), tokenizer4.end(), 
//         [](const std::string& token) {
//             return !token.empty() && token[0] == 'g';
//         });
    
//     if (found != tokenizer4.end()) {
//         cout << "Primo token che inizia con 'g': '" << *found << "'" << endl;
//     } else {
//         cout << "Nessun token trovato che inizia con 'g'" << endl;
//     }
//     cout << endl;

//     // Test 5: Copia di iteratori
//     cout << "=== Test 5: Copia di iteratori ===" << endl;
//     Tokenizer tokenizer5("first second third");
    
//     auto it1 = tokenizer5.begin();
//     auto it2 = it1;  // Copia
    
//     cout << "it1 punta a: '" << *it1 << "'" << endl;
//     cout << "it2 punta a: '" << *it2 << "'" << endl;
//     cout << "it1 == it2: " << (it1 == it2 ? "true" : "false") << endl;
    
//     ++it1;
//     cout << "Dopo ++it1:" << endl;
//     cout << "it1 punta a: '" << *it1 << "'" << endl;
//     cout << "it2 punta ancora a: '" << *it2 << "'" << endl;
//     cout << "it1 == it2: " << (it1 == it2 ? "true" : "false") << endl;
//     cout << endl;

//     // Test 6: Stringa vuota e casi limite
//     cout << "=== Test 6: Casi limite ===" << endl;
    
//     Tokenizer empty_tokenizer("");
//     cout << "Stringa vuota: ";
//     for (const auto& token : empty_tokenizer) {
//         cout << "'" << token << "' ";
//     }
//     cout << "(nessun output)" << endl;
    
//     Tokenizer only_delimiters("   \t\n  ");
//     cout << "Solo delimitatori: ";
//     for (const auto& token : only_delimiters) {
//         cout << "'" << token << "' ";
//     }
//     cout << "(nessun output)" << endl;
    
//     Tokenizer single_token("hello");
//     cout << "Singolo token: ";
//     for (const auto& token : single_token) {
//         cout << "'" << token << "' ";
//     }
//     cout << endl;

//     return 0;
// }