<?php

namespace Component\Factory;

use Component\Domain\Utilisateur;

class ClientFactory {
    public static function createFromArray(array $data): Utilisateur {
        return new Utilisateur(
            nom: $data['nom'], 
            prenom: $data['prenom']
        );
    }
}