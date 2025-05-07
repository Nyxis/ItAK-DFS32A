<?php

namespace Classes;
use Classes\Stock;
use Classes\Product;

class Service extends Product
{
    readonly public int $duree;
    public function __construct(array $data)
    {
        parent::__construct(
            $data['mission'],
            $data['type'],
            $data['ean'],
            new Stock()
        );
    $this->duree = $data['duree'];
    }
}