<?php

namespace Component\Prototype;

use Component\Product;

interface ProductPrototypeInterface
{
    public function clone(array $data): Product;
}
