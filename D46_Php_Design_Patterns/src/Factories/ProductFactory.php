<?php

namespace Factories;

use Classes\Article;
use Classes\Product;
use Classes\Service;
use InvalidArgumentException;
use Types\ProductType;
use ValueError;

class ProductFactory
{

    public
    function createProduct(object $productBluePrint): Service | Article
    {
        $productCallBack = [
            ProductType::ARTICLE->value => [$this, 'createArticle'],
            ProductType::SERVICE->value => [$this, 'createService'],
        ];

        try {
            $productType = ProductType::from($productBluePrint->type);

            printf('resultat:');
            var_dump($productCallBack[$productBluePrint->type]($productBluePrint));
            return $productCallBack[$productBluePrint->type]($productBluePrint);

        } catch (ValueError $e) {
            throw new \InvalidArgumentException("Type de produit invalide : '{$productBluePrint->type}'");
        }
    }

    public
    function createArticle(\stdClass $productBluePrint): Article
    {

        return new Article(
            $productBluePrint->designation,
            $productBluePrint->ean,
            $productBluePrint->poids
        );
    }

    public
    function createService(\stdClass $productBluePrint): Service
    {
        return new Service(
            $productBluePrint->mission,
            $productBluePrint->ean,
            $productBluePrint->duree
        );
    }
}