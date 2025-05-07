<?php

namespace Interface;

use Component\Domain\AbstractProduit;

interface ProductPersitenceInterface {
    public function getProducts(): array;
    public function getProduct(int $id): ?AbstractProduit;
}