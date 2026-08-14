#pragma once
#include <iostream>
#include "EnergyCoreObserver.hpp"

/**
 * @class ShieldSystem
 * @brief Representa o sistema de escudos da nave, agindo como um observador.
 * 
 * Responde a eventos críticos de energia mudando o foco de defesa.
 */
class ShieldSystem : public EnergyCoreObserver {
public:
    /**
     * @brief Atualiza o sistema de escudos em resposta a uma notificação do núcleo de energia.
     */
    void update() override;
};

/**
 * @class LightSystem
 * @brief Representa o sistema de iluminação da nave, agindo como um observador.
 * 
 * Responde a eventos críticos de energia desligando luzes não essenciais.
 */
class LightSystem : public EnergyCoreObserver {
public:
    /**
     * @brief Atualiza o sistema de luzes em resposta a uma notificação do núcleo de energia.
     */
    void update() override;
};

/**
 * @class PanelSystem
 * @brief Representa os painéis de navegação da nave, agindo como um observador.
 * 
 * Responde a eventos críticos de energia exibindo alertas.
 */
class PanelSystem : public EnergyCoreObserver {
public:
    /**
     * @brief Atualiza o sistema de painéis em resposta a uma notificação do núcleo de energia.
     */
    void update() override;
};