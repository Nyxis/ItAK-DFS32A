<?php

namespace Component\Supplier;

use Component\Product\ProductPrototype;

class Supplier
{
    private int $id;
    private string $name;
    private array $products = []; 

    public function __construct(int $id, string $name)
    {
        $this->id = $id;
        $this->name = $name;
    }

    public function addProduct(ProductPrototype $product, float $price): void
    {
        $this->products[] = ['product' => $product, 'price' => $price];
    }

    public function getId(): int
    {
        return $this->id;
    }

    public function getName(): string
    {
        return $this->name;
    }

    public function getProducts(): array
    {
        return $this->products;
    }

    public function __toString(): string
    {
        return "Supplier: {$this->name} (ID: {$this->id})";
    }
}