<?php

namespace Component\Builder;

use Component\Factory\ProduitFactory;

class FileProductBuilder {
    private $produits = [];

    /**
     * Générer une collection de produit à partir d'un fichier
     * @throws \FileNotFoundException
     */
    public function createFrom(array $produits): self
    {
        $this->produits = array_map(fn (array $produit) => ProduitFactory::createFromArray($produit), $produits);
        return $this;
    }

    /**
     * Filtrer la collection de produit
     * @param callable $callback
     * @return self
     */
    public function filter(callable $callback): self
    {
        $this->produits = array_filter($this->produits, $callback);
        return $this;
    }

    /**
     * Récupérer la collection générer
     * @return \Component\Domain\AbstractProduit[]
     */
    public function getCollection(): array
    {
        return $this->produits;
    }
}