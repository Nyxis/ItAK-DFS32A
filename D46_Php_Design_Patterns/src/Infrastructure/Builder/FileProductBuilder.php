<?php

namespace Infrastructure\Builder;

use Component\Factory\ProductFactory;
use Infrastructure\Parser\ProductFileReaderInterface;

class FileProductBuilder implements ProductBuilderInterface
{
    private ProductFactory $factory;
    private array $filters = [];
    private array $rawData = [];

    public function __construct(ProductFactory $factory)
    {
        $this->factory = $factory;
    }

    public function createFrom(array $rawProductData): self
    {
        $this->rawData = $rawProductData;
        return $this;
    }

    public function filter(callable $filterFn): self
    {
        $this->filters[] = $filterFn;
        return $this;
    }

    public function getCollection(): iterable
    {
        $filteredData = array_filter($this->rawData, function ($product) {
            foreach ($this->filters as $filter) {
                if (!$filter($product)) return false;
            }
            return true;
        });

        foreach ($filteredData as $productData) {
            if (!isset($productData['type'])) {
                continue; // ou log
            }
            yield $this->factory->createFromArray($productData);
        }
        
    }
}
