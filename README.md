# 🎯 Projeto Ogiva Modular para Airsoft

Sistema modular para criar diferentes missões e objetivos em jogos táticos de airsoft.

---

## 📋 O Que É Este Projeto?

A **Ogiva Modular** é um equipamento eletrônico que adiciona objetivos programáveis às partidas de airsoft, permitindo criar diferentes dinâmicas táticas e missões.

O sistema é composto por **3 módulos independentes** que podem ser usados sozinhos ou combinados. Cada módulo possui duas partes:

- **Funcionalidade específica**: A mecânica de jogo única de cada módulo
- **Sistema de Dominação integrado**: Presente em todos os módulos, permite captura de pontos e comunicação entre múltiplos módulos

O sistema de Dominação pode ser utilizado isoladamente (modo captura de ponto tradicional) ou em conjunto com outros módulos, permitindo que eles conversem entre si durante o jogo.

### 💡 Como Funciona?

Antes de cada partida, você conecta uma **IHM (Interface Humana-Máquina) de Configuração** para escolher o modo de jogo e ajustar parâmetros como tempo, dificuldade, etc. Depois é só posicionar no campo e começar a jogar!

> **Nota:** Existem diferentes IHMs para interagir com os módulos, sendo a IHM de Configuração a única obrigatória.

## 🧩 Os Módulos

Cada módulo cria uma missão diferente no jogo e pode ser usado individualmente ou combinado com outros:

### 1️⃣ Módulo Bomba

Simula uma bomba com temporizador que precisa ser desarmada ou protegida até detonar. Ideal para cenários de contraterrorismo e missões de desarme.

- **Uso individual**: Partida focada apenas no desarme/proteção da bomba
- **Na Ogiva Completa**: Parte da sequência de tarefas para armar/desarmar a ogiva

### 2️⃣ Módulo Sequenciador

Cria uma sequência de tarefas que devem ser completadas em ordem específica. Perfeito para missões que exigem coordenação e planejamento tático.

- **Uso individual**: Complete todos os checkpoints na ordem correta
- **Na Ogiva Completa**: Parte da sequência de tarefas para armar/desarmar a ogiva

### 3️⃣ Módulo 3

_(Ainda em definição - será adicionado conforme desenvolvimento)_

### 🔗 Sistema de Dominação (Integrado em Todos)

Presente em **todos os módulos**, o sistema de Dominação adiciona a mecânica de captura e controle de pontos:

- **Modo isolado**: Funciona como um ponto de captura tradicional (tipo "King of the Hill")
- **Modo múltiplo**: Vários módulos em modo Dominação se comunicam, criando rede de pontos estratégicos
- **Modo integrado**: Trabalha junto com a mecânica específica do módulo (ex: dominar antes de desarmar)

### 🎯 Ogiva Completa (Modo Integrado)

Quando todos os módulos são **fisicamente conectados**, formam uma única ogiva que funciona como uma **missão multi-etapa integrada**:

- Os 3 módulos são conectados em uma estrutura física única
- Os jogadores devem completar tarefas em cada módulo para armar ou desarmar a ogiva
- O sistema de Dominação é **ignorado** neste modo - apenas as funcionalidades específicas dos módulos são utilizadas
- A conclusão de uma etapa pode desbloquear ou afetar as próximas
- Ideal para cenários de alta complexidade com objetivos interdependentes

**Exemplo de cenário**: Conecte fisicamente os 3 módulos. Para desarmar a ogiva, primeiro complete a sequência do Sequenciador, depois desarme a Bomba, e finalmente conclua a tarefa do Módulo 3 antes que o tempo acabe.

## 📖 Documentação e Status

Cada módulo tem seu próprio manual técnico com esquemas eletrônicos, instruções de montagem e regras de jogo:

| Documentação                                             | Status          |
| -------------------------------------------------------- | --------------- |
| [📄 Componentes Comuns dos Módulos](Modulos/README.md)   | 🟡 Em progresso |
| [📄 Módulo Bomba](docs/modulo-bomba.md)                  | 🔴 Planejamento |
| [📄 Módulo Sequenciador](docs/modulo-sequenciador.md)    | 🔴 Planejamento |
| [📄 Módulo 3](docs/modulo-3.md)                          | 🔴 Planejamento |
| [📄 Sistema de Dominação](docs/modulo-dominacao.md)      | 🔴 Planejamento |
| [📄 Integração Ogiva Completa](docs/integracao-ogiva.md) | 🔴 Planejamento |
| [📄 IHM de Configuração](IHMs/Config/README.md)          | 🟡 Em progresso |

## 📜 Licença

Este projeto está licenciado sob a **Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0)**.

Isso significa que você pode:

- ✅ Compartilhar e redistribuir o projeto
- ✅ Modificar e criar versões derivadas
- ❌ **NÃO** usar comercialmente sem permissão
- ⚠️ Deve dar os devidos créditos ao autor original
- ⚠️ Modificações devem usar a mesma licença

Para mais detalhes, consulte o arquivo [LICENSE.md](LICENSE.md).
