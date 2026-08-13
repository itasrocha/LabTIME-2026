#include <iostream>
#include <memory>
#include <string>
#include "../include/contingency/EnergyCore.hpp"
#include "../include/contingency/ContigencySystems.hpp"
#include "../include/crew/CrewMember.hpp"
#include "../include/crew/CrewMemberDuties.hpp"

int main() {
    std::string input;

    // Energy Core contingency system
    EnergyCore energyCore;
    ShieldSystem shieldSystem;
    LightSystem lightSystem;
    PanelSystem panelSystem;
    energyCore.attachObserver(&shieldSystem);
    energyCore.attachObserver(&lightSystem);
    energyCore.attachObserver(&panelSystem);

    // Crew duty system
    auto crewMember = std::make_unique<CrewMember>(
        "Kyon",
        std::make_unique<IdleDuty>()
    );

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
            std::cout << "energia - Mostra o nível de energia do núcleo." << std::endl;
            std::cout << "dano - Reduz o nível de energia do núcleo." << std::endl;
        }
        else if (input == "energia") {
            std::cout << "O nível de energia do núcleo é " << std::to_string(energyCore.getEnergy()) << "." << std::endl;
        }
        else if (input == "dano") {
            energyCore.drainEnergy(10);
            std::cout << "O nível energia do núcleo foi reduzida em 10 pontos." << std::endl;
        }
        else if (input == "trabalhar") {
            crewMember->work();
        }
        else if (input == "tripulante_canhao") {
            crewMember->changeDuty(std::make_unique<CannonOpertatorDuty>());
        }
        else if (input == "tripulante_motor") {
            crewMember->changeDuty(std::make_unique<EngineMechanicDuty>());
        }
        else {
            std::cout << "Comando desconhecido. Digite 'ajuda' para ver os comandos." << std::endl;
        }
    }

    return 0;
}