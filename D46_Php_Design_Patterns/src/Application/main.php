<?php

// register Autoloader
define('PROJECT_DIR', realpath(__DIR__ . '/..'));
require_once PROJECT_DIR . '/Lib/Autoloader.php';

new Autoloader(PROJECT_DIR);

use Adapters\convertFromCsv;
use Builders\ProductBuilder;
use Utils\Files;
use Utils\Parsers;

/**
 * Main function
 */
function main(): void
{

    $files = new Files;
    $jsonParser = new Parsers;
    $adapters = new convertFromCsv;
    $productBuilder = new ProductBuilder;

    $jsonString = $files->getFile("data/products.json");
    $jsonArray = $jsonParser->parseJson($jsonString);

    $productListFromJSON = $productBuilder->buildProduct($jsonArray);

    $productListFromCSV = $productBuilder->buildProduct($adapters->convert('data/products.csv'));

    print_r("Liste d'objets Produits depuis un JSON:\n");
    var_dump($productListFromJSON);

    print_r("Liste d'objets Produits depuis un CSV:\n");
    var_dump($productListFromCSV);
}

main();