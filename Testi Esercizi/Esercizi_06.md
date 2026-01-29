# Esercizio 17 - Classe Tokenizer

Implementare una classe `Tokenizer` che permetta di dividere una stringa in token (parole) usando dei delimitatori specifici.

## Parte 1: Implementazione Base (senza iteratori)

Implementare la classe `Tokenizer` con le seguenti funzionalità:

### Costruttore

```cpp
Tokenizer(const std::string& input, const std::string& delimiters = "");
```

- `input`: la stringa da tokenizzare
- `delimiters`: i caratteri delimitatori (di default: spazi, tab, newline, ecc.)
- Se `delimiters` è vuoto, usare i delimitatori standard: `" \t\n\v\f\r"`

### Metodi Base

Implementare i seguenti metodi:

```cpp
bool HasNextToken();        // Verifica se ci sono altri token
std::string GetNextToken(); // Restituisce il prossimo token
```

### Esempio di Uso

```cpp
Tokenizer tokenizer("  Ciao   Mamma   guarda!");

while (tokenizer.HasNextToken()) {
    std::cout << tokenizer.GetNextToken() << std::endl;
}
```

**Output atteso:**
```
Ciao
Mamma
guarda!
```

## Parte 2: Aggiungere Supporto per Iteratori

Dopo aver completato la Parte 1, aggiungere il supporto per gli iteratori C++ per rendere la classe compatibile con i range-based for loops.

### Classe Iterator

Implementare una classe interna `iterator`:

```cpp
class iterator {
public:
    // Costruttore
    iterator(const std::string& input, const std::string& delimiters, size_t pos);
    
    // Operatori richiesti
    iterator& operator++();           // Pre-incremento
    std::string operator*();          // Dereferenziazione
    bool operator!=(const iterator& other); // Confronto
    
private:
    void FindNextToken();  // Trova il prossimo token
    
    std::string input_string_;
    std::string token_delimiters_;
    size_t current_pos_;
    std::string current_token_;
};
```

### Metodi per Range-Based For

Aggiungere alla classe `Tokenizer`:

```cpp
iterator begin() const;
iterator end() const;
```

### Esempio di Uso con Iteratori

```cpp
Tokenizer tokenizer("  Ciao   Mamma   guarda!");

// Usando iteratori espliciti
for (Tokenizer::iterator it = tokenizer.begin(); it != tokenizer.end(); ++it) {
    std::cout << *it << std::endl;
}

// Usando range-based for loop
for (const std::string& token : tokenizer) {
    std::cout << token << std::endl;
}
```

<!--
### Guida Implementativa - Parte 2

1. **Classe Iterator:**
   ```cpp
   class iterator : public std::iterator<std::input_iterator_tag, std::string> {
   ```

2. **Costruttore dell'iterator:**
   - Inizializzare le variabili membro
   - Chiamare `FindNextToken()` per posizionarsi sul primo token

3. **Metodo `FindNextToken()`:**
   - Simile alla logica di `GetNextToken()` ma memorizza il risultato in `current_token_`
   - Se non ci sono più token, impostare `current_pos_` alla fine della stringa

4. **Operatore `++`:**
   - Chiamare `FindNextToken()` per passare al token successivo
   - Restituire `*this`

5. **Operatore `*`:**
   - Restituire `current_token_`

6. **Operatore `!=`:**
   - Confrontare `current_pos_` con quella dell'altro iteratore

7. **Metodi `begin()` e `end()`:**
   - `begin()`: creare iterator con posizione 0
   - `end()`: creare iterator con posizione uguale alla lunghezza della stringa
-->

### Test Aggiuntivi

Testare la classe con:
- Stringhe vuote
- Stringhe con solo delimitatori
- Stringhe senza delimitatori
- Delimitatori personalizzati (es: virgole, punti e virgola)
- Token contenenti caratteri speciali

### Esempio Completo di Test

```cpp
int main() {
    // Test base
    Tokenizer t1("hello world");
    
    // Test con delimitatori multipli
    Tokenizer t2("apple,banana;orange", ",;");
    
    // Test range-based for
    for (const std::string& token : t1) {
        std::cout << "Token: '" << token << "'" << std::endl;
    }
    
    return 0;
}
```