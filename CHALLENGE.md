## 1. Visão Geral e Propósito do Desafio

No desenvolvimento de jogos e ferramentas no LabTIME, a capacidade de compreender requisitos de gameplay, abstrair problemas de lógica e aplicar soluções arquiteturais na prática é fundamental. O uso adequado de Padrões de Projeto (Design Patterns) garante que o código permaneça modular, legível e organizado.

Este desafio técnico tem como objetivo avaliar o seu raciocínio lógico, capacidade de aprendizado e poder de implementação em Orientação a Objetos. Trata-se de uma etapa prática: não buscamos uma arquitetura complexa ou perfeita, mas sim a sua capacidade de interpretar as necessidades apresentadas no briefing e traduzi-las em código funcional, objetivo e executável.

## 2. Estrutura e Funcionamento do Teste

O desafio consiste na análise de um cenário hipotético baseado em demandas típicas enviadas pela Equipe de Game Design. A partir desse cenário, você deverá:

1. **Analisar as Demandas do Briefing:** Ler as especificações do documento da questão e identificar os problemas lógicos de programação subjacentes.
2. **Consultar o Catálogo de Padrões e Pesquisar:** Recorrer à seção do Catálogo de Padrões de Projeto disponibilizada anexa ao teste, na qual estão listados os nomes e propósitos conceituais dos padrões permitidos. A partir dessa lista inicial, você deve realizar uma pesquisa individual mais aprofundada sobre os padrões que julgar mais pertinentes para resolver as demandas descritas. 
3. **Mapear e Selecionar a Solução:** Escolher os Padrões de Projeto do catálogo que melhor resolvem cada um dos requisitos funcionais do briefing.
4. **Implementar o Código Mínimo Executável:** Desenvolver um projeto prático e funcional na linguagem de sua preferência que demonstre os padrões trabalhando juntos na resolução das mecânicas pedidas.

## 3. Formato Obrigatório de Entrega da Resolução

A entrega do desafio deve ser feita exclusivamente através de um repositório público no GitHub contendo as seguintes partes:

### Parte A: Código Mínimo Executável (MVP de Console / Script)
* Um projeto funcional escrito em qualquer linguagem Orientada a Objetos (ex: C#, C++, Python, Java, TypeScript, GDScript, etc.).
* O código deve conter as interfaces, classes e componentes dos Padrões de Projeto escolhidos aplicados diretamente ao contexto do briefing.
* O código deve conter documentação padrão javadoc clara e coesa.
* **Execução Interativa Simples (ATENÇÃO - NÃO É UMA SIMULAÇÃO ESTÁTICA):** O projeto **não** deve ser um script linear e engessado que roda sozinho do início ao fim com mensagens print pré-programadas (hardcoded). Ele deve possuir um loop de leitura simples no terminal/console (ex: aguardar inputs do teclado) para que o avaliador possa digitar comandos e interagir com a implementação. O código deve comprovar que a lógica funciona de forma dinâmica, reagindo às escolhas de quem está operando o console. 
* Nota: Não é necessário criar interface gráfica (UI), arte visual, banco de dados ou testes unitários automatizados. Foque apenas na execução interativa limpa da lógica dos padrões.

### Parte B: Documentação no README.md
No arquivo README.md da raiz do repositório, você deve apresentar:
1. **Mapeamento e Justificativa:**
    * Qual Padrão de Projeto você escolheu para cada requisito do briefing e por que essa estrutura foi adotada.
2. **Identificação dos Papéis no Código:** 
    * Uma breve explicação de quais classes/interfaces do seu código representam os papéis do padrão (ex: quem é a interface da estratégia, quais são as estratégias concretas e quem é o contexto).
3. **Instruções de Execução:** 
    * Passo a passo simples de como clonar, compilar e/ou rodar a demonstração do projeto na máquina do avaliador.

## 4. Critérios de Avaliação

* **Capacidade de Abstração:** Aptidão em traduzir solicitações de gameplay e design em estruturas e classes lógicas. 
* **Compreensão dos Padrões:** Aplicação prática correta dos padrões de projeto escolhidos e a clara separação de papéis entre as classes.
* **Execução e Funcionalidade:** Código limpo, sem erros de compilação/execução, com uma demonstração funcional que comprove o funcionamento dos requisitos do briefing.
* **Clareza de Comunicação:** Organização do repositório, clareza das justificativas no README.md e facilidade de reprodução do projeto.

## 5. Prazos e Submissão

* **Contagem e Prazo de Execução:** Você terá **7 (sete) dias corridos** para concluir e submeter o teste.
* **Canal de Envio:** A submissão do projeto deve ser realizada exclusivamente através da seção 2 desse formulário. Nele, você deverá informar o link do seu repositório público do GitHub contendo a solução.
* **Atrasos e Validação:** A data de entrega será definida pelo email enviado ao participante junto ao link desse formulário. Envios realizados após o limite de 7 dias a partir da solicitação de início resultarão na desclassificação automática do candidato.

## O Problema: O Primeiro Dia no Laboratório

Você acabou de integrar a equipe de desenvolvimento de jogos e se sentou para a sua primeira reunião de alinhamento. O Tech Lead do projeto abre o quadro de tarefas, te dá as boas-vindas e apresenta as suas primeiras demandas. O seu papel é ler esses tickets, entender o que precisa ser feito na prática e aplicar os padrões de projeto corretos para que o código respeite as restrições estruturais impostas pela liderança.

**Mensagem do Lead:** "Bem-vindo à equipe! O pessoal do Game Design aprovou as novas mecânicas da nossa nave espacial e eu já quebrei a abstração deles em três tarefas principais para você puxar na sprint. O foco aqui não é só fazer a nave atirar ou a luz piscar, é garantir que a gente não engesse o projeto. Leia os requisitos, mas preste muita atenção nas restrições de arquitetura que eu coloquei em cada ticket. Escolha os padrões de projeto que melhor resolvem esses gargalos, beleza? Faça um loop de inputs simples para que eu possa mandar os comandos manualmente e ver o sistema reagir em tempo real. Mão na massa!"

### Ticket 1: Sistema de Contingência do Núcleo da Nave
* **Requisito:** O núcleo de energia da nave sofre variações constantes durante o combate. Precisamos que, ao atingir um nível crítico de energia (testável ao receber comandos no terminal como tomar_dano ou reduzir_energia), os escudos mudem o foco de defesa, as luzes das salas se apaguem e os painéis de navegação exibam alertas automaticamente.
* **Restrição Arquitetural:** A classe do Núcleo não pode conhecer, referenciar ou chamar diretamente as classes de Escudo, Luzes ou Painéis. A infraestrutura deve ser montada de uma forma que, se amanhã o design pedir para o "Suporte de Vida" também desligar durante a crise, nós possamos adicionar essa reação sem precisar alterar absolutamente nenhuma linha de código dentro da classe do Núcleo.

### Ticket 2: Comportamento Dinâmico da Tripulação
* **Requisito:** Os NPCs da tripulação precisam alternar entre diferentes funções durante o gameplay. O avaliador deve conseguir usar o console para trocar a função de um NPC vivo (ex: mudar de 'operador de canhões' para 'mecânico do motor') e, em seguida, mandar um comando de trabalhar. A função atual deve ditar o que ele vai imprimir no terminal ao tentar executar a tarefa.
* **Restrição Arquitetural:** É proibido destruir a entidade/objeto do tripulante e instanciar um novo NPC na cena apenas para mudar sua função. Além disso, a classe principal do Tripulante não deve conter blocos gigantes de if/else ou switch cases para decidir qual lógica rodar. As regras de cada comportamento devem ser isoladas, modulares e intercambiáveis em tempo de execução.

### Ticket 3: Armamento Modular e Modificadores Piratas
* **Requisito:** A nave precisa conseguir atirar usando diferentes tipos de armas base (Láser Contínuo, Enxame de Mísseis, etc). O console deve aceitar comandos como equipar_arma e atirar. Além disso, o usuário deve poder rodar um comando como adicionar_modificador para acoplar efeitos extras e cumulativos ao tiro (ex: colocar Dano de Fogo e, em seguida, adicionar Perfuração de Blindagem na mesma arma antes de atirar de novo).
* **Restrição Arquitetural:** A classe da Nave deve apenas emitir o comando genérico de "Atirar", sem precisar entender a lógica ou a física de disparo de cada arma fabricante. Para os modificadores, a estrutura deve permitir o empilhamento desses efeitos extras no momento do disparo de forma dinâmica. Não podemos recorrer à criação de uma classe nova para cada combinação possível de atributos.

## Anexo: Catálogo de Padrões de Projetos

### 1 - Padrões de Criação (Creational)
* **Abstract Factory** - Um método Factory é um método que fabrica objetos de um tipo particular; Um objeto Factory é um objeto que encapsula métodos Factory.
* **Builder** - Separa a construção de um objeto complexo da sua representação, de forma que o mesmo processo de construção possa criar diferentes representações.
* **Factory Method** - É uma interface para instanciação de objetos que mantém isoladas as classes concretas usadas da requisição da criação destes objetos.
* **Prototype** - O padrão Prototype fornece uma outra maneira de se construir objetos de tipos arbitrários.
* **Singleton** - Garante que para uma classe específica só possa existir uma única instância, a qual é acessível de forma global e uniforme.

### 2 - Padrões de Estrutura (Structural)
* **Adapter** - Permite que dois objetos se comuniquem mesmo que tenham interfaces incompatíveis.
* **Bridge** - Desacopla a interface da implementação; Ocultação de detalhes de implementação dos clientes.
* **Composite** - Lida com uma estrutura de elementos agrupada hierarquicamente (não como meras coleções).
* **Decorator** - Atribui responsabilidade adicionais a um objeto dinamicamente. O Decorator fornece uma alternativa flexível a subclasses para a extensão da funcionalidade.
* **Facade** - Interface unificada para um subsistema; Torna o subsistema mais fácil de usar.
* **Flyweight** - Usa compartilhamento para dar suporte a vários objetos de forma eficiente.
* **Proxy** - Fornece um objeto representante ou procurador de outro objeto para controlar o acesso ao mesmo.

### 3 - Padrões de Comportamento (Behavioral)
* **Chain of Responsability** - Evita dependência do remetente (cliente) de uma requisição ao seu destinatário, dando a oportunidade de mais de objeto tratar a requisição.
* **Command** - Associa uma ação a diferentes objetos através de uma interface conhecida.
* **Interpreter** - Usado para ajudar uma aplicação a entender uma declaração de linguagem natural e executar a funcionalidade da declaração.
* **Iterator** - Provê uma forma de percorrermos os elementos de uma coleção sem violar o seu encapsulamento.
* **Mediator** - Cria um objeto que age como um mediador controlando a interação entre um conjunto de objetos.
* **Memento** - Torna possível salvar o estado de um objeto de modo que o mesmo possa ser restaurado.
* **Observer** - Define uma relação de dependência 1:N de forma que quando um certo objeto (assunto) tem seu estado modificado os demais (observadores) são notificados; Possibilita baixo acoplamento entre os objetos observadores e o assunto.
* **State** - Permite objeto alterar seu comportamento quando estado interno muda.
* **Strategy** - Permite que uma família de algoritmos seja utilizada de modo independente e seletivo.
* **Template Method** - Define o esqueleto de um algoritmo em uma operação adiando a definição de alguns passos para a subclasse.
* **Visitor** - Define operações independentes a serem realizadas sobre elementos de uma estrutura.