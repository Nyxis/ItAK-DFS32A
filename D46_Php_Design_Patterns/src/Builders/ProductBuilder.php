<?php

namespace Builders;

use Factories\ProductFactory;

class ProductBuilder
{
    function buildProduct(array $productBluePrintList): array
    {
        $productArray = [];
        $productFactory = new ProductFactory;

        foreach ($productBluePrintList as $productBluePrint) {
            $productArray[] = $productFactory->createProduct($productBluePrint);
        }

        return $productArray;
    }
}