<?php

namespace Component;

class Stock
{
    /** @var array<string, int> */
    private array $stock = [];

    public function addStock(Product $product, int $quantity): void
    {
        $ean = $product->getEan();
        $this->stock[$ean] = ($this->stock[$ean] ?? 0) + $quantity;
    }

    public function getStock(Product $product): int
    {
        return $this->stock[$product->getEan()] ?? 0;
    }

    public function removeStock(Product $product, int $quantity): void
    {
        $ean = $product->getEan();
        if (!isset($this->stock[$ean]) || $this->stock[$ean] < $quantity) {
            throw new \RuntimeException("Stock insuffisant pour le produit " . $product->getDesignation());
        }
        $this->stock[$ean] -= $quantity;
    }
}
