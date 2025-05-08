<?php

namespace Component\Order;

use Component\Product\ProductPrototype;
use Component\Supplier\Supplier;
use Component\User\OrderIssuer;
use Component\User\Beneficiary;

class Order
{
    private int $id;
    private Supplier $supplier;
    private OrderIssuer $issuer;
    private Beneficiary $beneficiary;
    private array $items = []; // Liste des produits commandés avec quantités

    public function __construct(int $id, Supplier $supplier, OrderIssuer $issuer, Beneficiary $beneficiary)
    {
        $this->id = $id;
        $this->supplier = $supplier;
        $this->issuer = $issuer;
        $this->beneficiary = $beneficiary;
    }

    public function addItem(ProductPrototype $product, int $quantity): void
    {
        $this->items[] = ['product' => $product, 'quantity' => $quantity];
    }

    public function getId(): int
    {
        return $this->id;
    }

    public function getSupplier(): Supplier
    {
        return $this->supplier;
    }

    public function getIssuer(): OrderIssuer
    {
        return $this->issuer;
    }

    public function getBeneficiary(): Beneficiary
    {
        return $this->beneficiary;
    }

    public function getItems(): array
    {
        return $this->items;
    }

    public function __toString(): string
    {
        return "Order: ID {$this->id}, Supplier: {$this->supplier->getName()}";
    }
}