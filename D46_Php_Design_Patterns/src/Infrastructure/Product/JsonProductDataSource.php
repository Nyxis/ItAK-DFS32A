<?php

namespace Infrastructure\Product;

class JsonProductDataSource
{
    public function parse(string $filePath): array
    {
        if (!is_file($filePath)) {
            throw new \RuntimeException("File not found: $filePath");
        }

        $json = file_get_contents($filePath);
        $data = json_decode($json, true, 512, JSON_THROW_ON_ERROR);

        if (!is_array($data)) {
            throw new \UnexpectedValueException("Invalid JSON structure");
        }

        return $data;
    }
}
