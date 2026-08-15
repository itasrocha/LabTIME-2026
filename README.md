# LabTIME 2026 - Desafio Técnico

Este repositório contém a solução para o desafio técnico do processo seletivo LabTIME 2026. Você pode encontrar as diretrizes e o regulamento deste desafio no documento [CHALLENGE.md](CHALLENGE.md).

A aplicação é uma simulação de console interativa demonstrando o uso de Design Patterns no contexto de um jogo de nave espacial.

## 1. Mapeamento e Justificativa

### Ticket 1: Sistema de Contingência do Núcleo da Nave
* **Padrão Escolhido:** Observer
* **Justificativa:** O padrão Observer é ideal para criar uma relação de um-para-muitos entre o núcleo de energia e os vários sistemas da nave (escudos, luzes, painéis). Ele permite que o núcleo notifique todos os sistemas interessados sobre variações críticas de energia sem precisar conhecer os detalhes de implementação de cada um. Isso garante que a adição de novos sistemas de contingência (como um hipotético Suporte de Vida) ocorra sem nenhuma modificação no código do núcleo, respeitando o Open-Closed Principle.

### Ticket 2: Comportamento Dinâmico da Tripulação
* **Padrão Escolhido:** Strategy 
* **Justificativa:** O padrão Strategy permite encapsular diferentes comportamentos ou algoritmos (as funções da tripulação) em classes separadas e torná-las intercambiáveis em tempo de execução. Isso resolve a necessidade de alternar a função do NPC sem destruir a sua instância e evita o uso de estruturas condicionais gigantes. O tripulante simplesmente delega a ação de trabalhar para o seu `Duty` (estratégia concreta) atual.

### Ticket 3: Armamento Modular e Modificadores Piratas
* **Padrão Escolhido:** Decorator
* **Justificativa:** O padrão Decorator permite anexar responsabilidades ou comportamentos adicionais a um objeto dinamicamente. No caso das armas, podemos empilhar modificadores (como Dano de Fogo e Dano Perfurante) envolvendo a arma base com "decoradores" sucessivos. A classe `Ship` apenas chama o método `shoot()` na interface comum da arma e todos os modificadores empilhados são executados em cascata. Isso evita a proliferação de subclasses (ex: `LaserComFogo`, `MissilComPerfuracao`) e atende perfeitamente ao requisito de modularidade.

## 2. Identificação dos Papéis no Código

### Sistema de Contingência (Observer)
* **Subject (Sujeito / Observável):** `EnergyCore`
* **Observer (Interface Observador):** `EnergyCoreObserver`
* **Concrete Observers (Observadores Concretos):** `ShieldSystem`, `LightSystem` e `PanelSystem` (presentes em `ContigencySystems.hpp`)

### Comportamento da Tripulação (Strategy)
* **Context (Contexto):** `CrewMember`
* **Strategy (Interface Estratégia):** `CrewMemberDuty`
* **Concrete Strategies (Estratégias Concretas):** `IdleDuty`, `CannonOpertatorDuty` e `EngineMechanicDuty` (presentes em `CrewMemberDuties.hpp`)

### Armamento e Modificadores (Decorator)
* **Component (Componente Base):** `Weapon` (Interface base para todas as armas e modificadores)
* **Concrete Component (Componentes Concretos):** `ContinuousLaser` e `MissileSwarm` (Armas base, em `BaseWeapons.hpp`)
* **Decorator (Decorador Base):** `WeaponDecorator` (Classe abstrata que estende `Weapon` e mantém uma referência para um `Weapon` a ser decorado)
* **Concrete Decorators (Decoradores Concretos):** `FireDamageModifier` e `ArmorPiercingModifier` (presentes em `Modifiers.hpp`)
* **Client (Cliente):** `Ship` (Armazena a abstração da arma e dispara o tiro)

## 3. Instruções de Execução

O projeto foi construído utilizando C++ e o sistema de build CMake.

### Pré-requisitos
* Compilador C++ com suporte ao padrão **C++20** (GCC, Clang, MSVC, ...)
* **CMake** (versão 3.16 ou superior)

### Compilando o Projeto

1. Clone o repositório:
    ```bash
   git clone https://github.com/itasrocha/LabTIME-2026.git
   ```
2. Navegue até o diretório raiz do projeto:
   ```bash
   cd LabTIME-2026
   ```
3. Gere os arquivos de build:
   ```bash
   cmake -B build
   ```
4. Compile o código executável:
   ```bash
   cmake --build build
   ```

### Executando a Demonstração
Após compilar com sucesso, o arquivo executável `LabTIME` estará disponível dentro do diretório `build/bin`.
Para iniciar o console interativo, execute:

```bash
build/bin/LabTIME
```

*(No Windows, o caminho pode ser algo como `build\bin\Debug\LabTIME.exe`)*

### Exemplos de Sequências de Comandos

**1. Testando o Sistema de Contingência**

Simule o núcleo de energia perdendo força gradualmente até atingir o limiar crítico (30 pontos ou menos) para ver os sistemas da nave reagindo automaticamente:
```
> energia
> dano
> dano
> dano
> dano
```
*(No quarto comando `dano`, a energia cairá para 20 e você verá os alertas dos escudos, luzes e painéis sendo disparados simultaneamente)*

**2. Testando o Comportamento Dinâmico da Tripulação**

Mude a função do membro da tripulação e faça-o trabalhar para ver a diferença na execução da tarefa:
```
> trip_canhao
> trabalhar
> trip_motor
> trabalhar
```

**3. Testando o Armamento Modular**

Equipe uma arma e dispare. Depois adicione modificadores um a um e dispare novamente para ver o efeito cascata (cumulativo):
```
> equip_laser
> atirar
> add_fogo
> atirar
> add_perf
> atirar
> equip_missil
> atirar
```