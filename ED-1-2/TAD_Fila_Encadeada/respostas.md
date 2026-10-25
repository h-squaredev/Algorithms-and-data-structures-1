# Análise das operações – TAD Fila Encadeada

**1. O que significa FIFO?**
*First In, First Out*: o primeiro elemento inserido é o primeiro a ser removido. Os elementos saem na mesma ordem em que entraram, como uma fila de atendimento.

**2. Diferença entre fila e pilha?**
A fila segue FIFO: insere no final e remove no início (extremidades diferentes). A pilha segue LIFO (*Last In, First Out*): insere e remove pela mesma extremidade, o topo.

**3. Complexidade da inserção (com ponteiro `fim`)?**
O(1). Basta criar o nó, ligar `fim->proximo` a ele e atualizar `fim`, sem percorrer a lista.

**4. Complexidade da remoção do início?**
O(1). Só é preciso avançar `inicio` para o próximo nó e liberar o antigo.

**5. Complexidade da consulta ao primeiro elemento?**
O(1). O valor está direto em `inicio->valor`.

**6. Complexidade da impressão de todos os elementos?**
O(n), pois cada um dos n nós é visitado uma vez.

**7. Complexidade da verificação de fila vazia?**
O(1). É apenas a comparação `inicio == NULL`.

**8. Vantagem de manter `inicio` e `fim`?**
`inicio` dá acesso imediato ao próximo elemento a sair (remoção e consulta em O(1)) e `fim` dá acesso imediato ao ponto de inserção (inserção em O(1)). Com os dois, ambas as extremidades são operadas sem percorrer a lista.

**9. E se não existisse o ponteiro `fim`?**
Para inserir seria necessário percorrer a lista desde `inicio` até o último nó, tornando a inserção O(n) e, portanto, enfileirar n elementos custaria O(n²).

**10. Por que atualizar `fim` quando o último elemento é removido?**
Quando o último nó é removido, `inicio` passa a ser NULL. Se `fim` não fosse também colocado em NULL, ele ficaria apontando para memória já liberada (ponteiro pendente) e a próxima inserção tentaria escrever em `fim->proximo`, causando comportamento indefinido. Com `fim == NULL`, a inserção reconhece a fila vazia e define `inicio` e `fim` corretamente.

**11. Por que inserção e remoção precisam respeitar extremidades específicas?**
Porque é isso que garante a ordem FIFO: inserir só no final e remover só no início preserva a ordem de chegada. Inserir ou remover no meio, ou nas extremidades trocadas, quebraria o paradigma e a fila viraria outra estrutura (pilha, lista, etc.).

**12. Vantagem da fila encadeada sobre a fila em vetor de capacidade fixa?**
Ela não tem limite fixo de capacidade (só o da memória disponível), não desperdiça espaço reservado e não exige deslocar elementos nem lógica de fila circular. Cada nó é alocado apenas quando necessário.

**13. Principal desvantagem da alocação dinâmica?**
Custo extra: cada nó consome memória adicional para o ponteiro `proximo`, cada `malloc`/`free` tem custo de tempo, os nós ficam espalhados na memória (pior localidade de cache) e há risco de vazamento de memória, ponteiros pendentes e falha de alocação, que precisam ser tratados.

**14. Finalidade de `malloc()` e `free()`?**
`malloc()` reserva em tempo de execução, no heap, a memória de cada novo nó. `free()` devolve essa memória ao sistema quando o nó é removido ou a fila é destruída, evitando vazamentos.

**15. Duas aplicações reais de FIFO?**
(1) Fila de impressão (spooler): os documentos são impressos na ordem em que foram enviados. (2) Escalonamento de processos / filas de requisições: sistemas operacionais e servidores (buffers de rede, filas de mensagens) atendem as tarefas na ordem de chegada. Também é a base do BFS em grafos.
