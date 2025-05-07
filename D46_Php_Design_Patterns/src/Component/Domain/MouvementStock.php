<?php

namespace Component\Domain;

use Component\Enum\MouvementStockEnum;

class MouvementStock
{
    private MouvementStockEnum $type;
    private Commande $commande;
    private AbstractProduit $produit;
    private int $quantite;
}