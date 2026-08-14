#pragma once

/**
 * @class CrewMemberDuty
 * @brief Interface para as funções dos membros da tripulação.
 * 
 * Isto atua como a interface Strategy no padrão Strategy.
 * Declara o método execute() que todas as funções (estratégias) concretas devem implementar.
 */
class CrewMemberDuty {
public:
    /**
     * @brief Destrutor virtual.
     */
    virtual ~CrewMemberDuty() = default;

    /**
     * @brief Executa a função específica.
     */
    virtual void execute() = 0;
};