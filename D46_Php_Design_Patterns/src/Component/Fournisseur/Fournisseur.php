<?php

namespace Component\Fournisseur;

class Fournisseur {
    private $nom;
    private $adresse;

    public function __construct($nom, $adresse) {
        $this->nom = $nom;
        $this->adresse = $adresse;
    }

    // Getters and setters...
    public function getNom() {
        return $this->nom;
    }

    public function getAdresse() {
        return $this->adresse;
    }
}
