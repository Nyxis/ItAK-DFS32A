<?php

namespace Component\Commande;

use Component\Fournisseur\Fournisseur;
use Component\Produit\Produit;

class Commande {
    private $date;
    private $fournisseur;
    private $produits;

    public function __construct($date, Fournisseur $fournisseur, $produits) {
        $this->date = $date;
        $this->fournisseur = $fournisseur;
        $this->produits = $produits;
    }

    // Getters and setters...
    public function getDate() {
        return $this->date;
    }

    public function getFournisseur() {
        return $this->fournisseur;
    }

    public function getProduits() {
        return $this->produits;
    }
}
