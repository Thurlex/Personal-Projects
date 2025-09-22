/*
Instruções:

A partir dos conceitos fundamentais de Javascript Object e formato de dados JSON,
elaborar a estrutura de dados do projeto, baseado nos requisitos propostos pela equipe.

Código JavaScript representando a estrutura de dados do projeto, considerando os Objetos
Json necessários conforme o mapeamento da solução a ser considerado pela equipe;
*/


// Meu grupo já havia escolhido uma API em pokeapi.co
// portanto, seguirei apenas a documentação encontrada em https://pokeapi.co/docs/v2

// A partir do exemplo acima, podemos criar uma estrutura de dados em JavaScript
// que represente um Pokémon, conforme os dados retornados pela API.

/**
 * Olá!
 * A melhor forma de entender a estrutura de dados é criar um objeto JavaScript
 * que represente o Pokémon. O formato JSON é diretamente compatível com objetos JavaScript.
 *
 * Abaixo, temos um exemplo de como seria o objeto para o Pokémon "Bulbasaur",
 * baseado na estrutura que a PokeAPI retorna.
 */
const pokemonExemplo = {
  id: 1,
  name: "bulbasaur",
  height: 7,
  weight: 69,
  sprites: {
    front_default: "imagem",
    other: {
      "official-artwork": {
        front_default: "imagemOficial"
      }
    }
  },
  types: [
    {
      slot: 1,
      type: {
        name: "grass",
        url: "https://pokeapi.co/api/v2/type/12/"
      }
    },
    {
      slot: 2,
      type: {
        name: "poison",
        url: "https://pokeapi.co/api/v2/type/4/"
      }
    }
  ],
  abilities: [
    {
      ability: {
        name: "overgrow",
        url: "https://pokeapi.co/api/v2/ability/65/"
      },
      is_hidden: false,
      slot: 1
    },
    {
      ability: {
        name: "chlorophyll",
        url: "https://pokeapi.co/api/v2/ability/34/"
      },
      is_hidden: true,
      slot: 3
    }
  ]
};


// Agora, vamos adicionar a lógica para exibir esses dados no seu HTML.
// Esta função será chamada quando o botão for clicado.
function exibirDadosPokemon() {
  const outputElement = document.getElementById('output');
  
  // Usamos JSON.stringify para formatar o objeto de forma legível
  // O terceiro argumento (2) adiciona uma indentação de 2 espaços para facilitar a leitura.
  outputElement.textContent = JSON.stringify(pokemonExemplo, null, 2);
}

// Adicionamos um "escutador de eventos" ao botão.
// Quando o botão com id 'fetchPokemon' for clicado, a função 'exibirDadosPokemon' será executada.
document.getElementById('fetchPokemon').addEventListener('click', exibirDadosPokemon);




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