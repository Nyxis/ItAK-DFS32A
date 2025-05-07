<?php

// register Autoloader
define('PROJECT_DIR', realpath(__DIR__.'/..'));
require_once PROJECT_DIR.'/Lib/Autoloader.php';

new Autoloader(PROJECT_DIR);

use Component\Builder\FileProductBuilder;
use Component\Builder\JsonBuilder;
use Component\Domain\AbstractProduit;

/**
 * Main function
 */
function main(array $args) {
    $productsJsonPath = "./data/products.json";

    $builder = new FileProductBuilder();

    // Créer une collection d'objet produit
    $products = $builder->createFrom((new JsonBuilder)->parse($productsJsonPath))
        ->filter(fn (AbstractProduit $produit) => $produit->getNom() > 0)
        ->getCollection();

    /** @var AbstractProduit $product **/
    foreach ($products as $product) {
        echo "\n" . $product->getNom() . "\n";
        var_dump($product);
    }
}

return main($argv);