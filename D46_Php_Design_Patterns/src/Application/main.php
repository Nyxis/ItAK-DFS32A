<?php

// require_once __DIR__ . '/../vendor/autoload.php';
require_once '/app/vendor/autoload.php';

use Lib\Product\FileProductBuilder;
use Infrastructure\Product\PrototypeProductFactory;
use Infrastructure\Product\JsonProductDataSource;
use Infrastructure\Product\CsvProductDataSource;
use Component\Product\ProductPrototype;
use Component\Supplier\Supplier;
use Component\Order\Order;
use Component\Stock\Stock;
use Component\User\OrderIssuer;
use Component\User\Beneficiary;

function main(string $datasourceFile)
{
    try {
        // Instanciation des classes du modèle
        $issuer = new OrderIssuer(1, "John Dough");
        $beneficiary = new Beneficiary(1, "Rachida Datouille la Fripouille");
        $stock = new Stock();
        $supplier = new Supplier(1, "Startup Nation");

        // Instanciation d'un produit pour le fournisseur
        $product = new ProductPrototype('merchandise');
        $product->setAttributes(['id' => 1, 'name' => 'Sample Product', 'price' => 150]);
        $supplier->addProduct($product, 145.50);

        // Instanciation d'une commande
        $order = new Order(1, $supplier, $issuer, $beneficiary);
        $order->addItem($product, 10);
        $stock->addToStock($product, 10); // Simule la réception de la commande

        // Affichage des instances
        echo $issuer . PHP_EOL;
        echo $beneficiary . PHP_EOL;
        echo $supplier . PHP_EOL;
        echo $order . PHP_EOL;
        echo $stock . PHP_EOL;

        // Création des produits avec le Builder
        $factory = new PrototypeProductFactory();
        $factory->register('merchandise', new ProductPrototype('merchandise'));
        $factory->register('service', new ProductPrototype('service'));

        $builder = new FileProductBuilder(
            $factory,
            [
                new JsonProductDataSource(),
                new CsvProductDataSource(),
            ]
        );

        $productCollection = $builder
            ->createFrom($datasourceFile)
            ->filter(fn(ProductPrototype $p) => $p->price > 100)
            ->getCollection();

        foreach ($productCollection as $product) {
            echo $product . PHP_EOL;
        }

    } catch (\Throwable $e) {
        echo "[ERROR] " . $e->getMessage() . PHP_EOL;
    }
}

// Appel 
main(dirname(__DIR__, 2) . '/data/products.json');