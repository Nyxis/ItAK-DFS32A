<?php

namespace Classes;

use Types\ProductType;
use Classes\Stock;

class Service
{
    public function __construct(
        readonly public string $mission,
        readonly public int    $ean,
        readonly public int    $duration,
    )
    {
    }
}