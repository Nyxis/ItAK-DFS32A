<?php

namespace Component\Prototype;

use Component\Service;
use Component\Product;

class ServicePrototype implements ProductPrototypeInterface
{
    public function clone(array $data): Product
    {
        return new Service(
            $data['ean'],
            $data['mission'],
            $data['duree']
        );
    }
}
