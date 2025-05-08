<?php

namespace Component\User;

class OrderIssuer
{
    private int $id;
    private string $name;

    public function __construct(int $id, string $name)
    {
        $this->id = $id;
        $this->name = $name;
    }

    public function getId(): int
    {
        return $this->id;
    }

    public function getName(): string
    {
        return $this->name;
    }

    public function __toString(): string
    {
        return "OrderIssuer: {$this->name} (ID: {$this->id})";
    }
}