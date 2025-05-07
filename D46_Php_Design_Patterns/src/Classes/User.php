<?php

namespace Classes;

use Types\HierarchyPos;
class User
{
    public function __construct(
        readonly public string       $name,
        readonly public HierarchyPos $position,
    )
    {
    }
}