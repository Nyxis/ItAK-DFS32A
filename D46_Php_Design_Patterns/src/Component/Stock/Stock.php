<?php

namespace Component\Stock;

use Component\Product\ProductPrototype;

class Stock
{
    private array $items = []; // Liste des produits en stock avec quantités

    public function addToStock(ProductPrototype $product, int $quantity): void
    {
        if (isset($this->items[$product->getId()])) {
            $this->items[$product->getId()]['quantity'] += $quantity;
        } else {
            $this->items[$product->getId()] = ['product' => $product, 'quantity' => $quantity];
        }
    }

    public function getStock(): array
    {
        return $this->items;
    }

    public function __toString(): string
    {
        return "Stock: " . count($this->items) . " products";
    }
}