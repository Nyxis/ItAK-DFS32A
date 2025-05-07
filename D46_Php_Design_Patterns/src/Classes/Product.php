<?php

namespace Classes;
use Classes\Stock;

class Product
{
    public function __construct(
        readonly public string $name,
        readonly public string $type,
        readonly public string $ean,
        private Stock $stock
    )
    {
    }
}
