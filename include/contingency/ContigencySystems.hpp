#pragma once
#include <iostream>
#include "EnergyCoreObserver.hpp"

class ShieldSystem : public EnergyCoreObserver {
public:
    void update() override {
        std::cout << "[Escudos] Redirecionando energia para defesa do setor central!" << std::endl;
    }
};

class LightSystem : public EnergyCoreObserver {
public:
    void update() override {
        std::cout << "[Luzes] Apagando luzes das salas não essenciais. Iluminação de emergência ativada." << std::endl;
    }
};

class PanelSystem : public EnergyCoreObserver {
public:
    void update() override {
        std::cout << "[Painéis] Exibindo alerta vermelho em todos os monitores de navegação!" << std::endl;
    }
};