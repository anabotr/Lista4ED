# Lista 4 

## Descrição do projeto
Este projeto traz uma solução em C++ para um sistema de autocomplete e busca de jogos, através da estrutura de dados Trie. Para construir a estrutura separa-se o título dos jogos letra a letra e cada uma se torna um nó na árvore. Ao percorrer todas as letras necessárias para formar o título do jogo, o ponteiro para o jogo é inserido. 


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
./app k "pre fixo"
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

Os diferentes comandos a seguir devem ter o mesmo resultado ao serem executados pela linha de comando. 

```bash
./app 1 "halo i"
```

```bash
./app 1 HALOI
```

```bash
./app 1 haloi
```

Resultado esperado: 

```bash
Halo Infinite | The legendary Halo series returns with the most expansive Master Chief campaign yet and a ground breaking free to play multiplayer experience | 160647
```

Em caso de empate por score, o display deve ser em ordem alfabética. 

```bash
./app 2 "grand theft auto iv"
```

Resultado esperado: 

```bash
Grand Theft Auto IV Complete Edition | PLEASE NOTE Microsoft no longer supports creating Games for Windows LIVE accounts within Grand Theft Auto IV You can create an account through account xbox com and then log into your account in game This standalone retail title spans three distinct stories interwoven to create one of the most unique and engaging single player | 112673
Grand Theft Auto IV The Complete Edition | Niko Bellic Johnny Klebitz and Luis Lopez all have one thing in common they live in the worst city in America Liberty City worships money and status and is heaven for those who have them and a living nightmare for those who don t | 112673
```







