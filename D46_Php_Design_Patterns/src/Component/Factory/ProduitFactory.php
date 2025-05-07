<?php

namespace Component\Factory;

use Component\Domain\AbstractProduit;
use Component\Domain\Produit\MarchandiseProduit;
use Component\Domain\Produit\ServiceProduit;

class ProduitFactory {
    public static function createFromArray(array $data): AbstractProduit {
        $objectTypes = [
            "service" => ServiceProduit::class,
            "marchandise" => MarchandiseProduit::class
        ];

        if (!array_key_exists($data['type'], $objectTypes)) {
            throw new \InvalidArgumentException("Product type not found");
        }

        $productClass = $objectTypes[$data['type']];

        return $productClass === ServiceProduit::class
            ? new ServiceProduit(
                nom: $data['mission'],
                duree: $data['duree'],
            ) 
            : new MarchandiseProduit(
                nom: $data['designation'],
                poids: $data['poids']
            )
        ;
    }
}