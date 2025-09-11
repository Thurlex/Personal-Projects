<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>Pokédex - 1ª Geração</title>
  <link rel="stylesheet" href="styles.css" />
</head>
<body>
  <header>
    <h1>Pokédex</h1>
    <p>Os 150 Pokémon da 1ª Geração</p>
  </header>

  <main>
    <div class="search-box">
      <input type="text" id="searchInput" placeholder="Buscar Pokémon por nome ou número..." />
    </div>

    <div id="pokemonContainer" class="pokemon-container">
      <!-- Os cards serão gerados aqui pelo JavaScript -->
    </div>
  </main>

  <script src="script.js"></script>
</body>
</html>

