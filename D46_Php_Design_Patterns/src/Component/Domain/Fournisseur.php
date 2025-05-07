<?php

namespace Component\Domain;

class Fournisseur
{
    private string $nom;

    public function __construct(string $nom)
    {
        $this->nom = $nom;
    }
}