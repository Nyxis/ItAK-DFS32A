<?php

// register Autoloader
define('PROJECT_DIR', realpath(__DIR__ . '/..'));
require_once PROJECT_DIR . '/Lib/Autoloader.php';

new Autoloader(PROJECT_DIR);

use Classes\Devis;
use Classes\Product;
use Classes\Stock;
use Classes\Supplier;
use Classes\User;
use Types\HierarchyPos;
use Types\ProductType;

/**
 * Main function
 */
function main(array $args)
{
    $produit = new Product("saucisse", ProductType::ARTICLE, new Stock());
    var_dump($produit);

    $user1 = new User('123Lunatic', HierarchyPos::DEALER);
    $fournisseur1 = new Supplier($user1, '0656565656', "rue du lilas");

    $user2 = new User('Enflure2renard', HierarchyPos::DEALER);
    $fournisseur2 = new Supplier($user2, '0672345162', "rue de la meumeuh");

    $saucisse1 = new Devis($fournisseur1, 13, $produit);
    $saucisse2 = new Devis($fournisseur2, 12, $produit);

    printf("Une {$produit->name} de chez {$saucisse1->dealer->user->name} coute {$saucisse1->price} euros\n");
    printf("Une {$produit->name} de chez {$saucisse2->dealer->user->name} coute {$saucisse2->price} euros\n");

}

return main($argv);