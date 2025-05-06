<?php

namespace Classes;

use Classes\Product;

class Devis
{
    public function __construct(
        readonly public Supplier $supplier,
        readonly public float    $price,
        readonly public array  $product,
    )
    {
    }
}