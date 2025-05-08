<?php

namespace Component;

abstract class Product
{
    protected string $ean;
    protected string $designation;

    public function __construct(string $ean, string $designation)
    {
        $this->ean = $ean;
        $this->designation = $designation;
    }

    public function getEan(): string
    {
        return $this->ean;
    }

    public function getDesignation(): string
    {
        return $this->designation;
    }
}
