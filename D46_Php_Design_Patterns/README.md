# D46 - Design Pattern

Dans ces exercices, nous appliquerons les principes SOLID vus en cours pour se démarquer du modèle "Database Driven Developpement" et s'orienter vers la logique "Code first" et la "Clean Architecture".

Nous améliorerons notre code au fur et à mesure des exercices, en implémantant des Design Pattern pour aider à résoudre des problèmes plus complexes, sans complexifier le code, sa sécurité et sa maintenance.

*Tips* : Pour exécuter le programme, vous pouvez utiliser Docker pour travailler sur la dernière version de Php sans avoir à l'installer directement dans votre environnement :
```sh
docker run --rm -v "$(pwd)/D46_Php_Design_Patterns":/app -w /app php:8.4-cli-alpine php src/Application/main.php
```

*Ressources utiles* :
 - Explication et schéma des design patterns usuels : https://refactoring.guru/design-patterns

## Créer un modèle de classes

Notre client souhaite pouvoir visualiser une liste de produits et de fournisseurs, chaque produit pouvant être acheté à des fournisseurs différents à des prix différents.
Nous devons également pouvoir générer des commandes de certains produits à un fournisseur précis.
Chaque réception de commande devra alimenter le stock.
Le donneur d'ordre des opérations doit pouvoir être identifié, de même que son bénéficiaire.
Les produits peuvent également être de plusieurs types, marchandise et service dans un premier temps.

Créez une structure de classes pour matérialiser ce modèle. Pensez à découper ce modèle en différents modules afin de visualiser les dépendances fonctionnelles dans votre code (il ne doit pas être possible de faire des cercles de dépendances : A dépend de B qui dépend de C qui dépend de A).

Vous livrerez une instanciation complète de chacune des classes du modèle dans le fichier `main.php`.

## Factory & Builder

Nous allons maintenant afficher dans le terminal la liste des Produits du fichier `data/products.json`.

Utilisez les notions vues en cours pour :
 - Charger la liste des produits en json
 - Créer de manière transparente des objets Marchandise ou Service à partir de ces données
 - Les renvoyer sous forme d'un générateur

Nous allons maintenant implémenter des filtres dans la lecture des produits dans le fichier json via un builder.

Implémentez ce pattern via la fonction "filter" telle que présentée dans l'exemple ci-dessous :
```php
// main.php

// Tips : dirname, __FILE__, is_file, file_get_contents

function main(string $datasourceFile)
{
    $datasourcePath = // ....

    $builder = new JsonFileProductBuilder(
        /* new ........([   => ....::class ]) */
    );

    $productCollection = $builder->createFrom($datasourcePath)
        ->filter(fn(array $productData) => $productData['....'] > '?')
        ->getCollection()
    ;

    foreach ($productCollection as $product) {
        var_dump($product);
    }
}

main(...$argv);
```

Vous prendrez grand soin à respecter les principes SOLID et à tester vos cas d'erreur en utilisant des exceptions.

## Adapter

Dans certains cas, deux interfaces programmatiques (API) ne sont pas compatibles, il est nécessaire d'ajouter un connecteur à notre programme pour pouvoir l'utiliser.
Il est sinon une bonne pratique en architecture logicielle de ne pas lier fortement une dépendance d'infrastructure à votre modèle, en suivant le principe d'inversion de dépendance (comme par exemple un client d'API quelconque pour des emails, paiements etc...).

Nous allons donc "adapter" le connecteur externe à notre modèle.

Nous souhaitons maintenant décorreler l'API Json en Php de notre Builder, pour qu'il puisse utiliser de manière indifférenciée du Csv et du Json en données d'entrée.

Commencez par modéliser le comportement à adapter, puis utilisez cette modélisation dans votre builder. Matérialisez ce comportement avec le Json, puis faites la même chose pour lire un fichier Csv à la place d'un json.

Voici le fichier `main.php` tel qu'attendu :

```php
// main.php

function main(string $datasourceFile)
{
    // ........

    $builder = new FileProductBuilder(
        /* new ........([   => ....::class ]) */
    );

    $productCollection = $builder
        ->createFrom((new Json.......($datasourcePath))->parse())
        // ou
        ->createFrom((new Csv.......($datasourcePath))->read())
        ->getCollection()
    ;
}

main(...$argv);
```

Vous prendrez grand soin à respecter les principes SOLID et à tester vos cas d'erreur en utilisant des exceptions.

## Visiteur & Strategy

Dans l'exemple précédent, il est dommage de devoir référencer manuellement chaque lecteur de format de fichier "à la main".
Pour améliorer, il est possible que chaque lecteur soit transformé en "stratégie" de lecture, référencée directement dans le builder; ainsi il y aurait un builder pour chaque type de fichier.

Modélisez le comportement correspondant à la stratégie de lecture, uniformisez ce comportement dans vos stratégies de lecture, puis intégrez cette stratégie comme paramètre de construction de vos builders.

```php
// main.php

$csvBuilder = new FileProductBuilder(
    /* new ........([   => ....::class ]) */
    /* new Json.......() */
);

$productCollection = $csvBuilder
    ->createFrom($datasourcePath)
    ->getCollection()
;
```

Néanmoins, devoir instancier plusieurs builders n'est pas vraiment une meilleure solution.
Pour faire mieux, il faudrait pouvoir sélectionner la stratégie la plus adaptée en fonction du type du fichier lui même. Pour ce faire, il est possible d'utiliser un pattern Visiteur qui va proposer le fichier à toutes les stratégies référencées, et dès qu'une des stratégies se déclare élligible, le visiteur l'exécute pour rendre le service correspondant.

Modifiez votre programme pour référencer toutes vos stratégies dans un seul objet qui implémente lui même le comportement de la stratégie. Transformez ensuite vos lecteurs pour implémenter une méthode de test sur un chemin de fichier, qui renvoie vrai si le format est supporté, faux sinon.

Dans l'objet conteneur, lors de l'appel à la méthode de lecture, on appellera d'abord la méthode de test de chacun des lecteurs, dès qu'un répond vrai, on l'exécute et on renvoie le résultat au builder.

Voici la construction de votre builder avec cette modification :
```php
// main.php

// Tips : fileinfo, array_filter, spread operator

$csvBuilder = new FileProductBuilder(/*
    new ........([   => ....::class ])
    new .......(
        new Csv.......(),
        new Json.......()
    )
*/);
```

Vous prendrez grand soin à respecter les principes SOLID et à tester vos cas d'erreur en utilisant des exceptions.

## Prototype

Le pattern Prototype permet de créer des objets à partir d'une définition dynamique (les attributs peuvent être variables sans avoir à créer de nouvelles classes).

Dans notre exemple, nous avons deux grands types de produits : les marchandises et les services, qui possèdent chacun des attributs différents. Nous souhaitons malgré tout avoir une classe de produits commune pour tous les achats. Afin de ne pas avoir en permanence des attributs null à tester, il faut utiliser un Prototype.
