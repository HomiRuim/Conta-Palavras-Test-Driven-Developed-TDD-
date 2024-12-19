#include "conta_palavras.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

std::map<std::string, int> ContaPalavras(const std::string& filename) {
    std::map<std::string, int> palavras;
    std::ifstream arquivo(filename);

    if (!arquivo.is_open()) {
        throw std::ios_base::failure("Não foi possível abrir o arquivo.");
    }

    std::string linha, palavra;
    while (std::getline(arquivo, linha)) {
        std::istringstream stream(linha);
        while (stream >> palavra) {
            palavras[palavra]++;
        }
    }

    return palavras;
}
