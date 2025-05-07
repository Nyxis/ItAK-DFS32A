<?php

namespace App\Lib\Builder;

use App\Component\Produit\Produit;

class ProduitPrototype {
    private Produit $prototype;

    public function setPrototype(Produit $prototype): void {
        $this->prototype = $prototype;
    }

    public function createProduit(string $nom, float $prix): Produit {
        $newProduit = clone $this->prototype;
        $newProduit->setNom($nom);
        $newProduit->setPrix($prix);
        return $newProduit;
    }
}
