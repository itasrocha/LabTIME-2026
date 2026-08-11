#include <iostream>
#include <string>
#include "../include/core.hpp"

int main() {
    std::string input;

    EnergyCore core(100);

    while (true) {
        std::cout << "\n> ";
        
        if (!std::getline(std::cin, input)) {
            break;
        }

        if (input == "sair") {
            break;
        }
        else if (input == "ajuda") {
            std::cout << "sair - Sai do programa." << std::endl;
        }
        else if (input == "energia") {
            std::cout << "O nível de energia do núcleo é " << std::to_string(core.getEnergy()) << "." << std::endl;
        }
        else if (input == "dano") {
            core.drainEnergy(10);
            std::cout << "A energia do núcleo foi reduzida em 10 pontos." << std::endl;
        }
        else {
            std::cout << "Comando desconhecido. Digite 'ajuda' para ver os comandos." << std::endl;
        }
    }

    return 0;
}