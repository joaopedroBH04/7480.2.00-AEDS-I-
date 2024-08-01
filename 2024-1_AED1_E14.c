#include <iostream>
#include <string>
#include <cctype> // Para toupper, tolower
#include <sstream> // Para stringstream
#include <vector> // Para vetor de strings

using namespace std;

class StringUtil {
public:
    // Função para converter conteúdo para valor inteiro, se possível.
    static int getInt(const string &texto) {
        stringstream ss(texto);
        int valor;
        if (ss >> valor) {
            return valor;
        } else {
            return -1;
        }
    }

    // Função para converter conteúdo para valor real, se possível.
    static double getDouble(const string &texto) {
        stringstream ss(texto);
        double valor;
        if (ss >> valor) {
            return valor;
        } else {
            return 0.0;
        }
    }

    // Função para converter conteúdo para valor lógico, se possível.
    static bool getBoolean(const string &texto) {
        string upper = toUpperCase(texto);
        if (upper == "TRUE" || upper == "T" || upper == "1") {
            return true;
        } else if (upper == "FALSE" || upper == "F" || upper == "0") {
            return false;
        } else {
            return false;
        }
    }

    // Função para verificar se o parâmetro está contido no conteúdo.
    static bool contains(const string &texto, const string &busca) {
        return texto.find(busca) != string::npos;
    }

    // Função para converter letras para maiúsculas.
    static string toUpperCase(const string &texto) {
        string upper = texto;
        for (char &c : upper) {
            c = toupper(c);
        }
        return upper;
    }

    // Função para converter letras para minúsculas.
    static string toLowerCase(const string &texto) {
        string lower = texto;
        for (char &c : lower) {
            c = tolower(c);
        }
        return lower;
    }

    // Função para trocar todas as ocorrências de certo caractere por outro novo.
    static string replace(const string &texto, char original, char novo) {
        string result = texto;
        for (char &c : result) {
            if (c == original) {
                c = novo;
            }
        }
        return result;
    }

    // Função para codificar o conteúdo segundo a cifra de César.
    static string encrypt(const string &texto, int shift) {
        string result = texto;
        for (char &c : result) {
            if (isalpha(c)) {
                c = (c - 'A' + shift) % 26 + 'A';
            }
        }
        return result;
    }

    // Função para decodificar o conteúdo previamente cifrado pela função acima.
    static string decrypt(const string &texto, int shift) {
        return encrypt(texto, 26 - shift); // Decifração é o inverso da cifração
    }

    // Função para separar todas as sequências de caracteres separadas por espaços em branco.
    static int split(const string &texto, vector<string> &sequencia) {
        stringstream ss(texto);
        string palavra;
        int cont = 0;
        while (ss >> palavra) {
            sequencia.push_back(palavra);
            cont++;
        }
        return cont;
    }

    // Tarefa extra E1: Método para fragmentar o conteúdo usando um delimitador à escolha.
    static int splitByDelimiter(const string &texto, vector<string> &sequencia, char delimiter) {
        stringstream ss(texto);
        string palavra;
        int cont = 0;
        while (getline(ss, palavra, delimiter)) {
            sequencia.push_back(palavra);
            cont++;
        }
        return cont;
    }

    // Tarefa extra E2: Método para inverter a ordem dos símbolos na cadeia de caracteres.
    static string reverse(const string &texto) {
        string reversed = texto;
        int n = texto.length();
        for (int i = 0; i < n / 2; i++) {
            swap(reversed[i], reversed[n - i - 1]);
        }
        return reversed;
    }
};

int main() {
    // Exemplo de uso das funções da classe StringUtil
    string texto = "123";
    cout << "getInt(\"" << texto << "\") = " << StringUtil::getInt(texto) << endl;

    texto = "3.14";
    cout << "getDouble(\"" << texto << "\") = " << StringUtil::getDouble(texto) << endl;

    texto = "True";
    cout << "getBoolean(\"" << texto << "\") = " << StringUtil::getBoolean(texto) << endl;

    string texto1 = "Este é um exemplo";
    string texto2 = "exemplo";
    cout << "contains(\"" << texto1 << "\", \"" << texto2 << "\") = " << StringUtil::contains(texto1, texto2) << endl;

    texto = "Hello, World!";
    cout << "toUpperCase(\"" << texto << "\") = " << StringUtil::toUpperCase(texto) << endl;
    cout << "toLowerCase(\"" << texto << "\") = " << StringUtil::toLowerCase(texto) << endl;

    char original = 'o';
    char novo = '*';
    cout << "replace(\"" << texto << "\", '" << original << "', '" << novo << "') = " << StringUtil::replace(texto, original, novo) << endl;

    texto = "HELLO";
    int shift = 3;
    cout << "encrypt(\"" << texto << "\", " << shift << ") = " << StringUtil::encrypt(texto, shift) << endl;
    cout << "decrypt(\"" << StringUtil::encrypt(texto, shift) << "\", " << shift << ") = " << StringUtil::decrypt(StringUtil::encrypt(texto, shift), shift) << endl;

    texto = "Splitting text by spaces";
    vector<string> sequencia;
    int quantidade = StringUtil::split(texto, sequencia);
    cout << "split(\"" << texto << "\") = " << quantidade << " sequências:" << endl;
    for (const auto &palavra : sequencia) {
        cout << palavra << endl;
    }

    // Teste das tarefas extras
    texto = "Splitting,text,by,comma";
    sequencia.clear();
    quantidade = StringUtil::splitByDelimiter(texto, sequencia, ',');
    cout << "splitByDelimiter(\"" << texto << "\", ',') = " << quantidade << " sequências:" << endl;
    for (const auto &palavra : sequencia) {
        cout << palavra << endl;
    }

    string texto3 = "abcdef";
    cout << "reverse(\"" << texto3 << "\") = " << StringUtil::reverse(texto3) << endl;

    return 0;
}
