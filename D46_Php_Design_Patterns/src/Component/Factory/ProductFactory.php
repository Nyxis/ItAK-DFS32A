<?php

namespace Component\Factory;

use Component\Product;
use Component\Prototype\ProductPrototypeInterface;
use InvalidArgumentException;

class ProductFactory
{
    /* @var array<string, ProductPrototypeInterface> */
    private array $prototypes;

    public function __construct(array $prototypes)
    {
        $this->prototypes = $prototypes;
    }

    public function createFromArray(array $data): Product
    {
        $type = $data['type'] ?? null;

        if (!$type || !isset($this->prototypes[$type])) {
            throw new InvalidArgumentException("Type de produit inconnu ou non supporté : $type");
        }

        return $this->prototypes[$type]->clone($data);
    }
}
