# Philosophers

## Visão Geral

Philosophers é um projeto que simula o famoso problema dos filósofos comensais, utilizando threads e mutexes para gerenciar a sincronização. O objetivo é aprender os conceitos básicos de threading em C, criar e gerenciar threads, além de trabalhar com mutexes para evitar condições de corrida.

## Funcionalidades

- **Simulação de filósofos**: Vários filósofos sentam-se em uma mesa redonda para comer, pensar e dormir, com a condição de que cada um precisa de dois garfos para comer.
- **Sincronização com mutexes**: Os garfos são compartilhados entre os filósofos e são protegidos por mutexes para garantir que dois filósofos não peguem o mesmo garfo ao mesmo tempo.
- **Controle de vida dos filósofos**: A simulação continua até que um filósofo morra de fome ou que todos tenham comido um número específico de vezes.

### Instalação e uso

1. Clone o repositório:
   ```bash
   git clone <url_do_repositorio>
   cd philosophers
2. Compile o projeto:
   ```bash
   make
3. Execute o programa com os seguintes argumentos:
   ```bash
    ./philo <número_de_filósofos> <tempo_para_morrer> <tempo_para_comer> <tempo_para_dormir> [número_de_vezes_que_cada_filósofo_deve_comer]
   -> ./philo 5 800 200 200
