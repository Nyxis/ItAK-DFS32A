<?php

namespace Component\Domain;

use Component\Collection\DevisCollection;
use Component\Enum\CommandeStatusEnum;

class Commande
{
    private CommandeStatusEnum $status;
    private Utilisateur $client;
    private DevisCollection $devis;

    public function __construct(CommandeStatusEnum $status, Utilisateur $client)
    {
        $this->status = $status;
        $this->client = $client;
        $this->devis = new DevisCollection();
    }

    /**
     * Ajouter un devis dans la commande
     * @param Devis $devis
     * @return void
     */
    public function ajouterDevis(Devis $devis): void
    {
        $this->devis->addDevis($devis);
    }

    /**
     * Retourne le montant total de la commande
     * @return float
     */
    public function getMontantTotal(): float
    {
        return array_sum(
            array_map(fn($devis) => $devis->getTotal(), $this->devis->getDevis())
        );
    }

    /**
     * Retourne le client ayant passée la commande
     * @return Utilisateur
     */
    public function getClient(): Utilisateur
    {
        return $this->client;
    }

    public function getStatus(): CommandeStatusEnum
    {
        return $this->status;
    }
}