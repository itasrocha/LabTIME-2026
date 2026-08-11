#include <iostream>
#include <string>

int main() {
    std::string input;

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
        else {
            std::cout << "Comando desconhecido. Digite 'ajuda' para ver os comandos." << std::endl;
        }
    }

    return 0;
}