# LogicExpressionsSolver
- Este repositório foi criado como parte do Trabalho Prático 1 da disciplina DCC205 – Estruturas de Dados da UFMG, realizado pelo aluno Rodolfo Lins Cardoso. 
- O objetivo do trabalho é abordar problemas de expressões lógicas e satisfabilidade.

- O PDF contendo as especificações do trabalho pode ser encontrado na raiz do projeto.


## Estrutura do Repositório
Este repositório contém oito classes, um arquivo main, e um CMakeLists.txt para facilitar o debug no CLion. A solução foi desenvolvida em C++.

### Classes:
#### Node:
Representa os nós de uma stack.

#### Stack:
Implementação de uma stack que pode assumir qualquer tipo necessário.

#### InFixExpression:
Transforma uma string p e uma string s e devolve uma stack no formato de expressão infix.

- p representa a fórmula lógica.

- s é uma string binária contendo valorações para as variáveis na fórmula.

**Exemplo:**
- p := 1 & ~ 2 | (1 & 0)
- s := 001

#### PostFixExpression:

Recebe uma stack com a expressão em formato infix fornecida pela classe anterior e constrói uma stack na notação reversa.
Pode resolver essa expressão.

#### TreeNode:
Representa o nó de uma árvore utilizada para resolver problemas de satisfabilidade.

#### Tree:
Gera uma árvore com todas as possibilidades de um problema de satisfabilidade.
Retorna se a expressão é verdadeira ou falsa, além da solução possível.

#### Utils:
Classe auxiliar para o desenvolvimento.

#### ErrorTreatment:
Classe responsável pelo tratamento de erros.
