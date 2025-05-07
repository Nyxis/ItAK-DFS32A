<?php

define('PROJECT_DIR', realpath(__DIR__ . '/..'));
require_once PROJECT_DIR . '/../Lib/Autoloader.php';

use Component\Factory\ProductFactory;
use Component\Merchandise;
use Component\Service;
use Component\Prototype\MerchandisePrototype;
use Component\Prototype\ServicePrototype;
use Infrastructure\Builder\FileProductBuilder;
use Infrastructure\Parser\JsonProductReader;
use Infrastructure\Parser\CsvProductReader;
use Infrastructure\Strategy\FileReaderSelector;

new Autoloader(PROJECT_DIR);

/**
 * Main function
 */
function main(array $argv): void
{
    $filePath = $argv[1] ?? PROJECT_DIR . '/../data/products.json';

    // 💡 Injection des prototypes dans la factory
    $factory = new ProductFactory([
        'marchandise' => new MerchandisePrototype(),
        'service'     => new ServicePrototype(),
    ]);

    // 🧠 Détection automatique du format avec le visiteur
    $readerSelector = new FileReaderSelector(
        new JsonProductReader(),
        new CsvProductReader()
    );

    if (!$readerSelector->supports($filePath)) {
        throw new InvalidArgumentException("Aucun lecteur compatible avec le fichier : $filePath");
    }

    $readerSelector->setFile($filePath);

    $builder = new FileProductBuilder($factory);

    $products = $builder
        ->createFrom($readerSelector->read())
        ->filter(fn(array $p) => $p['type'] === 'service' || ($p['type'] === 'marchandise' && $p['poids'] > 300))
        ->getCollection();

    foreach ($products as $product) {
        var_dump($product);
    }
}

main($argv);
