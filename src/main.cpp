#include <iostream>
#include <memory>
#include <string>
#include "../include/contingency/EnergyCore.hpp"
#include "../include/contingency/ContigencySystems.hpp"
#include "../include/crew/CrewMember.hpp"
#include "../include/crew/CrewMemberDuties.hpp"
#include "../include/weaponry/Ship.hpp"
#include "../include/weaponry/BaseWeapons.hpp"
#include "../include/weaponry/Modifiers.hpp"


int main() {
    std::string input;

    // Energy Core contingency system
    EnergyCore energyCore;
    auto shieldSystem = std::make_shared<ShieldSystem>();
    auto lightSystem = std::make_shared<LightSystem>();
    auto panelSystem = std::make_shared<PanelSystem>();
    energyCore.attachObserver(shieldSystem);
    energyCore.attachObserver(lightSystem);
    energyCore.attachObserver(panelSystem);

    // Crew duty system
    auto crewMember = std::make_unique<CrewMember>(
        "Kyon",
        std::make_unique<IdleDuty>()
    );

    // Ship weaponry system
    Ship ship;

    std::cout << "Digite \"ajuda\" para ver os comandos disponíveis" << std::endl;

    while (true) {
        std::cout << "\n> ";
        
        if (!std::getline(std::cin, input)) {
            break;
        }

        if (input == "sair") {
            break;
        }
        else if (input == "ajuda") {
            std::cout << "\n-- SISTEMA DE CONTINGÊNCIA DO NÚCLEO DE ENERGIA --" << std::endl;
            std::cout << "energia - Mostra o nível de energia do núcleo." << std::endl;
            std::cout << "dano - Reduz o nível de energia do núcleo." << std::endl;

            std::cout << "\n-- COMPORTAMENTO DINÂMICO DA TRIPULAÇÃO --" << std::endl;
            std::cout << "trabalhar - Faz o tripulante trabalhar." << std::endl;
            std::cout << "trip_canhao - Muda a função do tripulante para operador de canhões." << std::endl;
            std::cout << "trip_motor - Muda a função do tripulante para mecânico dos motores." << std::endl;

            std::cout << "\n-- ARMAMENTO MODULAR E MODIFICADORES PIRATAS --" << std::endl;
            std::cout << "equip_laser - Equipa o Laser Contínuo na nave." << std::endl;
            std::cout << "equip_missil - Equipa o Enxame de Mísseis na nave." << std::endl;
            std::cout << "add_fogo - Adiciona dano de fogo à arma atual." << std::endl;
            std::cout << "add_perf - Adiciona perfuração de armadura à arma atual." << std::endl;
            std::cout << "atirar - Dispara a arma atual da nave com todos os modificadores." << std::endl;

            std::cout << "\n-- COMANDOS DE CONTROLE --" << std::endl;
            std::cout << "ajuda - Exibe o menu de ajuda." << std::endl;
            std::cout << "sair - Sai do programa." << std::endl;
        }
        else if (input == "energia") {
            std::cout << "O nível de energia do núcleo é " << std::to_string(energyCore.getEnergy()) << " pontos." << std::endl;
        }
        else if (input == "dano") {
            energyCore.drainEnergy(20);
            std::cout << "O nível energia do núcleo sofreu um dano de 20 pontos. O limiar crítico é 30 pontos!" << std::endl;
            std::cout << "O nível energia do núcleo atual é: " << std::to_string(energyCore.getEnergy()) << " pontos." << std::endl;
        }
        else if (input == "trabalhar") {
            crewMember->work();
        }
        else if (input == "trip_canhao") {
            crewMember->changeDuty(std::make_unique<CannonOpertatorDuty>());
            std::cout << "Estou a postos nos canhões!" << std::endl;
        }
        else if (input == "trip_motor") {
            crewMember->changeDuty(std::make_unique<EngineMechanicDuty>());
            std::cout << "Estou a postos nos motores!" << std::endl;
        }
        else if (input == "equip_laser") {
            ship.equipWeapon(std::make_unique<ContinuousLaser>());
            std::cout << "Laser Contínuo equipado." << std::endl;
        }
        else if (input == "equip_missil") {
            ship.equipWeapon(std::make_unique<MissileSwarm>());
            std::cout << "Enxame de Mísseis equipado." << std::endl;
        }
        else if (input == "add_fogo") {
            auto currentWeapon = ship.unequipWeapon();
            if (currentWeapon) {
                ship.equipWeapon(std::make_unique<FireDamageModifier>(std::move(currentWeapon)));
                std::cout << "Modificador de Fogo adicionado." << std::endl;
            } else {
                std::cout << "Nenhuma arma equipada para modificar!" << std::endl;
            }
        }
        else if (input == "add_perf") {
            auto currentWeapon = ship.unequipWeapon();
            if (currentWeapon) {
                ship.equipWeapon(std::make_unique<ArmorPiercingModifier>(std::move(currentWeapon)));
                std::cout << "Modificador Perfurante adicionado." << std::endl;
            } else {
                std::cout << "Nenhuma arma equipada para modificar!" << std::endl;
            }
        }
        else if (input == "atirar") {
            ship.shoot();
        }
        else {
            std::cout << "Comando desconhecido. Digite 'ajuda' para ver os comandos." << std::endl;
        }
    }

    return 0;
}