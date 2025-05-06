<?php

// register Autoloader
define('PROJECT_DIR', realpath(__DIR__.'/..'));
require_once PROJECT_DIR.'/Lib/Autoloader.php';

new Autoloader(PROJECT_DIR);

use Classes\Devis;
use Classes\Order;
use Classes\Product;
use Classes\Stock;
use Classes\Supplier;
use Classes\User;
use Types\OrderStatus;
use Types\ProductType;
use Types\Role;


/**
 * Main function
 */


function main(array $args) {

    $croquette = new Product('Croquettes', ProductType::PET, new Stock());
    var_dump($croquette);

    $litiere = new Product('Litiere', ProductType::PET, new Stock());
    var_dump($litiere);

    $employee = new User('Thomas', Role::EMPLOYEE);
    var_dump($employee);

    $croquePet = new User("Croque-Pet'", Role::SUPPLIER);

    $supplier = new Supplier($croquePet,"0453646464", "chemin des herissons", "contact@croquepet.com");
    var_dump($supplier);

    $order = new Order($employee, $croquePet, [$croquette]);
    $order->addToOrder([$litiere]);
    var_dump($order);
}

return main($argv);

