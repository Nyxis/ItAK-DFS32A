<?php

namespace Classes;

use Types\OrderStatus;
use Classes\User;
use Product;


class Order
{
    private array $statusUpdateTable;
    private OrderStatus $status = OrderStatus::VALIDATE;

    public function __construct(
        readonly User $operator,
        readonly User $supplier,
        private array $content,
    )
    {
        $this->statusUpdateTable = [
            OrderStatus::VALIDATE->name => function () {
                return OrderStatus::IN_PROCESS;
            },
            OrderStatus::IN_PROCESS->name => function () {
                return OrderStatus::IN_TRANSFERT;
            },
            OrderStatus::IN_TRANSFERT->name => function () {
                return OrderStatus::RECEIVED;
            }
        ];
    }

    function addToOrder(array $toAdd): void
    {
        $this->content = array_merge($this->content, $toAdd);
    }

    function removeFromOrder(Product $toRemove): void
    {
        $this->content = array_values(
            array_filter(
                $this->content,
                fn($item) => $item->name !== $toRemove->name
            ));
    }

    function updateStatus(): OrderStatus
    {
        return $this->status = $this->statusUpdateTable[$this->status->name]();
    }
}