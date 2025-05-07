<?php

namespace Infrastructure\Product;

use Component\Product\ProductPrototype;

class PrototypeProductFactory
{
    private array $prototypes = [];

    public function register(string $type, ProductPrototype $prototype): void
    {
        $this->prototypes[$type] = $prototype;
    }

    public function create(array $data): ProductPrototype
    {
        $type = $data['type'] ?? null;

        if (!$type || !isset($this->prototypes[$type])) {
            throw new \InvalidArgumentException("Unknown or unregistered product type: $type");
        }

        $product = clone $this->prototypes[$type];
        $product->setAttributes($data);

        return $product;
    }
}
