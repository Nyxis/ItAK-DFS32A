<?php

namespace Classes;

use Types\ProductType;
use Classes\Stock;

class Product
{
    public function __construct(
        readonly public string      $name,
        readonly public ProductType $type,
        private Stock               $stock,
    )
    {
    }
}