<?php

namespace Utils;

class Parsers
{
    public function parseJson(string $jsonString): array
    {
        var_dump(json_decode($jsonString));
        return json_decode($jsonString);
    }
}