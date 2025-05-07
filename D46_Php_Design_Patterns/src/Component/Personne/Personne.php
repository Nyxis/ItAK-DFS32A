<?php

namespace Component\Personne;

class Personne {
    private $nom;
    private $identifiant;

    public function __construct($nom, $identifiant) {
        $this->nom = $nom;
        $this->identifiant = $identifiant;
    }

    // Getters and setters...
    public function getNom() {
        return $this->nom;
    }

    public function getIdentifiant() {
        return $this->identifiant;
    }
}
