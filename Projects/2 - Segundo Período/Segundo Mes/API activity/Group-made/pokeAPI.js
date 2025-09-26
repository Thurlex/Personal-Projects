let pokemons = [];
/**
 * Função construtora para criar um objeto Pokémon
 * @param id - Identificador único do Pokémon
 * @param name - Nome do Pokémon
 * @param type - Tipo do Pokémon (ex: Fogo, Água, Planta)
 * @param abilities - Lista de habilidades do Pokémon
 * @param status - Estatísticas do Pokémon (ex: ataque, defesa, velocidade)
 */
function pokemon(id , name , type , abilities , status) {
    this.id = id,
    this.name = name,
    this.type = type,
    this.abilities = abilities,
    this.stats= status;
}
/**
 * Função construtora para criar um objeto de usuário
 * @param id - Identificador único do usuário
 * @param name - Nome do usuário
 * @param email - E-mail do usuário
 */
function userObjec(id, name ,email) {
    this.id = id,
    this.name =name ,
    this.email =email,
    this.active=true
}
/**
 * Função construtora para criar uma categoria de Pokémons
 * @param category - Nome da categoria (ex: "Fogo", "Água", "Planta")
 * @param pokemonsInCategory - Lista de Pokémons que pertencem à categoria
 */
function SelectingCategory(category, pokemonsInCategory) {
    this.category = category;
    this.pokemonsInCategory = pokemonsInCategory;

    this.mostrarPokemons = function () {
        for (let i = 0; i < this.pokemonsInCategory.length; i++) {
            console.log(this.pokemonsInCategory[i]);
        }
    };
}
/**
 * Função construtora para criar um objeto de favoritos de Pokémon
 * @param user_id - Identificador do usuário
 */
function favoritesObject(user_id) {
    this.user_id = user_id,
    this.pokemonFavorites= [
        {
          function() { console.log(pokemon1)}
        },
        {
           function(){ console.log(pokemon2)}
        },
        
    ];
};
/**
 * Função para exibir os Pokémons disponíveis em uma região
 * @param region - Objeto que contém uma lista de Pokémons na propriedade 'pokemon'
 */
function pokemonsInMap(region){
    for(let i=0 ; i < region.pokemon.length ; i ++){
        console.log(region[i].pokemon)
    }
}let pokemon = [];
/**
 * Função construtora para criar um objeto Pokémon
 * @param id - Identificador único do Pokémon
 * @param name - Nome do Pokémon
 * @param type - Tipo do Pokémon (ex: Fogo, Água, Planta)
 * @param abilities - Lista de habilidades do Pokémon
 * @param status - Estatísticas do Pokémon (ex: ataque, defesa, velocidade)
 */
function pokemon(id , name , type , abilities , status) {
    this.id = id,
    this.name = name,
    this.type = type,
    this.abilities = abilities,
    this.stats= status;
}
/**
 * Função construtora para criar um objeto de usuário
 * @param id - Identificador único do usuário
 * @param name - Nome do usuário
 * @param email - E-mail do usuário
 */
function userObjec(id, name ,email) {
    this.id = id,
    this.name =name ,
    this.email =email,
    this.active=true
}
/**
 * Função construtora para criar uma categoria de Pokémons
 * @param category - Nome da categoria (ex: "Fogo", "Água", "Planta")
 * @param pokemonsInCategory - Lista de Pokémons que pertencem à categoria
 */
function SelectingCategory(category, pokemonsInCategory) {
    this.category = category;
    this.pokemonsInCategory = pokemonsInCategory;

    this.mostrarPokemons = function () {
        for (let i = 0; i < this.pokemonsInCategory.length; i++) {
            console.log(this.pokemonsInCategory[i]);
        }
    };
}
/**
 * Função construtora para criar um objeto de favoritos de Pokémon
 * @param user_id - Identificador do usuário
 */
function favoritesObject(user_id) {
    this.user_id = user_id,
    this.pokemonFavorites= [
        {
          function() { console.log(pokemon1)}
        },
        {
           function(){ console.log(pokemon2)}
        },
        
    ];
};
/**
 * Função para exibir os Pokémons disponíveis em uma região
 * @param region - Objeto que contém uma lista de Pokémons na propriedade 'pokemon'
 */
function pokemonsInMap(region){
    for(let i=0 ; i < region.pokemon.length ; i ++){
        console.log(region[i].pokemon)
    }
}