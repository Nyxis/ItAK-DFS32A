<?php

namespace Component\Domain\Produit;

use Component\Domain\AbstractProduit;

class MarchandiseProduit extends AbstractProduit
{
    private int $poids;
    public function __construct(string $nom, int $poids)
    {
        parent::__construct($nom);
        $this->poids = $poids;
    }

    public function getPoids(): int
    {
        return $this->poids;
    }
}