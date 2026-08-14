#pragma once
#include "CrewMemberDuty.hpp"
#include <string>
#include <memory>

/**
 * @class CrewMember
 * @brief Representa um membro da tripulação da nave.
 * 
 * O CrewMember atua como o Context no padrão Strategy. Ele mantém uma
 * referência para um CrewMemberDuty (a Estratégia) e delega o trabalho a ela.
 */
class CrewMember {
private:
    std::string name; ///< O nome do membro da tripulação.
    std::unique_ptr<CrewMemberDuty> duty; ///< A função (estratégia) atual atribuída ao tripulante.
public:
    /**
     * @brief Constrói um CrewMember com um nome e função específicos.
     * @param name O nome do membro da tripulação.
     * @param duty A função inicial atribuída ao tripulante.
     */
    CrewMember(std::string name, std::unique_ptr<CrewMemberDuty> duty);

    /**
     * @brief Altera a função do tripulante em tempo de execução.
     * @param duty A nova função a ser atribuída.
     */
    void changeDuty(std::unique_ptr<CrewMemberDuty> duty);

    /**
     * @brief Instrui o membro da tripulação a executar sua função atual.
     */
    void work();
};