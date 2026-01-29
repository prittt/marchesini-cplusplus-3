// #include <string>
// #include <iostream>

// class Tokenizer {
// private:
//     std::string input_string_;
//     std::string token_delimiters_;
//     size_t current_pos_;

// public:
//     // Costruttore
//     Tokenizer(const std::string& input, const std::string& delimiters = "") 
//         : input_string_(input), token_delimiters_(delimiters), current_pos_(0) {
//         // Se delimiters è vuoto, usa i delimitatori standard
//         if (token_delimiters_.empty()) {
//             token_delimiters_ = " \t\n\v\f\r";
//         }
//     }

//     // Verifica se ci sono altri token
//     bool HasNextToken() {
//         // Cerca il primo carattere non-delimitatore dalla posizione corrente
//         size_t start = input_string_.find_first_not_of(token_delimiters_, current_pos_);
//         return start != std::string::npos;
//     }

//     // Restituisce il prossimo token
//     std::string GetNextToken() {
//         // Trova l'inizio del prossimo token (primo carattere non-delimitatore)
//         size_t start = input_string_.find_first_not_of(token_delimiters_, current_pos_);
        
//         if (start == std::string::npos) {
//             // Non ci sono più token
//             current_pos_ = input_string_.length();
//             return "";
//         }
        
//         // Trova la fine del token (primo delimitatore dopo l'inizio)
//         size_t end = input_string_.find_first_of(token_delimiters_, start);
        
//         std::string token;
//         if (end == std::string::npos) {
//             // Il token va fino alla fine della stringa
//             token = input_string_.substr(start);
//             current_pos_ = input_string_.length();
//         } else {
//             // Il token ha una fine definita
//             token = input_string_.substr(start, end - start);
//             current_pos_ = end;
//         }
        
//         return token;
//     }
// };

// int main() {
//     using namespace std;
    
//     // Test 1: Stringa base con spazi
//     cout << "=== Test 1: Stringa con spazi ===" << endl;
//     Tokenizer tokenizer1("  Ciao   Mamma   guarda!");
    
//     while (tokenizer1.HasNextToken()) {
//         cout << "'" << tokenizer1.GetNextToken() << "'" << endl;
//     }
//     cout << endl;
    
//     // Test 2: Delimitatori personalizzati
//     cout << "=== Test 2: Delimitatori personalizzati ===" << endl;
//     Tokenizer tokenizer2("apple,banana;orange:grape", ",;:");
    
//     while (tokenizer2.HasNextToken()) {
//         cout << "'" << tokenizer2.GetNextToken() << "'" << endl;
//     }
//     cout << endl;
    
//     // Test 3: Stringa vuota
//     cout << "=== Test 3: Stringa vuota ===" << endl;
//     Tokenizer tokenizer3("");
    
//     if (tokenizer3.HasNextToken()) {
//         cout << "Token trovato: '" << tokenizer3.GetNextToken() << "'" << endl;
//     } else {
//         cout << "Nessun token trovato" << endl;
//     }
//     cout << endl;
    
//     // Test 4: Solo delimitatori
//     cout << "=== Test 4: Solo delimitatori ===" << endl;
//     Tokenizer tokenizer4("   \t\n  ");
    
//     if (tokenizer4.HasNextToken()) {
//         cout << "Token trovato: '" << tokenizer4.GetNextToken() << "'" << endl;
//     } else {
//         cout << "Nessun token trovato" << endl;
//     }
//     cout << endl;
    
//     // Test 5: Un singolo token
//     cout << "=== Test 5: Un singolo token ===" << endl;
//     Tokenizer tokenizer5("hello");
    
//     while (tokenizer5.HasNextToken()) {
//         cout << "'" << tokenizer5.GetNextToken() << "'" << endl;
//     }
//     cout << endl;
    
//     // Test 6: Token con caratteri speciali
//     cout << "=== Test 6: Token con caratteri speciali ===" << endl;
//     Tokenizer tokenizer6("hello@world.com test123 #hashtag", " .");
    
//     while (tokenizer6.HasNextToken()) {
//         cout << "'" << tokenizer6.GetNextToken() << "'" << endl;
//     }
//     cout << endl;
    
//     return 0;
// }