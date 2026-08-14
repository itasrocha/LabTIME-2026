#include "../../include/contingency/ContigencySystems.hpp"
#include <iostream>

void ShieldSystem::update() {
    std::cout << "[Escudos] Redirecionando energia para defesa do setor central!" << std::endl;
}

void LightSystem::update() {
    std::cout << "[Luzes] Apagando luzes das salas não essenciais. Iluminação de emergência ativada." << std::endl;
}

void PanelSystem::update() {
    std::cout << "[Painéis] Exibindo alerta vermelho em todos os monitores de navegação!" << std::endl;
}
