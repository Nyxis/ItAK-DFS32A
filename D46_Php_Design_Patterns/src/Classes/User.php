<?php

namespace Classes;
use Types\Role;
class User
{
    public function __construct(
        readonly public string $name,
        readonly public Role $position,
    )
    {
    }
}