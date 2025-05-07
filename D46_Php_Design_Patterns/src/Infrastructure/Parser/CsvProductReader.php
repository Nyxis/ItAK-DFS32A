<?php

namespace Infrastructure\Parser;

use InvalidArgumentException;

class CsvProductReader implements ProductFileReaderInterface
{
    
    private string $filePath;
    private string $delimiter;


    public function setFile(string $filePath): void
{
    $this->filePath = $filePath;
}
    public function __construct(string $filePath = '', string $delimiter = ';')
    {
        $this->filePath = $filePath;
        $this->delimiter = $delimiter;
    }

    public function supports(string $filePath): bool
    {
        return is_file($filePath) && str_ends_with(strtolower($filePath), '.csv');
    }

    public function read(): array
    {
        if (!is_file($this->filePath)) {
            throw new InvalidArgumentException("Fichier CSV introuvable : {$this->filePath}");
        }
    
        $handle = fopen($this->filePath, 'r');
        if (!$handle) {
            throw new InvalidArgumentException("Impossible d'ouvrir le fichier CSV.");
        }
    
        $rows = [];
        $headers = null;
    
        while (($line = fgetcsv($handle, 1000, $this->delimiter, '"', '\\')) !== false) {
            if (!$headers) {
                $headers = $line;
                continue;
            }
        
            if (count($headers) !== count($line)) {
                // 
                continue;
            }
        
            $row = array_combine($headers, $line);
            $row = array_map(fn($val) => is_numeric($val) ? +$val : $val, $row);
            $rows[] = $row;
        }
        
    
        fclose($handle);
        return $rows;
    }
    
}
