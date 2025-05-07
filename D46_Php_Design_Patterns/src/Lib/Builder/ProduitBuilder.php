<?php

namespace App\Lib\Builder;

use App\Lib\Builder\ProduitPrototype;
use App\Component\Produit\Produit;

class ProduitBuilder {
    private string $dataSource;
    private array $filters = [];
    private ProduitPrototype $prototype;

    public function from(string $dataSource): self {
        $this->dataSource = $dataSource;
        return $this;
    }

    public function addFilter(callable $filter): self {
        $this->filters[] = $filter;
        return $this;
    }

    public function setPrototype(ProduitPrototype $prototype): self {
        $this->prototype = $prototype;
        return $this;
    }

    public function build(): array {
        if (!file_exists($this->dataSource)) {
            throw new \Exception("Le fichier source de données n'existe pas : " . $this->dataSource);
        }
    
        $data = json_decode(file_get_contents($this->dataSource), true);
        if (json_last_error() !== JSON_ERROR_NONE) {
            throw new \Exception("Erreur lors du décodage JSON : " . json_last_error_msg());
        }
    
        $filteredData = array_filter($data, function($item) {
            foreach ($this->filters as $filter) {
                if (!$filter($item)) {
                    return false;
                }
            }
            return true;
        });
    
        $produits = [];
        foreach ($filteredData as $item) {
            $produit = $this->prototype->createProduit($item['nom'], $item['prix']);
            $produits[] = $produit;
        }
    
        return $produits;
    }
    
}
