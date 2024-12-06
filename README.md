# Simulador de Vida

Bem-vindo ao **Simulador de Vida**, um jogo simples e envolvente onde você gerencia sua carreira, investimentos e escolhas ao longo de 60 anos, buscando o maior saldo financeiro possível ao final da sua jornada.

## 🎮 Sobre o jogo

No **Simulador de Vida**, você assume o papel de um personagem que inicia sua carreira como estagiário, com um saldo inicial de R$0. Durante o jogo, você poderá:

- **Escolher e evoluir sua carreira profissional**
- **Realizar investimentos financeiros**
- **Tomar decisões estratégicas para equilibrar trabalho, investimentos e gastos**

Seu objetivo é maximizar seu saldo financeiro e deixar sua marca nos recordes do jogo.

## 🚀 Funcionalidades

- **Progresso na Carreira**:
  - Estagiário: R$10.000/ano
  - Analista: R$30.000/ano
  - Gerente: R$60.000/ano
  
- **Opções de Investimento**:
  - Poupança: 0,5% ao ano
  - CDB: 5% ao ano
  - Tesouro Direto: 10% ao ano
  
- **Sistema de Registro de Recordes**:
  - Ao finalizar o jogo, seu saldo é salvo automaticamente em um arquivo de recordes para consulta futura.

## 🛠️ Como executar

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/simulador-vida.git
   cd simulador-vida
   ```

2. Compile o jogo usando um compilador C (como `gcc`):
   ```bash
   gcc -o simulador main.c
   ```

3. Execute o jogo:
   ```bash
   ./simulador
   ```

## 📚 Regras do Jogo

1. O jogo é dividido em anos, e a cada ano você pode escolher entre:
   - Trabalhar para ganhar dinheiro e acumular experiência.
   - Investir parte do saldo em diferentes opções de investimento.
   - Retirar seus investimentos.

2. A experiência no trabalho é acumulada a cada ano. Após 5 anos no mesmo cargo, você é promovido automaticamente.

3. O jogo termina após 60 anos ou se você optar por sair.

4. Seu saldo final será salvo e comparado com os recordes existentes.

## 📦 Estrutura do Projeto

- **`main.c`**: Arquivo principal contendo toda a lógica do jogo.
- **`recordes.txt`**: Arquivo gerado automaticamente que armazena os recordes de saldo final dos jogadores.

## 📝 Licença

Este projeto está sob a licença MIT. Consulte o arquivo `LICENSE` para mais informações.


