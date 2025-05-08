<?php

namespace Component;

class Merchandise extends Product
{
    private int $poids;

    public function __construct(string $ean, string $designation, int $poids)
    {
        parent::__construct($ean, $designation);
        $this->poids = $poids;
    }

    public function getPoids(): int
    {
        return $this->poids;
    }
}
