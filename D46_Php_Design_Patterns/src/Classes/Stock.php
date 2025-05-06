<?php

namespace Classes;
class Stock
{
    private int $quantity = 0 {
        set {
            $this->quantity;
        }
    }

    function isAvailable(): bool
    {
        return $this->quantity > 0;
    }
}