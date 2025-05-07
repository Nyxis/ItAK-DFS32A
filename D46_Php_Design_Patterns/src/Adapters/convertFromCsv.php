<?php

namespace Adapters;

class convertFromCsv
{
    public function convert(string $url): array
    {
        $productObjectList = [];

        try {
            $csvFile = fopen($url, 'r');
        } catch (\Exception $e) {
            throw new \Exception("Impossible d'ouvrir le fichier à l'URL suivant:" . $url . "\n");
        }
        $i = 0;
        while (($csvLine = fgetcsv($csvFile, 1000, escape: "\\")) !== false) {
            $productObject = new \stdClass();
            $productObject->ean = $csvLine[0];
            $productObject->type = $csvLine[1];

            if ($i > 0 && $csvLine[1] == 'marchandise') {

                $productObject->designation = $csvLine[2];
                $productObject->poids = $csvLine[3];

            } elseif ($i > 0 && $csvLine[1] == 'service') {

                $productObject->mission = $csvLine[4];
                $productObject->duree = $csvLine[5];

            } else {
                throw new \InvalidArgumentException("Aucun type de produit ne correspond à" . $csvFile[1]);
            }

            $productObjectList[] = $productObject;
            $i++;
        }

        fclose($csvFile);

        return $productObjectList;
    }
}