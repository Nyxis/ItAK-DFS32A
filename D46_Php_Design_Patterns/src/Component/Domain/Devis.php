<?php

namespace Component\Domain;

class Devis
{
    private float $prix;
    private Fournisseur $fournisseur;
    private AbstractProduit $produit;

    public function __construct(float $prix, Fournisseur $fournisseur, AbstractProduit $produit)
    {
        $this->prix = $prix;
        $this->fournisseur = $fournisseur;
        $this->produit = $produit;
    }

    public function getPrix(): float
    {
        return $this->prix;
    }

    public function getFournisseur(): Fournisseur
    {
        return $this->fournisseur;
    }

    public function getProduit(): AbstractProduit
    {
        return $this->produit;
    }
}