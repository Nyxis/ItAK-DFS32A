<?php

define('PROJECT_DIR', __DIR__ . '/src');
require_once __DIR__ . '/src/Lib/Autoloader.php';

use Component\Factory\ProductFactory;
use Component\Merchandise;
use Component\Service;
use Component\Prototype\MerchandisePrototype;
use Component\Prototype\ServicePrototype;
use Infrastructure\Builder\FileProductBuilder;
use Infrastructure\Parser\JsonProductReader;
use Infrastructure\Parser\CsvProductReader;
use Infrastructure\Strategy\FileReaderSelector;

new Autoloader(__DIR__ . '/src');

// Source de données
$filePath = $_GET['file'] ?? __DIR__ . '/data/products.json';

$factory = new ProductFactory([
    'marchandise' => new MerchandisePrototype(),
    'service'     => new ServicePrototype(),
]);

$readerSelector = new FileReaderSelector(
    new JsonProductReader(),
    new CsvProductReader()
);

if (!$readerSelector->supports($filePath)) {
    $products = [];
    $error = "Format non pris en charge pour le fichier : $filePath";
} else {
    $readerSelector->setFile($filePath);
    $builder = new FileProductBuilder($factory);
    $allProducts = iterator_to_array(
        $builder
            ->createFrom($readerSelector->read())
            ->getCollection()
    );
    $error = null;
    $merchandises = array_filter($allProducts, fn($p) => $p instanceof Merchandise);
    $services     = array_filter($allProducts, fn($p) => $p instanceof Service);
}
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Visualisation des Produits</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">

<div class="container py-5">
    <h1 class="mb-4">Visualisation des Produits</h1>

    <form method="get" class="mb-4">
        <label for="file" class="form-label">Choisissez une source :</label>
        <select name="file" id="file" class="form-select" onchange="this.form.submit()">
            <option value="data/products.json" <?= str_contains($filePath, 'json') ? 'selected' : '' ?>>JSON</option>
            <option value="data/products.csv" <?= str_contains($filePath, 'csv') ? 'selected' : '' ?>>CSV</option>
        </select>
    </form>

    <?php if ($error): ?>
        <div class="alert alert-danger"><?= htmlspecialchars($error) ?></div>
    <?php else: ?>

        <h2 class="mt-5">Marchandises</h2>
        <?php if (count($merchandises) === 0): ?>
            <p class="text-muted">Aucune marchandise à afficher.</p>
        <?php else: ?>
            <table class="table table-bordered table-striped">
                <thead class="table-primary">
                <tr>
                    <th>EAN</th>
                    <th>Désignation</th>
                    <th>Poids</th>
                </tr>
                </thead>
                <tbody>
                <?php foreach ($merchandises as $product): ?>
                    <tr>
                        <td><?= $product->getEan() ?></td>
                        <td><?= htmlspecialchars($product->getDesignation()) ?></td>
                        <td><?= $product->getPoids() ?> g</td>
                    </tr>
                <?php endforeach; ?>
                </tbody>
            </table>
        <?php endif; ?>

        <h2 class="mt-5">Services</h2>
        <?php if (count($services) === 0): ?>
            <p class="text-muted">Aucun service à afficher.</p>
        <?php else: ?>
            <table class="table table-bordered table-striped">
                <thead class="table-success">
                <tr>
                    <th>EAN</th>
                    <th>Mission</th>
                    <th>Durée</th>
                </tr>
                </thead>
                <tbody>
                <?php foreach ($services as $product): ?>
                    <tr>
                        <td><?= $product->getEan() ?></td>
                        <td><?= htmlspecialchars($product->getMission()) ?></td>
                        <td><?= $product->getDuree() ?> min</td>
                    </tr>
                <?php endforeach; ?>
                </tbody>
            </table>
        <?php endif; ?>

    <?php endif; ?>
</div>

</body>
</html>
