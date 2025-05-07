<?php

namespace Factories;
use Factories\ProductFactory;

class ProductBuilder
{
    private ProductFactory $productFactory;
    private array $filter = [];
    private $dataList;
    public function __construct(ProductFactory $productFactory)
    {
        $this->productFactory = $productFactory;
    }

    public function createFrom(string $filepath) {
        if (!file_exists($filepath)) {
            throw new \RuntimeException("Fichier non trouvé : $filepath");
        }

        $jsonContent = file_get_contents($filepath);
        $dataList = json_decode($jsonContent, true);

        if (!is_array($dataList)) {
            throw new \RuntimeException("Le contenu JSON n'est pas valide.");
        }

        $this->dataList = $dataList;

        return $this;
    }

    public function filter($filterCondition) {
        $this->filter[] = $filterCondition;
        return $this;
    }

    public function getCollection() {
        $filteredData = $this->dataList;

        foreach ($this->filter as $condition) {
            $filteredData = array_filter($filteredData, $condition);
        }
        return array_map(
            fn(array $data) => $this->productFactory->createFrom($data),
            $filteredData
        );
    }
}