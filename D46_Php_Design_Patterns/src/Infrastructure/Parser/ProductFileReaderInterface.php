<?php

namespace Infrastructure\Parser;

interface ProductFileReaderInterface
{
    public function read(): array;
    public function supports(string $filePath): bool;
    public function setFile(string $filePath): void;
}
