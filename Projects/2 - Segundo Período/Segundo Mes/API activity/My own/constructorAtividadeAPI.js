/*
Instruções na Blackboard:

A partir dos conceitos fundamentais de Javascript Object e formato de dados JSON,
elaborar a estrutura de dados do projeto, baseado nos requisitos propostos pela equipe.

Código JavaScript representando a estrutura de dados do projeto, considerando os Objetos
Json necessários conforme o mapeamento da solução a ser considerado pela equipe;
*/

// Meu grupo já havia escolhido uma API em pokeapi.co
// portanto, seguirei apenas a documentação encontrada em https://pokeapi.co/docs/v2

// ============================= Introdução ====================================
// ESTRUTURA DE DADOS DO PROJETO POKÉDEX
// Baseado nos conceitos de JavaScript Object e formato JSON
// Mapeamento da solução considerando a PokéAPI (pokeapi.co)
// Versão usando Constructor Functions para melhor reusabilidade
// =============================================================================

// ============================= Constructor Functions =========================

// 1. CONSTRUCTOR POKEMON - Estrutura principal baseada na PokéAPI
function Pokemon(data) {
    this.id = data.id;
    this.name = data.name;
    this.height = data.height;
    this.weight = data.weight;
    this.base_experience = data.base_experience;
    this.sprites = data.sprites || {
        front_default: null,
        front_shiny: null,
        back_default: null,
        back_shiny: null
    };
    this.types = data.types || [];
    this.abilities = data.abilities || [];
    this.stats = data.stats || [];
    
    // Método para obter tipo primário
    this.getPrimaryType = function() {
        return this.types.find(t => t.slot === 1)?.type.name || 'unknown';
    };
    
    // Método para verificar se é shiny
    this.hasShinySprite = function() {
        return this.sprites.front_shiny !== null;
    };
    
    // Método para obter estatística específica
    this.getStat = function(statName) {
        const stat = this.stats.find(s => s.stat.name === statName);
        return stat ? stat.base_stat : 0;
    };
}

// 2. CONSTRUCTOR USUÁRIO - Para funcionalidade de favoritos
function User(username, email, preferences = {}) {
    this.id = 'user_' + Date.now(); // Gera ID único baseado em timestamp
    this.username = username;
    this.email = email;
    this.created_at = new Date().toISOString();
    this.preferences = {
        theme: preferences.theme || 'dark',
        language: preferences.language || 'pt-BR',
        show_shiny: preferences.show_shiny !== undefined ? preferences.show_shiny : true
    };
    
    // Método para atualizar preferências
    this.updatePreference = function(key, value) {
        if (this.preferences.hasOwnProperty(key)) {
            this.preferences[key] = value;
            return true;
        }
        return false;
    };
}

// 3. CONSTRUCTOR FAVORITOS - Relaciona usuário com Pokémons favoritos
function Favorites(userId) {
    this.user_id = userId;
    this.pokemon_favorites = [];
    this.total_favorites = 0;
    this.last_updated = new Date().toISOString();
    
    // Método para adicionar favorito
    this.addFavorite = function(pokemonId, pokemonName, isShiny = false) {
        // Verifica se já não está nos favoritos
        if (!this.pokemon_favorites.find(p => p.pokemon_id === pokemonId)) {
            this.pokemon_favorites.push({
                pokemon_id: pokemonId,
                pokemon_name: pokemonName,
                added_at: new Date().toISOString(),
                is_shiny: isShiny
            });
            this.total_favorites++;
            this.last_updated = new Date().toISOString();
            return true;
        }
        return false;
    };
    
    // Método para remover favorito
    this.removeFavorite = function(pokemonId) {
        const index = this.pokemon_favorites.findIndex(p => p.pokemon_id === pokemonId);
        if (index !== -1) {
            this.pokemon_favorites.splice(index, 1);
            this.total_favorites--;
            this.last_updated = new Date().toISOString();
            return true;
        }
        return false;
    };
    
    // Método para verificar se é favorito
    this.isFavorite = function(pokemonId) {
        return this.pokemon_favorites.some(p => p.pokemon_id === pokemonId);
    };
}

// 4. CONSTRUCTOR TIPO - Informações sobre tipos de Pokémon
function PokemonType(data) {
    this.id = data.id;
    this.name = data.name;
    this.damage_relations = data.damage_relations || {
        double_damage_to: [],
        half_damage_from: [],
        no_damage_to: []
    };
    this.pokemon = data.pokemon || [];
    
    // Método para verificar efetividade contra outro tipo
    this.isEffectiveAgainst = function(typeName) {
        return this.damage_relations.double_damage_to.some(t => t.name === typeName);
    };
    
    // Método para verificar resistência
    this.isResistantTo = function(typeName) {
        return this.damage_relations.half_damage_from.some(t => t.name === typeName);
    };
}

// 5. CONSTRUCTOR LISTA DE POKÉMONS - Para paginação e listagem
function PokemonList(limit = 20, offset = 0) {
    this.count = 0;
    this.next = null;
    this.previous = null;
    this.results = [];
    this.currentPage = Math.floor(offset / limit) + 1;
    this.itemsPerPage = limit;
    
    // Método para adicionar pokémon à lista
    this.addPokemon = function(name, url, id) {
        this.results.push({
            name: name,
            url: url,
            id: id
        });
        this.count++;
    };
    
    // Método para obter total de páginas
    this.getTotalPages = function() {
        return Math.ceil(this.count / this.itemsPerPage);
    };
    
    // Método para verificar se há próxima página
    this.hasNextPage = function() {
        return this.next !== null;
    };
    
    // Método para verificar se há página anterior
    this.hasPreviousPage = function() {
        return this.previous !== null;
    };
}

// 6. CONSTRUCTOR BUSCA/FILTRO - Para funcionalidades de pesquisa
function SearchFilter(query = '') {
    this.query = query;
    this.filters = {
        type: [],
        generation: [],
        has_evolution: null,
        min_height: null,
        max_height: null,
        min_weight: null,
        max_weight: null
    };
    this.sort_by = 'id';
    this.sort_order = 'asc';
    this.results_found = 0;
    this.search_timestamp = new Date().toISOString();
    
    // Método para adicionar filtro de tipo
    this.addTypeFilter = function(type) {
        if (!this.filters.type.includes(type)) {
            this.filters.type.push(type);
        }
    };
    
    // Método para remover filtro de tipo
    this.removeTypeFilter = function(type) {
        const index = this.filters.type.indexOf(type);
        if (index !== -1) {
            this.filters.type.splice(index, 1);
        }
    };
    
    // Método para resetar filtros
    this.resetFilters = function() {
        this.filters = {
            type: [],
            generation: [],
            has_evolution: null,
            min_height: null,
            max_height: null,
            min_weight: null,
            max_weight: null
        };
        this.search_timestamp = new Date().toISOString();
    };
    
    // Método para aplicar filtro de peso
    this.setWeightRange = function(min, max) {
        this.filters.min_weight = min;
        this.filters.max_weight = max;
    };
    
    // Método para aplicar filtro de altura
    this.setHeightRange = function(min, max) {
        this.filters.min_height = min;
        this.filters.max_height = max;
    };
}

// 7. CONSTRUCTOR CONFIGURAÇÃO DA API - Para gerenciar requisições
function ApiConfig() {
    this.base_url = 'https://pokeapi.co/api/v2/';
    this.endpoints = {
        pokemon: 'pokemon/',
        type: 'type/',
        ability: 'ability/',
        species: 'pokemon-species/'
    };
    this.cache_duration = 300000; // 5 minutos em millisegundos
    this.request_timeout = 5000;
    this.max_retries = 3;
    this.cache = new Map(); // Cache simples usando Map
    
    // Método para construir URL completa
    this.buildUrl = function(endpoint, id = '') {
        return `${this.base_url}${this.endpoints[endpoint]}${id}`;
    };
    
    // Método para verificar se cache está válido
    this.isCacheValid = function(key) {
        const cached = this.cache.get(key);
        if (!cached) return false;
        
        const now = Date.now();
        return (now - cached.timestamp) < this.cache_duration;
    };
    
    // Método para adicionar ao cache
    this.addToCache = function(key, data) {
        this.cache.set(key, {
            data: data,
            timestamp: Date.now()
        });
    };
    
    // Método para obter do cache
    this.getFromCache = function(key) {
        if (this.isCacheValid(key)) {
            return this.cache.get(key).data;
        }
        return null;
    };
}

// =============================================================================
// EXEMPLOS DE USO DOS CONSTRUCTORS
// =============================================================================

// Exemplo 1: Criando um novo Pokémon com dados da API
const pikachuData = {
    id: 25,
    name: "pikachu",
    height: 4,
    weight: 60,
    base_experience: 112,
    sprites: {
        front_default: "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/25.png",
        front_shiny: "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/shiny/25.png",
        back_default: "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/back/25.png",
        back_shiny: "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/back/shiny/25.png"
    },
    types: [
        {
            slot: 1,
            type: {
                name: "electric",
                url: "https://pokeapi.co/api/v2/type/13/"
            }
        }
    ],
    abilities: [
        {
            ability: {
                name: "static",
                url: "https://pokeapi.co/api/v2/ability/9/"
            },
            is_hidden: false,
            slot: 1
        }
    ],
    stats: [
        {
            base_stat: 35,
            effort: 0,
            stat: {
                name: "hp",
                url: "https://pokeapi.co/api/v2/stat/1/"
            }
        },
        {
            base_stat: 55,
            effort: 0,
            stat: {
                name: "attack",
                url: "https://pokeapi.co/api/v2/stat/2/"
            }
        }
    ]
};

const pikachu = new Pokemon(pikachuData);
console.log('Pikachu tipo primário:', pikachu.getPrimaryType()); // "electric"
console.log('HP do Pikachu:', pikachu.getStat('hp')); // 35

// Exemplo 2: Criando um novo usuário
const usuario = new User('treinador_pokemon', 'user@email.com', {
    theme: 'light',
    language: 'pt-BR',
    show_shiny: true
});
console.log('Usuário criado:', usuario.username);

// Exemplo 3: Gerenciando favoritos
const meusFavoritos = new Favorites(usuario.id);
meusFavoritos.addFavorite(25, 'pikachu', false);
meusFavoritos.addFavorite(6, 'charizard', true);
console.log('Total de favoritos:', meusFavoritos.total_favorites);
console.log('Pikachu é favorito?', meusFavoritos.isFavorite(25));

// Exemplo 4: Criando busca com filtros
const busca = new SearchFilter('pika');
busca.addTypeFilter('electric');
busca.setWeightRange(50, 70);
console.log('Filtros aplicados:', busca.filters);

// Exemplo 5: Configurando API
const api = new ApiConfig();
const pokemonUrl = api.buildUrl('pokemon', '25');
console.log('URL para buscar Pikachu:', pokemonUrl);

// Exemplo 6: Lista de Pokémons para paginação
const listaPokemon = new PokemonList(20, 0);
listaPokemon.addPokemon('bulbasaur', 'https://pokeapi.co/api/v2/pokemon/1/', 1);
listaPokemon.addPokemon('ivysaur', 'https://pokeapi.co/api/v2/pokemon/2/', 2);
console.log('Pokémons na lista:', listaPokemon.results.length);

// =============================================================================
// FUNÇÃO AUXILIAR PARA CRIAR POKÉMON A PARTIR DE RESPOSTA DA API
// =============================================================================

/**
 * Função helper para criar instância de Pokemon a partir da resposta da API
 * @param {Object} apiResponse - Resposta da PokéAPI
 * @returns {Pokemon} - Instância de Pokemon
 */
function createPokemonFromApi(apiResponse) {
    return new Pokemon(apiResponse);
}

/**
 * Função helper para criar tipo de Pokémon a partir da resposta da API
 * @param {Object} apiResponse - Resposta da PokéAPI para tipo
 * @returns {PokemonType} - Instância de PokemonType
 */
function createTypeFromApi(apiResponse) {
    return new PokemonType(apiResponse);
}

// Exportar constructors para uso em outros módulos (se necessário)
// module.exports = {
//     Pokemon,
//     User,
//     Favorites,
//     PokemonType,
//     PokemonList,
//     SearchFilter,
//     ApiConfig
// };