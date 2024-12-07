# Simulador de Vida

Bem-vindo ao **Simulador de Vida**, um jogo de estratégia financeira onde você gerencia sua carreira, investimentos e decisões ao longo de 60 anos, buscando maximizar seu saldo financeiro e deixar sua marca nos recordes do jogo.

## 🎮 Sobre o Jogo

No **Simulador de Vida**, você inicia sua jornada com um saldo de R$ 0 e assume o papel de um profissional em ascensão. Durante o jogo, você:

- **Escolhe e evolui sua carreira profissional**
- **Realiza investimentos financeiros estratégicos**
- **Toma decisões importantes para equilibrar trabalho, investimentos e gastos**

Seu objetivo é terminar o jogo com o maior saldo financeiro possível.

## 🚀 Novidades da Versão Atual

- **Situação Econômica Aleatória**:
  - Apresentada anualmente com uma barra de status colorida para indicar o impacto econômico.
  
- **Opções de Investimento Refinadas**:
  - Poupança: 0,5% ao ano
  - CDB: 5% ao ano
  - Tesouro Direto: 10% ao ano

- **Interface com Cores**:
  - Melhor visualização com mensagens coloridas para um gameplay mais imersivo.

- **Registro e Exibição de Recordes**:
  - Salve automaticamente seu desempenho final em `recordes.txt` e confira o histórico dos melhores jogadores.

## 📚 Regras do Jogo

1. **Duração do Jogo**:
   - O jogo é dividido em 60 anos, ou termina se você optar por sair.

2. **Progresso na Carreira**:
   - Comece como estagiário (R$ 10.000/ano).
   - Trabalhe por 5 anos no mesmo cargo para ser promovido automaticamente:
     - Estagiário ➔ Analista (R$ 30.000/ano) ➔ Gerente (R$ 60.000/ano).

3. **Investimentos**:
   - Escolha entre Poupança, CDB ou Tesouro Direto para multiplicar seus ganhos.
   - Retire seu investimento a qualquer momento para reinvestir ou utilizar os fundos.

4. **Impactos Econômicos**:
   - Situação econômica aleatória exibida anualmente pode influenciar suas decisões estratégicas.

5. **Objetivo Final**:
   - Maximize seu saldo financeiro ao final dos 60 anos.

## 📦 Estrutura do Projeto

- **`main.c`**: Código principal contendo as lógicas do jogo.
- **`economia.h` e `economia.c`**: Módulo para cálculo de impacto econômico.
- **`recordes.txt`**: Arquivo gerado automaticamente com o histórico de recordes.

## 📈 Exemplo de Jogo

1. Digite seu nome.
2. Escolha ações a cada ano:
   - Trabalhar para ganhar salário.
   - Investir para obter rendimentos.
   - Retirar investimentos.
   - Avançar para o próximo ano.
3. Acompanhe sua progressão e planeje suas escolhas com base no saldo atual, status econômico e oportunidades de carreira.

## 📝 Licença

Este projeto está sob a licença MIT. Consulte o arquivo `LICENSE` para mais informações.


