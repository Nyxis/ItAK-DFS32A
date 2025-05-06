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
    $litiere = new Product('Litiere', ProductType::PET, new Stock());

    $employee = new User('Thomas', Role::EMPLOYEE);

    $croquePet = new User("Croque-Pet'", Role::SUPPLIER);

    $supplier = new Supplier($croquePet,"0453646464", "chemin des herissons", "contact@croquepet.com");

    $devis = new Devis($supplier, 312.60, [$croquette, $litiere]);

    $order = new Order($employee, $croquePet, [$croquette]);
    $order->addToOrder([$litiere]);


}

return main($argv);

