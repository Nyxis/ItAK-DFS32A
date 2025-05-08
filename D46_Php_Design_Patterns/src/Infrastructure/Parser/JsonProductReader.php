<?php

namespace Infrastructure\Parser;

use InvalidArgumentException;

class JsonProductReader implements ProductFileReaderInterface
{
    private string $filePath;

    public function __construct(string $filePath = '')
    {
        $this->filePath = $filePath;
    }

    public function supports(string $filePath): bool
    {
        return is_file($filePath) && str_ends_with(strtolower($filePath), '.json');
    }

    public function setFile(string $filePath): void
    {
        $this->filePath = $filePath;
    }

    public function read(): array
    {
        if (!is_file($this->filePath)) {
            throw new InvalidArgumentException("Fichier JSON introuvable : {$this->filePath}");
        }

        $content = file_get_contents($this->filePath);
        $data = json_decode($content, true);

        if (!is_array($data)) {
            throw new InvalidArgumentException("Fichier JSON invalide.");
        }

        return $data;
    }
}
