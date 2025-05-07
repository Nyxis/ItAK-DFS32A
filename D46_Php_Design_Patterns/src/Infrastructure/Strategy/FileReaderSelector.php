<?php

namespace Infrastructure\Strategy;

use Infrastructure\Parser\ProductFileReaderInterface;
use InvalidArgumentException;

class FileReaderSelector implements ProductFileReaderInterface
{
    /** @var ProductFileReaderInterface[] */
    private array $strategies = [];

    private ?string $filePath = null;

    public function __construct(ProductFileReaderInterface ...$strategies)
    {
        $this->strategies = $strategies;
    }

    public function supports(string $filePath): bool
    {
        foreach ($this->strategies as $strategy) {
            if ($strategy->supports($filePath)) {
                return true;
            }
        }
        return false;
    }

    public function setFile(string $filePath): void
    {
        $this->filePath = $filePath;
    }

    public function read(): array
    {
        if (!$this->filePath) {
            throw new InvalidArgumentException("Aucun fichier défini pour la lecture.");
        }
    
        foreach ($this->strategies as $strategy) {
            if ($strategy->supports($this->filePath)) {
                $strategy->setFile($this->filePath); // ✅ on configure l’instance
                return $strategy->read();            // ✅ on utilise l’instance existante
            }
        }
    
        throw new InvalidArgumentException("Aucune stratégie compatible avec le fichier : {$this->filePath}");
    }
    
    
}
