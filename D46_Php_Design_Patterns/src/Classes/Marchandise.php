<?php

namespace Classes;
use Classes\Product;

class Marchandise extends Product
{
    readonly public int $poids;
    public function __construct(array $data)
    {
            parent::__construct(
            $data['designation'],
            $data['type'],
            $data['ean'],
            new Stock()
        );
    $this->poids = $data['poids'];
    }
}