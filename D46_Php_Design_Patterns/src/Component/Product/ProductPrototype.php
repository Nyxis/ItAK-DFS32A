<?php

namespace Component\Product;

class ProductPrototype
{
    protected int $id;
    protected string $name;
    public float $price;
    protected string $type;

    public function __construct(string $type)
    {
        $this->type = $type;
    }

    public function setAttributes(array $data): void
    {
        foreach ($data as $key => $value) {
            if (property_exists($this, $key)) {
                $this->$key = $value;
            }
        }
    }

    public function __toString(): string
    {
        return "[{$this->type}] {$this->name} (ID: {$this->id}) - {$this->price}€";
    }

    public function getId(): int
    {
        return $this->id;
    }
}
