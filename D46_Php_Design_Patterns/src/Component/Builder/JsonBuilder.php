<?php
namespace Component\Builder;
use Component\Factory\ProduitFactory;
use Component\Builder\BuilderInterface;

class JsonBuilder implements BuilderInterface
{
    public function parse(string $filePath): array {
        if (!file_exists($filePath)) {
            throw new \FileNotFoundException();
        }

        $file = file_get_contents($filePath);
        return json_decode($file, true);
    }
}