<?php

namespace Component\Domain\Produit;

use Component\Domain\AbstractProduit;

class ServiceProduit extends AbstractProduit
{
    private int $duree;

    public function __construct(string $nom, int $duree)
    {
        parent::__construct($nom);
        $this->duree = $duree;
    }
}