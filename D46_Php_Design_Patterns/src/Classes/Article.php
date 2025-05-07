<?php

namespace Classes;

use Types\ProductType;
use Classes\Stock;

class Article
{
    public function __construct(
        readonly public string $name,
        readonly public int    $ean,
        readonly public int    $weight,
    )
    {
    }
}