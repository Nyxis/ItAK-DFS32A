<?php

namespace Factories;
use Classes\Product;

class ProductFactory
{
    private const PRODUCT_TYPE_KEY = 'type';

    private array $mapping;

    public function __construct(array $mapping)
    {
        $this->mapping = [];

        foreach ($mapping as $type => $classname) {
            if (!class_exists($classname)) {
                throw new \InvalidArgumentException("Class $classname not found for type $type");
            }
            $this->mapping[$type] = $classname;
        }
    }

    public function loadFile(string $filepath): \Generator
    {
        if (!file_exists($filepath)) {
            throw new \RuntimeException("Fichier non trouvé : $filepath");
        }

        $jsonContent = file_get_contents($filepath);
        $dataList = json_decode($jsonContent, true);

        if (!is_array($dataList)) {
            throw new \RuntimeException("Le contenu JSON n'est pas valide.");
        }

        foreach ($dataList as $data) {
            yield $this->createFrom($data);
        }
    }

    public function createFrom(array $data): Product
    {
        if (
            empty($data[self::PRODUCT_TYPE_KEY]) ||
            !array_key_exists($data[self::PRODUCT_TYPE_KEY], $this->mapping)
        ) {
            throw new \InvalidArgumentException("Type inconnu ou manquant dans les données.");
        }

        $type = $data[self::PRODUCT_TYPE_KEY];
        $className = $this->mapping[$type];

        return new $className($data);
    }
}
