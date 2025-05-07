<?php

// register Autoloader
define('PROJECT_DIR', realpath(__DIR__.'/..'));
require_once PROJECT_DIR.'/Lib/Autoloader.php';

new Autoloader(PROJECT_DIR);

use Factories\ProductBuilder;
use Factories\ProductFactory;
use Classes\Devis;
use Classes\Order;
use Classes\Product;
use Classes\Stock;
use Classes\Supplier;
use Classes\User;
use Classes\Service;
use Classes\Marchandise;
use Types\OrderStatus;
use Types\ProductType;
use Types\Role;


/**
 * Main function
 */


function main(array $args) {

    /** Exercice 1 **/
    /*
    $croquette = new Product('Croquettes', 'pet', '12348559', new Stock());
    $litiere = new Product('Litiere', 'pet', '37846283', new Stock());

    $employee = new User('Thomas', Role::EMPLOYEE);

    $croquePet = new User("Croque-Pet'", Role::SUPPLIER);

    $supplier = new Supplier($croquePet,"0453646464", "chemin des herissons", "contact@croquepet.com");

    $devis = new Devis($supplier, 312.60, [$croquette, $litiere]);

    $order = new Order($employee, $croquePet, [$croquette]);
    $order->addToOrder([$litiere]);
    */

    /*** Exercice 2 et 3 ***/

    $factory = new ProductFactory([
        'marchandise' => Marchandise::class,
        'service' => Service::class,
    ]);

    $datasourcePath = './data/products.json';

    $builder = new ProductBuilder($factory);

    $productCollection = $builder->createFrom($datasourcePath)
        ->filter(fn(array $productData) => strlen($productData['ean']) < 9)
        ->getCollection()
    ;

    foreach ($productCollection as $product) {
        var_dump($product);
    }

}

return main($argv);

