<?php

namespace Component\Commande;

class Reception {
    private $commande;
    private $dateReception;

    public function __construct(Commande $commande, $dateReception) {
        $this->commande = $commande;
        $this->dateReception = $dateReception;
    }

    public function getCommande() {
        return $this->commande;
    }

    public function getDateReception() {
        return $this->dateReception;
    }
}
