# Lista 4 

## Descrição do projeto
Este projeto traz uma solução em C++ para um sistema de busca de jogos. 


## Instruções de compilação
O código deve ser compilado por meio do seguinte comando em seu terminal. 

```
g++ main.cpp Game.cpp Trie.cpp GamesDatabase.cpp -o app
```

## Instruções de execução

O programa deve ser executado no seguinte formato:

```bash
./app k prefixo
```

Caso a busca seja realizada com mais de uma palavra, o conteúdo deve ser colocado entre aspas: 

```bash
./app k "duas palavras"
```

Onde:

* `k` é a quantidade máxima de sugestões desejadas;
* `prefixo` é o prefixo usado na busca.

## Organização

* **main.cpp**: arquivo principal responsável por carregar a lista inicial de jogos, inserir os jogos na Trie e executar a busca usando os argumentos da linha de comando.
* **Game.hpp**: declaração da classe `Game`.
* **Game.cpp**: implementação da classe `Game`.
* **Trie.hpp**: declaração das classes `Trie` e `TrieNode`.
* **Trie.cpp**: implementação das classes `Trie` e `TrieNode`.
* **GamesDatabase.hpp**: declaração das variáveis contendo a lista inicial de jogos.
* **GamesDatabase.cpp**: definição da lista inicial de jogos. 

## Exemplos de uso 

Considerando o modo de execução mostrado acima, aqui estão alguns exemplos para verificar o funcionamento do código! 

Os diferentes comandos a seguir devem ter o mesmo resultado. 

```bash
./app 3 "halo i"
```

```bash
./app 3 HALOI
```

```bash
./app 3 haloi
```

Resultado esperado: 

```bash
[Halo Infinite | The legendary Halo series returns with the most expansive Master Chief campaign yet and a ground breaking free to play multiplayer experience | 160647
```


