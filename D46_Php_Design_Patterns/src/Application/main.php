<?php

require_once __DIR__ . '/../vendor/autoload.php';

use Infrastructure\Product\FileProductBuilder;
use Infrastructure\Product\PrototypeProductFactory;
use Infrastructure\Product\JsonProductDataSource;
use Infrastructure\Product\CsvProductDataSource;

function main(string $datasourceFile)
{
    try {
        $factory = new PrototypeProductFactory();

        // Enregistrement des prototypes
        $factory->register('merchandise', new \Component\Product\ProductPrototype('merchandise'));
        $factory->register('service', new \Component\Product\ProductPrototype('service'));

        // Initialisation du builder avec les stratégies
        $builder = new FileProductBuilder(
            $factory,
            [
                new JsonProductDataSource(),
                new CsvProductDataSource(),
            ]
        );

        // Création de la collection de produits avec filtre
        $productCollection = $builder
            ->createFrom($datasourceFile)
            ->filter(fn(array $p) => $p['price'] > 100)
            ->getCollection();

        // Affichage des produits
        foreach ($productCollection as $product) {
            echo $product . PHP_EOL;
        }

    } catch (\Throwable $e) {
        echo "[ERROR] " . $e->getMessage() . PHP_EOL;
    }
}

// Appel de la fonction main avec le chemin vers le fichier JSON à la racine
main(dirname(__DIR__, 2) . '/product.json');
