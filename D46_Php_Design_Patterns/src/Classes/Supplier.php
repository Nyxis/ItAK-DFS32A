<?php

namespace Classes;

use Classes\User;
class Supplier
{
    public function __construct(
        readonly User   $user,
        readonly string $phone,
        readonly string $address,
    )
    {
    }
}