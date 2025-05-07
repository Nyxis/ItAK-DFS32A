<?php

namespace Classes;

use Classes\User;
use Types\OrderStatus;

class Order
{

    private array $statusUpdateTable;
    private OrderStatus $status = OrderStatus::RECEIVED;

    public function __construct(
        readonly User $operator,
        readonly User $addressedTo,
        private array $content,
    )
    {
        $this->statusUpdateTable = [
            OrderStatus::RECEIVED->name => function () {
                return OrderStatus::IN_PROCESS;
            },
            OrderStatus::IN_PROCESS->name => function () {
                return OrderStatus::IN_TRANSFERT;
            },
            OrderStatus::IN_TRANSFERT->name => function () {
                return OrderStatus::DELIVERED;
            },
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
        $this->status = $this->statusUpdateTable[$this->status->name]();
    }
}