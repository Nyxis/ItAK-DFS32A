<?php

namespace Component;

class Order
{
    private Product $product;
    private Supplier $supplier;
    private int $quantity;
    private Actor $orderedBy;
    private Actor $deliveredTo;

    public function __construct(
        Product $product,
        Supplier $supplier,
        int $quantity,
        Actor $orderedBy,
        Actor $deliveredTo
    ) {
        $this->product = $product;
        $this->supplier = $supplier;
        $this->quantity = $quantity;
        $this->orderedBy = $orderedBy;
        $this->deliveredTo = $deliveredTo;
    }

    public function getProduct(): Product
    {
        return $this->product;
    }

    public function getSupplier(): Supplier
    {
        return $this->supplier;
    }

    public function getQuantity(): int
    {
        return $this->quantity;
    }

    public function getOrderedBy(): Actor
    {
        return $this->orderedBy;
    }

    public function getDeliveredTo(): Actor
    {
        return $this->deliveredTo;
    }
}
