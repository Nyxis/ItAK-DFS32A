<?php

namespace Classes;

use Product;

class Devis
{
    public function __construct(
        readonly public Supplier $dealer,
        readonly public float    $price,
        readonly public Product  $product,
    )
    {
    }
}