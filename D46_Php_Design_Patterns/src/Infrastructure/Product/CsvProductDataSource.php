<?php

namespace Infrastructure\Product;

class CsvProductDataSource
{
    public function parse(string $filePath): array
    {
        if (!is_file($filePath)) {
            throw new \RuntimeException("File not found: $filePath");
        }

        $rows = [];
        if (($handle = fopen($filePath, 'r')) !== false) {
            $headers = fgetcsv($handle);
            if (!$headers) {
                throw new \UnexpectedValueException("CSV has no headers");
            }

            while (($data = fgetcsv($handle)) !== false) {
                $row = array_combine($headers, $data);
                if ($row === false) {
                    throw new \UnexpectedValueException("CSV row malformed");
                }
                $rows[] = $row;
            }
            fclose($handle);
        }

        return $rows;
    }
}
