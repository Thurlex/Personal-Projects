/*
Exercício 1: Livro

Crie um objeto chamado livro para representar um livro.


Ele deve ter as seguintes propriedades:

título (string)

autor (string)

numeroDePaginas (number)

lido (boolean - indicando se você já leu ou não)

genero (romance, ficção, comédia, distopia...)

numero de páginas


1.1 Crie 5 livros diferentes (livro1, livro2, livro3, livro4 e livro5)

1.2 Crie um array chamado acervo, e adicione os 5 livros no acervo

1.3 Imprima todos os livros do acervo

1.4 Imprima todos os livros lidos do acervo

1.5 Faça uma função que imprima apenas os livros de um determinado genero informado.

1.6 Faça uma função que retorne um array apenas com livros que contenham mais de 100 páginas
*/

const livro1 = {
    titulo: "livro1",
    autor: "autor1",
    numeroDePaginas: 100,
    lido: true,
    genero: "Ação"
};

const livro2 = {
    titulo: "livro1",
    autor: "autor1",
    numeroDePaginas: 70,
    lido: false,
    genero: "Ação"
};

const livro3 = {
    titulo: "livro3",
    autor: "autor3",
    numeroDePaginas: 150,
    lido: true,
    genero: "Romance"
};

const livro4 = {
    titulo: "livro4",
    autor: "autor4",
    numeroDePaginas: 230,
    lido: true,
    genero: "Comédia"
};

const livro5 = {
    titulo: "livro5",
    autor: "autor5",
    numeroDePaginas: 50,
    lido: false,
    genero: "Ficção"
};

acervo = [livro1, livro2, livro3, livro4, livro5];

function imprimirLivros(acervo) {
    acervo.forEach (livro => {
        console.log(`Título: ${livro.titulo}, Autor: ${livro.autor}, Páginas: ${livro.numeroDePaginas}, Lido: ${livro.lido}, Gênero: ${livro.genero}`);
    });
}

function imprimirLivrosLidos(acervo) {
        acervo.forEach (livro => {
        if (livro.lido) {
            console.log(`Título: ${livro.titulo}, Autor: ${livro.autor}, Páginas: ${livro.numeroDePaginas}, Gênero: ${livro.genero}`);
        }
    });
}

function imprimirLivrosPorGenero(acervo, genero) {
    acervo.forEach (livro => {
        if (livro.genero === genero) {
            console.log(`Título: ${livro.titulo}, Autor: ${livro.autor}, Páginas: ${livro.numeroDePaginas}, Lido: ${livro.lido}, Gênero: ${livro.genero}`);
        }
    });
}

function livrosComMaisDe100Paginas(acervo) {
    acervo.forEach (livro => {
        if (livro.numeroDePaginas > 100) {
            console.log(`Título: ${livro.titulo}, Autor: ${livro.autor}, Páginas: ${livro.numeroDePaginas}, Lido: ${livro.lido}, Gênero: ${livro.genero}`);
        };
    });
}