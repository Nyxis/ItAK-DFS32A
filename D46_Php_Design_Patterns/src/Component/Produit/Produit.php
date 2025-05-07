<?php

namespace App\Component\Produit;

class Produit {
    private string $nom;
    private string $type;
    private float $prix;

    public function __construct(string $nom, string $type, float $prix) {
        $this->nom = $nom;
        $this->type = $type;
        $this->prix = $prix;
    }

    public function getNom(): string {
        return $this->nom;
    }

    public function setNom(string $nom): void {
        $this->nom = $nom;
    }

    public function getType(): string {
        return $this->type;
    }

    public function getPrix(): float {
        return $this->prix;
    }

    public function setPrix(float $prix): void {
        $this->prix = $prix;
    }
}
