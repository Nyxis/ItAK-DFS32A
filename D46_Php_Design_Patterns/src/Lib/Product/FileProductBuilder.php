<?php
// src/Lib/Product/FileProductBuilder.php
namespace Lib\Product;

use Infrastructure\Product\PrototypeProductFactory;
use Infrastructure\Product\JsonProductDataSource;
use Infrastructure\Product\CsvProductDataSource;

class FileProductBuilder
{
    private PrototypeProductFactory $factory;
    private array $strategies = [];
    private array $products = [];  

    public function __construct(PrototypeProductFactory $factory, array $strategies)
    {
        $this->factory = $factory;
        $this->strategies = $strategies;
    }

    public function createFrom(string $datasourceFile): self
    {
        foreach ($this->strategies as $strategy) {
            if (method_exists($strategy, 'parse')) {
                $data = $strategy->parse($datasourceFile);
                $this->products = array_map(
                    fn($productData) => $this->factory->create($productData),
                    $data
                );
                break;
            }
        }
        return $this;
    }

    public function filter(callable $filter): self
    {
        $this->products = array_filter($this->products, $filter);
        return $this;
    }

    public function getCollection(): array
    {
        return $this->products;
    }
}
