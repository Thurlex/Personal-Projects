/*
Instruções na Blackboard:

A partir dos conceitos fundamentais de Javascript Object e formato de dados JSON,
elaborar a estrutura de dados do projeto, baseado nos requisitos propostos pela equipe.

Código JavaScript representando a estrutura de dados do projeto, considerando os Objetos
Json necessários conforme o mapeamento da solução a ser considerado pela equipe;
*/


// Meu grupo já havia escolhido uma API em pokeapi.co
// portanto, seguirei apenas a documentação encontrada em https://pokeapi.co/docs/v2

// A partir do exemplo acima, podemos criar uma estrutura de dados em JavaScript
// que represente um Pokémon, conforme os dados retornados pela API.


// ============================= Introdução ====================================
// ESTRUTURA DE DADOS DO PROJETO POKÉDEX
// Baseado nos conceitos de JavaScript Object e formato JSON
// Mapeamento da solução considerando a PokéAPI (pokeapi.co)
// =============================================================================

// ============================= Estrutura =====================================
// A estrutura está separada em 8 categorias para facilitar a leitura;
//  1. pokemonObject, a estrutura principal, onde ficam as principais informações dos pokemon;
//  2. userObject, onde são guardadas as informações do usuário (ex.: favoritos, login, linguagem, etc...);
//  3. favoritesObject, uma lista de pokemons favoritos;
//  4. PokemonTypeObject, onde são guardadas as informações de relações entre tipos de pokemon;
//  5. pokemonListObject, feito para a paginação e listagem de pokemons (por ID);
//  6. searchFilterObject, o objeto de busca para o site;
//  7. apiConfigObject, para configurar requisições à API
// =============================================================================

// 1. OBJETO POKEMON - Estrutura principal baseada na PokéAPI, pode ser encontrada em: https://pokeapi.co/api/v2/pokemon/pikachu
const pokemonObject = {
    id: 25,
    name: "pikachu",
    height: 4,
    weight: 60,
    base_experience: 112,
    // Abaixo do objeto "sprites," podem se encontrar os links de sprites aqui depositados// Array types, também no site da pokeAPI
    sprites: {
        front_default: "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/25.png",
        front_shiny: "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/shiny/25.png",
        back_default: "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/back/25.png",
        back_shiny: "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/back/shiny/25.png"
    },
    // Array com os tipo(s) do pokémon
    types: [
        {
            slot: 1,
            type: {
                name: "electric",
                url: "https://pokeapi.co/api/v2/type/13/"
            }
        }
    ],
    // Array com as habilidades do pokémon
    abilities: [
        {
            ability: {
                name: "static",
                url: "https://pokeapi.co/api/v2/ability/9/"
            },
            is_hidden: false,
            slot: 1
        },
        {
            ability: {
                name: "lightning-rod",
                url: "https://pokeapi.co/api/v2/ability/31/"
            },
            is_hidden: true,
            slot: 3
        }
    ],
    // Array com os status base do pokemon
    stats: [
        {
            base_stat: 90,
            effort: 2,
            stat: {
                name: "speed",
                url: "https://pokeapi.co/api/v2/stat/6/"
            }
        },
        {
            base_stat: 55,
            effort: 0,
            stat: {
                name: "special-defense",
                url: "https://pokeapi.co/api/v2/stat/5/"
            }
        },
        {
            base_stat: 50,
            effort: 0,
            stat: {
                name: "special-attack",
                url: "https://pokeapi.co/api/v2/stat/4/"
            }
        },
        {
            base_stat: 40,
            effort: 0,
            stat: {
                name: "defense",
                url: "https://pokeapi.co/api/v2/stat/3/"
            }
        },
        {
            base_stat: 55,
            effort: 0,
            stat: {
                name: "attack",
                url: "https://pokeapi.co/api/v2/stat/2/"
            }
        },
        {
            base_stat: 35,
            effort: 0,
            stat: {
                name: "hp",
                url: "https://pokeapi.co/api/v2/stat/1/"
            }
        }
    ]
};

// 2. OBJETO USUÁRIO - Para funcionalidade de favoritos
const userObject = {
    id: "user_123",
    username: "treinador_pokemon",
    email: "user@email.com",
    created_at: "2025-09-15T10:30:00Z",
    preferences: {
        theme: "dark",
        language: "pt-BR",
        show_shiny: true
    }
};

// 3. OBJETO FAVORITOS - Relaciona usuário com Pokémons favoritos
const favoritesObject = {
    user_id: "user_123",

    // Array que guarda os pokemons favoritos
    pokemon_favorites: [
        {
            pokemon_id: 25,
            pokemon_name: "pikachu",
            added_at: "2025-09-22T14:25:00Z",
            is_shiny: false
        },
        {
            pokemon_id: 150,
            pokemon_name: "mewtwo",
            added_at: "2025-09-21T09:15:00Z",
            is_shiny: true
        },
        {
            pokemon_id: 6,
            pokemon_name: "charizard",
            added_at: "2025-09-20T16:45:00Z",
            is_shiny: false
        }
    ],
    // O total de favoritos dos 
    total_favorites: 3,
    last_updated: "2025-09-20T16:45:00Z"
};

// 4. OBJETO TIPO - Informações sobre tipos de Pokémon, pode ser encontrado em https://pokeapi.co/api/v2/type/electric
const pokemonTypeObject = {
    id: 13,
    name: "electric",
    damage_relations: {
        double_damage_to: [
            {
                name: "flying",
                url: "https://pokeapi.co/api/v2/type/3/"
            },
            {
                name: "water",
                url: "https://pokeapi.co/api/v2/type/11/"
            }
        ],
        half_damage_from: [
            {
                name: "flying",
                url: "https://pokeapi.co/api/v2/type/3/"
            },
            {
                name: "steel",
                url: "https://pokeapi.co/api/v2/type/9/"
            },
            {
                name: "electric",
                url: "https://pokeapi.co/api/v2/type/13/"
            }
        ],
        no_damage_to: [
            {
                name: "ground",
                url: "https://pokeapi.co/api/v2/type/5/"
            }
        ]
    },
    pokemon: [
        {
            pokemon: {
                name: "pikachu",
                url: "https://pokeapi.co/api/v2/pokemon/25/"
            },
            slot: 1
        }
    ]
};

// 5. OBJETO LISTA DE POKÉMONS - Para paginação e listagem
const pokemonListObject = {
    count: 1302, // Quantidade total de pokemons
    next: "https://pokeapi.co/api/v2/pokemon/?offset=20&limit=20",
    previous: null,
    // Listagem por ID
    results: [
        {
            name: "bulbasaur",
            url: "https://pokeapi.co/api/v2/pokemon/1/",
            id: 1
        },
        {
            name: "ivysaur",
            url: "https://pokeapi.co/api/v2/pokemon/2/",
            id: 2
        },
        {
            name: "venusaur",
            url: "https://pokeapi.co/api/v2/pokemon/3/",
            id: 3
        }
    ]
};

// 6. OBJETO BUSCA/FILTRO - Para funcionalidades de pesquisa, no momento é apenas exemplo pois necessita de user input
const searchFilterObject = {
    query: "pika",
    filters: {
        type: ["electric"],
        generation: [1],
        has_evolution: true,
        min_height: null,
        max_height: null,
        min_weight: null,
        max_weight: null
    },
    sort_by: "id",
    sort_order: "asc",
    results_found: 3,
    search_timestamp: "2025-09-20T10:30:00Z"
};

// 7. OBJETO CONFIGURAÇÃO DA API - Para gerenciar requisições
const apiConfigObject = {
    base_url: "https://pokeapi.co/api/v2/",
    endpoints: {
        pokemon: "pokemon/",
        type: "type/",
        ability: "ability/",
        species: "pokemon-species/"
    },
    cache_duration: 300000, // 5 minutos em millisegundos
    request_timeout: 5000,
    max_retries: 3
};

// =============================================================================
// EXEMPLOS DE ARRAYS DE OBJETOS PARA SIMULAÇÃO DE DADOS
// =============================================================================

// Exemplo de array de tipos de Pokémon
const pokemonTypesArray = [
    { id: 1, name: "normal", color: "#A8A878" },
    { id: 2, name: "fighting", color: "#C03028" },
    { id: 3, name: "flying", color: "#A890F0" },
    { id: 4, name: "poison", color: "#A040A0" },
    { id: 5, name: "ground", color: "#E0C068" },
    { id: 13, name: "electric", color: "#F8D030" }
];



// Estrutura JSON
/* 
{
  "id": 1,
  "name": "stench",
  "is_main_series": true,
  "generation": {
    "name": "generation-iii",
    "url": "https://pokeapi.co/api/v2/generation/3/"
  },
  "names": [
    {
      "name": "Stench",
      "language": {
        "name": "en",
        "url": "https://pokeapi.co/api/v2/language/9/"
      }
    }
  ],
  "effect_entries": [
    {
      "effect": "This Pokémon's damaging moves have a 10% chance to make the target [flinch]{mechanic:flinch} with each hit if they do not already cause flinching as a secondary effect.\n\nThis ability does not stack with a held item.\n\nOverworld: The wild encounter rate is halved while this Pokémon is first in the party.",
      "short_effect": "Has a 10% chance of making target Pokémon [flinch]{mechanic:flinch} with each hit.",
      "language": {
        "name": "en",
        "url": "https://pokeapi.co/api/v2/language/9/"
      }
    }
  ],
  "effect_changes": [
    {
      "version_group": {
        "name": "black-white",
        "url": "https://pokeapi.co/api/v2/version-group/11/"
      },
      "effect_entries": [
        {
          "effect": "Has no effect in battle.",
          "language": {
            "name": "en",
            "url": "https://pokeapi.co/api/v2/language/9/"
          }
        }
      ]
    }
  ],
  "flavor_text_entries": [
    {
      "flavor_text": "è‡­ãã¦ã€€ç›¸æ‰‹ãŒ\nã²ã‚‹ã‚€ã€€ã“ã¨ãŒã‚ã‚‹ã€‚",
      "language": {
        "name": "ja-kanji",
        "url": "https://pokeapi.co/api/v2/language/11/"
      },
      "version_group": {
        "name": "x-y",
        "url": "https://pokeapi.co/api/v2/version-group/15/"
      }
    }
  ],
  "pokemon": [
    {
      "is_hidden": true,
      "slot": 3,
      "pokemon": {
        "name": "gloom",
        "url": "https://pokeapi.co/api/v2/pokemon/44/"
      }
    }
  ]
}
*/