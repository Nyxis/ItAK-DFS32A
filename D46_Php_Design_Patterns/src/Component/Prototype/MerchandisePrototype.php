<?php

namespace Component\Prototype;

use Component\Merchandise;
use Component\Product;

class MerchandisePrototype implements ProductPrototypeInterface
{
    public function clone(array $data): Product
    {
        return new Merchandise(
            $data['ean'],
            $data['designation'],
            $data['poids']
        );
    }
}
