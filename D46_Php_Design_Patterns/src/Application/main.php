<?php

require_once __DIR__ . '/../../vendor/autoload.php';

use App\Lib\Builder\ProduitBuilder;
use App\Lib\Builder\ProduitPrototype;
use App\Component\Produit\Produit;
use App\Component\Produit\TypeProduit;

echo "Début du script...\n"; 

$produitPrototype = new ProduitPrototype();
$produitPrototype->setPrototype(new Produit('', TypeProduit::MARCHANDISE, 0.0));

$filePath = __DIR__ . '/../src/Infrastructure/Data/products.json';
echo "Chemin du fichier : " . realpath($filePath) . "\n"; 

$produits = (new ProduitBuilder())
    ->from($filePath)
    ->addFilter(fn(array $data) => $data['type'] === 'marchandise')
    ->setPrototype($produitPrototype)
    ->build();

foreach ($produits as $produit) {
    echo "Produit : " . $produit->getNom() . " - Prix : " . $produit->getPrix() . "\n"; 
    var_dump($produit);
}


// lancer la commande "php Application/main.php" dans la console

// // register Autoloader
// define('PROJECT_DIR', realpath(__DIR__.'/..'));
// require_once PROJECT_DIR.'/Lib/Autoloader.php';

// new Autoloader(PROJECT_DIR);

// /**
//  * Main function
//  */
// function main(array $args) {

// }

// return main($argv);



