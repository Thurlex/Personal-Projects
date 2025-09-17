/*
Playlist de Músicas

Você tem os dados de uma playlist. A playlist é um array, e cada item nesse array é um objeto que representa uma música.

Exercícios

Tente resolver cada um dos exercícios abaixo usando o método de array mais apropriado.

Exercício 1: Listar Títulos (.map()) Crie um novo array que contenha apenas os títulos de todas as músicas da playlist.

Exercício 2: Filtrar por Gênero (.filter()) Crie um novo array que contenha apenas as músicas do gênero "Rock".

Exercício 3: Encontrar uma Música Específica (.find()) Encontre e exiba no console o objeto completo da música cujo id é 5.

Exercício 4: Somar Durações (.reduce()) Calcule e exiba no console a duração total da playlist em segundos. (Some a propriedade duracao de todas as músicas).

Exercício 5: Músicas Longas (Enfileirando Métodos) Crie um novo array contendo apenas os títulos das músicas que têm mais de 6 minutos de duração. (Dica: você precisará usar .filter() primeiro e depois .map() no resultado).



Documentação referência: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array
*/


const playlist = [
  { id: 1, titulo: "Bohemian Rhapsody", artista: "Queen", duracao: 355, genero: "Rock" },
  { id: 2, titulo: "Stairway to Heaven", artista: "Led Zeppelin", duracao: 482, genero: "Rock" },
  { id: 3, titulo: "Billie Jean", artista: "Michael Jackson", duracao: 294, genero: "Pop" },
  { id: 4, titulo: "Like a Rolling Stone", artista: "Bob Dylan", duracao: 369, genero: "Rock" },
  { id: 5, titulo: "Smells Like Teen Spirit", artista: "Nirvana", duracao: 301, genero: "Rock Alternativo" },
  { id: 6, titulo: "Shape of You", artista: "Ed Sheeran", duracao: 233, genero: "Pop" },
  { id: 7, titulo: "Hotel California", artista: "Eagles", duracao: 390, genero: "Rock" }
];

const mappedPlaylist = playlist.map(({id, titulo, artista, duracao, genero}) => ({titulo}));
console.log(mappedPlaylist);

const filteredPlaylist = playlist.filter(musica => musica.genero.includes('Rock'));
console.log(filteredPlaylist);

const findPlaylist = playlist.find((id) => id = 5);
console.log(findPlaylist);

const totalDuracao = playlist.reduce((total, musica) => total + musica.duracao, 0);
console.log(totalDuracao);


// Enfileirando(?) metodos

const filterLongSongs = playlist.filter(musica => musica.duracao > 360);
console.log(filterLongSongs);

const mappedLongSongs = playlist.filter(musica => musica.duracao > 360).map(musica => musica.titulo);
console.log(mappedLongSongs);

const findLongSongs = playlist.find((duracao) => duracao => 361);
console.log(findLongSongs);